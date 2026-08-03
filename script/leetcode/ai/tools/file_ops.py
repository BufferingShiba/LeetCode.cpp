#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""文件 CRUD 工具：`create_or_update_file` / `retrieve_file_content` / `append_test_case`。

`create_or_update_file` 在首次生成时多做三道守卫：必须三文件齐全、必须先
拿到 metadata 并覆盖全部官方 examples、额外 TEST_P 自动补上 `SelfAuthored` 前缀——
这些规则 JSON Schema 表达不了，只能在执行器层兜底。
"""

import re
from pathlib import Path
from typing import Any, Dict, List, Optional

from script.leetcode.ai.tools._utils import class_name_from_slug
from script.leetcode.config import ProjectPaths

_REQUIRED_CATEGORIES = ("header", "source", "test")


def _category_paths(slug: str) -> Dict[str, Path]:
    return {
        "header": Path(f"{ProjectPaths.INCLUDE_PROBLEMS}/{slug}.h"),
        "source": Path(f"{ProjectPaths.SRC_PROBLEMS}/{slug}.cpp"),
        "test": Path(f"{ProjectPaths.TEST_PROBLEMS}/{slug}.cpp"),
    }


class FileOps:
    def __init__(self, repository: Any, metadata_cache: Dict[int, Dict[str, Any]]):
        self._repo = repository
        self._cache = metadata_cache
        # 首次生成时允许模型分多次提交，但只在三份文件齐全且校验通过后落盘。
        self._initial_staging: Dict[int, Dict[str, str]] = {}

    def create_or_update(
        self,
        problem_id: int,
        files: list,
        overwrite_existing: bool = False,
    ) -> Dict[str, Any]:
        try:
            problem_info = self._repo.get_by_id(problem_id)
            paths = _category_paths(problem_info.slug)

            any_existing = any(p.exists() for p in paths.values())
            if not any_existing:
                staged = dict(self._initial_staging.get(problem_id, {}))
                seen_categories = set()
                for entry in files:
                    category = entry.get("file_category")
                    if category not in paths:
                        return {
                            "is_successful": False,
                            "error_message": f"未知文件类型: {category}",
                        }
                    if category in seen_categories:
                        return {
                            "is_successful": False,
                            "error_message": f"本次提交文件类型重复: {category}",
                        }
                    seen_categories.add(category)
                    staged[category] = entry.get("content", "")

                missing = [c for c in _REQUIRED_CATEGORIES if c not in staged]
                if missing:
                    self._initial_staging[problem_id] = staged
                    return _staged_initial(staged, missing)

                files = [
                    {"file_category": category, "content": staged[category]}
                    for category in _REQUIRED_CATEGORIES
                ]
                extra_check = self._check_extra_tests(problem_id, files)
                if extra_check is not None:
                    self._initial_staging[problem_id] = staged
                    return extra_check
                self._initial_staging.pop(problem_id, None)
            else:
                # 外部已经创建了文件，暂存内容不再代表当前磁盘状态。
                self._initial_staging.pop(problem_id, None)

            errors: List[str] = []
            pending: List[tuple[str, Path, str]] = []
            seen_categories = set()

            for entry in files:
                category = entry["file_category"]
                content = entry["content"]
                file_path = paths.get(category)
                if file_path is None:
                    errors.append(f"未知文件类型: {category}")
                    continue
                if category in seen_categories:
                    errors.append(f"文件类型重复提交: {category}")
                    continue
                seen_categories.add(category)
                if file_path.exists() and not overwrite_existing:
                    errors.append(f"文件已存在: {file_path}")
                    continue

                if category == "test" and file_path.exists() and overwrite_existing:
                    guard_error = _test_replacement_guard(file_path, content)
                    if guard_error is not None:
                        errors.append(guard_error)
                        continue

                pending.append((category, file_path, content))

            if errors:
                # 先完成所有输入校验，再写文件，避免 valid 文件已经落盘而
                # 后续 entry 失败，留下一个看似存在但不完整的题目。
                return {
                    "is_successful": False,
                    "error_message": "; ".join(errors),
                    "generated_files": [],
                }

            generated: List[Dict[str, str]] = []
            for category, file_path, content in pending:
                file_path.parent.mkdir(parents=True, exist_ok=True)
                file_path.write_text(content, encoding="utf-8")
                generated.append({"file_category": category, "file_path": str(file_path)})

            suffix = "（覆盖旧文件）" if overwrite_existing else ""
            return {
                "is_successful": True,
                "status_message": f"已生成 {len(generated)} 个文件{suffix}",
                "generated_files": generated,
            }
        except Exception as e:
            return {"is_successful": False, "error_message": str(e)}

    def retrieve(self, problem_id: int, file_category: str) -> Dict[str, Any]:
        try:
            problem_info = self._repo.get_by_id(problem_id)
            file_path = _category_paths(problem_info.slug).get(file_category)
            if file_path is None:
                return {"is_successful": False, "error_message": f"未知文件类型: {file_category}"}
            if not file_path.exists():
                return {"is_successful": False, "error_message": f"文件不存在: {file_path}"}
            return {
                "is_successful": True,
                "file_category": file_category,
                "file_path": str(file_path),
                "content": file_path.read_text(encoding="utf-8"),
            }
        except Exception as e:
            return {"is_successful": False, "error_message": str(e)}

    def append_test_case(
        self, problem_id: int, test_name: str, test_code: str
    ) -> Dict[str, Any]:
        try:
            problem_info = self._repo.get_by_id(problem_id)
            test_path = _category_paths(problem_info.slug)["test"]
            class_base = class_name_from_slug(problem_info.slug)

            if not test_path.exists():
                return {"is_successful": False, "error_message": f"测试文件不存在: {test_path}"}

            content = test_path.read_text(encoding="utf-8")
            match = re.search(r"INSTANTIATE_TEST_SUITE_P\(", content)
            if not match:
                return {
                    "is_successful": False,
                    "error_message": "无法找到 INSTANTIATE_TEST_SUITE_P 标记",
                }

            indented = "\n".join(
                "  " + line if line.strip() else line
                for line in test_code.strip().split("\n")
            )
            stub = (
                f"\n// LeetCode 失败用例: {test_name}\n"
                f"TEST_P({class_base}Test, {test_name}) {{\n"
                f"{indented}\n"
                f"}}\n"
            )
            insert_pos = match.start()
            test_path.write_text(content[:insert_pos] + stub + content[insert_pos:], encoding="utf-8")

            return {
                "is_successful": True,
                "message": f"测试用例 '{test_name}' 已添加到 {test_path}",
                "test_file": str(test_path),
            }
        except Exception as e:
            return {"is_successful": False, "error_message": str(e)}

    def _check_extra_tests(self, problem_id: int, files: list) -> Optional[Dict[str, Any]]:
        """首次生成时校验官方 examples 数量并拦截未命名的自编 TEST_P。

        必须先 fetch metadata，且 test 文件至少覆盖全部官方 examples；超出数量的
        TEST_P 必须 `SelfAuthored` 前缀。这条约束用于在 LeetCode 返回 WA 时提醒模型
        "先核对 SelfAuthored 的 expected 是否算错"；如果模型漏写前缀，工具只自动修正
        测试名，不会修改测试内容。
        """
        cached = self._cache.get(problem_id)
        if not cached:
            return {
                "is_successful": False,
                "error_type": "metadata_required_before_initial_files",
                "retryable": True,
                "error_message": (
                    "首次生成文件前必须先调用 fetch_problem_metadata，确保官方 examples "
                    "已进入缓存；拿到 metadata 后再重新提交三份文件。"
                ),
                "next_steps": [
                    "调用 fetch_problem_metadata",
                    "重新调用 create_or_update_file 提交 header、source、test",
                ],
            }
        examples = cached.get("examples") or []
        expected_count = len(examples)
        if expected_count == 0:
            return None

        test_file = next((f for f in files if f.get("file_category") == "test"), None)
        if not test_file:
            return None

        test_content = test_file.get("content") or ""
        names = re.findall(r"\bTEST_P\s*\(\s*[^,]+,\s*([A-Za-z_][A-Za-z0-9_]*)", test_content)
        if len(names) < expected_count:
            return {
                "is_successful": False,
                "error_type": "missing_official_test_cases",
                "retryable": True,
                "error_message": (
                    f"test 文件只找到 {len(names)} 个 TEST_P，但题目有 {expected_count} 个官方 "
                    "examples。请保留/补齐全部官方 Example 测试后重新提交。"
                ),
                "next_steps": [
                    "为每个官方 example 添加一个 TEST_P",
                    "重新调用 create_or_update_file 提交完整 test 文件",
                ],
            }

        if len(names) == expected_count:
            return None

        bad = [n for n in names[expected_count:] if not n.startswith("SelfAuthored")]
        if not bad:
            return None

        # 测试名称本身不影响算法和 expected。模型在批量运行中经常忘记给
        # 自编 TEST_P 加前缀，若仅返回错误就会额外浪费一轮 API。安全地只
        # 改写这些宏的第二个参数，保留测试主体、断言和官方样例不变。
        renamed_content = test_content
        for name in bad:
            renamed_content = re.sub(
                rf"(\bTEST_P\s*\(\s*[^,]+,\s*){re.escape(name)}\b",
                rf"\1SelfAuthored{name}",
                renamed_content,
            )
        test_file["content"] = renamed_content
        return None


def _test_replacement_guard(file_path: Path, replacement: str) -> Optional[str]:
    """Reject a partial test snippet sent as a whole-file overwrite.

    ``create_or_update_file`` is intentionally a whole-file operation. Models
    sometimes try to fix one expected value by sending only a ``TEST_P`` block,
    which silently destroys the fixture and strategy registration. If the
    existing ordinary test has those structural markers, require the
    replacement to retain them; small additions belong in ``append_test_case``.
    Design tests without parameterized registration are left untouched.
    """
    try:
        existing = file_path.read_text(encoding="utf-8")
    except OSError as error:
        return f"无法读取现有测试文件以保护覆盖操作: {error}"

    required_markers = []
    for marker in ("TEST_P(", "INSTANTIATE_TEST_SUITE_P("):
        if marker in existing:
            required_markers.append(marker)
    missing = [marker for marker in required_markers if marker not in replacement]
    if not missing:
        return None
    marker_text = "、".join(missing)
    return (
        f"拒绝用不完整内容覆盖 {file_path}：缺少 {marker_text}。"
        "请提交完整 test 文件；若只需添加一个测试，请使用 append_test_case。"
    )


def _staged_initial(staged: Dict[str, str], missing: list) -> Dict[str, Any]:
    staged_categories = [
        category for category in _REQUIRED_CATEGORIES if category in staged
    ]
    return {
        "is_successful": False,
        "error_type": "initial_files_staged",
        "retryable": True,
        "error_message": (
            f"已暂存 {', '.join(staged_categories) or '0 个文件'}（尚未写入项目目录），"
            f"当前还缺少: {', '.join(missing)}。下一次 create_or_update_file 只需提交缺失类别；"
            "三份齐全后系统会一次性完成首次写入。"
        ),
        "staged_categories": staged_categories,
        "missing_categories": missing,
        "next_steps": [
            "提交缺失的文件类别，不要只重复提交已经暂存的类别",
            "三份齐全后系统会检查官方 examples，再自动 compile_and_test",
        ],
    }

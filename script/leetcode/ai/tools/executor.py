#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""工具派发器。

把模型发来的工具调用映射到四类具体模块：
  - metadata: fetch_problem_metadata
  - file_ops: create_or_update_file / retrieve_file_content / append_test_case
  - build_runner: compile_project / compile_and_test / execute_test_suite
  - structure_ref: fetch_structure_definition

结果统一走 `result_utils.normalize` 归一化。executor 自身只做派发，不藏逻辑。
"""

import traceback
from typing import Any, Callable, Dict

from script.leetcode.ai import result_utils
from script.leetcode.ai.tools.build_runner import BuildRunner
from script.leetcode.ai.tools.file_ops import FileOps
from script.leetcode.ai.tools.metadata import MetadataFetcher
from script.leetcode.ai.tools.structure_ref import fetch_structure_definition
from script.leetcode.api import ProblemRepository


class ToolExecutor:
    def __init__(self, repository: ProblemRepository):
        self.repository = repository
        # MetadataFetcher 写 + FileOps 读的共享缓存；flash 盲目重 fetch 时由此返回
        # cached=True 的精简响应，避免浪费轮次。
        self._metadata_cache: Dict[int, Dict[str, Any]] = {}

        self._metadata = MetadataFetcher(repository, self._metadata_cache)
        self._files = FileOps(repository, self._metadata_cache)
        self._build = BuildRunner()

    def execute(self, name: str, arguments: Dict[str, Any]) -> Dict[str, Any]:
        executors: Dict[str, Callable] = {
            "fetch_problem_metadata": self._metadata.fetch,
            "create_or_update_file": self._files.create_or_update,
            "retrieve_file_content": self._files.retrieve,
            "append_test_case": self._files.append_test_case,
            "compile_and_test": self._build.compile_and_test,
            "compile_project": self._build.compile_project,
            "execute_test_suite": self._build.execute_test_suite,
            "fetch_structure_definition": fetch_structure_definition,
        }

        executor = executors.get(name)
        if not executor:
            return result_utils.normalize(
                {
                    "is_successful": False,
                    "error_message": f"未知工具函数: {name}",
                    "error_type": "tool_not_found",
                },
                tool_name=name,
            )

        try:
            normalized_arguments = dict(arguments)
            if name == "create_or_update_file":
                normalized_arguments = _normalize_file_update_arguments(
                    normalized_arguments
                )
            if "problem_id" in normalized_arguments and normalized_arguments["problem_id"] is not None:
                normalized_arguments["problem_id"] = int(normalized_arguments["problem_id"])
            raw = executor(**normalized_arguments)
            return result_utils.normalize(raw, tool_name=name)
        except Exception as e:
            return result_utils.normalize(
                {
                    "is_successful": False,
                    "error_message": f"{str(e)}\n{traceback.format_exc()}",
                    "error_type": "execution_exception",
                },
                tool_name=name,
            )


def _normalize_file_update_arguments(arguments: Dict[str, Any]) -> Dict[str, Any]:
    """兼容模型偶尔生成的单文件简写，统一转成 ``files`` 数组。

    这里只修工具参数形状，不猜测或修改任何 C++ 内容。这样一个常见的
    ``file_category + content`` 误用不会额外消耗一轮 API，也不会绕过
    FileOps 的首次三文件和官方 examples 校验。部分模型会把 schema 中的
    ``content`` 误写成 ``file_content``；仅在字段缺失时做同义字段归一化，
    避免完整测试内容被静默变成空字符串。
    """
    normalized = dict(arguments)
    # Some tool-call emitters wrap the JSON payload in an extra `arguments`
    # object even though the dispatcher already receives the arguments map.
    # Unwrap only a mapping so malformed scalar values still reach the normal
    # validation path instead of being silently discarded.
    wrapped = normalized.get("arguments")
    if isinstance(wrapped, dict):
        normalized = dict(wrapped, **{
            key: value
            for key, value in normalized.items()
            if key != "arguments"
        })
    if normalized.get("files") is not None:
        # 模型有时同时保留冗余的顶层 file_category/content；真正的文件
        # 条目已经在 files 中，丢弃冗余字段即可，避免传入业务函数时报错。
        normalized_files = []
        for entry in normalized["files"]:
            if not isinstance(entry, dict):
                normalized_files.append(entry)
                continue
            normalized_entry = dict(entry)
            if "content" not in normalized_entry and "file_content" in normalized_entry:
                normalized_entry["content"] = normalized_entry.pop("file_content")
            normalized_files.append(normalized_entry)
        normalized["files"] = normalized_files
        normalized.pop("file_category", None)
        normalized.pop("content", None)
        normalized.pop("file_content", None)
        return normalized

    file_category = normalized.get("file_category")
    if "content" not in normalized and "file_content" in normalized:
        normalized["content"] = normalized.pop("file_content")
    else:
        normalized.pop("file_content", None)
    if file_category is None or "content" not in normalized:
        return normalized

    normalized["files"] = [{
        "file_category": file_category,
        "content": normalized.get("content", ""),
    }]
    normalized.pop("file_category", None)
    normalized.pop("content", None)
    return normalized

#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
工具结果规范化与辅助函数。

统一 solver 与 executor 两侧对"工具调用结果"的格式化、截断、签名提取等逻辑，
消除此前 `_compact_tool_result` 与 `_normalize_result` 大量重复的问题。
"""

from typing import Any, Dict, List, Optional

from script.leetcode.config import AIConfig


def is_success(result: Dict[str, Any]) -> bool:
    """`status=='success'` 优先；缺字段时退回 `is_successful`。"""
    if "status" in result:
        return result.get("status") == "success"
    return bool(result.get("is_successful"))


def error_signature(tool_name: str, result: Dict[str, Any]) -> str:
    """提取"工具名|错误类|首行摘要"作为签名，供守卫检测连续同型失败。"""
    error_type = str(result.get("error_type") or "unknown")
    message = str(
        result.get("message") or result.get("error_message") or "unknown"
    )
    first_line = message.strip().splitlines()[0] if message.strip() else "unknown"
    return f"{tool_name}|{error_type}|{first_line[:160]}"


def normalize(raw: Dict[str, Any], tool_name: str) -> Dict[str, Any]:
    """executor 返回原始 dict → solver 消费的统一 schema。

    - 对齐 `status` / `is_successful` 双字段以兼容老调用点
    - 生成 `message` / `error_message` / `status_message` 三件套（哪个存在都一致）
    - 把长 `output` 收成 `output_excerpt`（尾部 OUTPUT_EXCERPT_CHARS 字节）
    - `artifacts` 把 `generated_files` / `file_path` 都统一成 `{type,category,path}` 列表
    - `retryable` 由 `_infer_retryable` 推断（超时 / 网络 / 编译测试类 → True）
    """
    result = dict(raw or {})
    success = bool(result.get("is_successful", False))
    status = "success" if success else "error"

    message = (
        result.get("status_message")
        or result.get("message")
        or (result.get("error_message") if not success else "成功")
    )

    error_type = result.get("error_type") if not success else None
    if not success and not error_type:
        error_type = "unknown"

    retryable = _infer_retryable(result, tool_name)
    artifacts = _collect_artifacts(result)
    output_excerpt = _truncate_output_field(result)

    result["status"] = status
    result["message"] = message
    result["error_type"] = error_type
    result["retryable"] = retryable
    result["artifacts"] = artifacts
    result["tool_name"] = tool_name
    result["is_successful"] = success

    if output_excerpt:
        result["output_excerpt"] = output_excerpt
        result.pop("output", None)

    if success:
        result.setdefault("status_message", message)
    else:
        result.setdefault("error_message", message)

    return result


def compact(raw: Dict[str, Any]) -> Dict[str, Any]:
    """把 normalize 之后的结果再压一次，作为 tool-message content 回传模型。

    主要是把 `output_excerpt` 截到 OUTPUT_TAIL_CHARS，避免长日志挤占 context。
    """
    payload: Dict[str, Any] = dict(raw or {})
    success = bool(payload.get("is_successful", False))
    payload["is_successful"] = success
    payload["status"] = "success" if success else "error"

    message = (
        payload.get("status_message")
        or payload.get("message")
        or payload.get("error_message")
        or ("成功" if success else "")
    )
    payload["message"] = message
    if success:
        payload.setdefault("status_message", message)
    else:
        payload.setdefault("error_message", message)

    excerpt = payload.get("output_excerpt") or payload.get("output")
    if excerpt:
        text = str(excerpt)
        if len(text) > AIConfig.OUTPUT_TAIL_CHARS:
            text = text[-AIConfig.OUTPUT_TAIL_CHARS:]
        payload["output_excerpt"] = text
        payload.pop("output", None)

    tool_name = str(payload.get("tool_name") or "")
    if tool_name == "fetch_problem_metadata" and success:
        payload = _compact_metadata(payload)
    elif tool_name == "retrieve_file_content" and payload.get("content"):
        # 文件内容是修复编译错误的有效上下文，但不应把一次误读的大文件
        # 永久复制到每一轮请求中。需要时模型仍可再次 retrieve。
        payload["content"] = _clip_text(str(payload["content"]), 16_000)

    return payload


def _compact_metadata(payload: Dict[str, Any]) -> Dict[str, Any]:
    """保留解题所需元数据，去掉重复的 Two Sum/LRU 完整工程源码。

    system prompt 已经给出最小架构模板；metadata 原先又携带两套完整示例
    文件，单题每一轮都会重复计入 prompt，尤其容易把 Hard 题推过预算。
    """
    keep_fields = {
        "is_successful",
        "status",
        "message",
        "status_message",
        "problem_id",
        "title",
        "slug",
        "difficulty",
        "url",
        "cached",
        "hint",
        "examples",
        "description",
        "function_signature",
        "code_template",
        "is_design",
        "solution_class_name",
        "solution_class_base",
        "test_class_name",
        "namespace",
        "framework_apis",
        "tool_name",
    }
    compacted = {key: value for key, value in payload.items() if key in keep_fields}

    if compacted.get("description"):
        compacted["description"] = _clip_text(str(compacted["description"]), 9_000)
    if compacted.get("code_template"):
        compacted["code_template"] = _clip_text(str(compacted["code_template"]), 5_000)
    if compacted.get("examples"):
        compacted["examples"] = _compact_examples(compacted["examples"])
    if compacted.get("framework_apis"):
        compacted["framework_apis"] = {
            str(name): _clip_text(str(source), 7_000)
            for name, source in dict(compacted["framework_apis"]).items()
        }

    compacted["context_note"] = (
        "已省略重复的 example_ordinary/example_design 完整文件；系统提示词已提供"
        "项目模板，当前字段包含本题描述、签名、模板和必要 framework API。"
    )
    return compacted


def _compact_examples(examples: Any) -> Any:
    """裁剪异常冗长的 example 文本，同时保留所有官方 example 条目。"""
    if not isinstance(examples, list):
        return examples
    compacted = []
    for example in examples:
        if not isinstance(example, dict):
            compacted.append(example)
            continue
        item = dict(example)
        for key, value in list(item.items()):
            if isinstance(value, str):
                item[key] = _clip_text(value, 1_500)
        compacted.append(item)
    return compacted


def _clip_text(text: str, max_chars: int) -> str:
    if len(text) <= max_chars:
        return text
    if max_chars < 80:
        return text[:max_chars]
    head = max_chars * 2 // 3
    tail = max_chars - head
    return f"{text[:head]}\n...[已压缩]...\n{text[-tail:]}"


def truncate_output(output: str, max_chars: int = AIConfig.OUTPUT_EXCERPT_CHARS) -> str:
    """裁剪命令/工具的长输出到 `max_chars`（尾部保留，前面丢）。"""
    if not output:
        return ""
    text = str(output)
    return text if len(text) <= max_chars else text[-max_chars:]


def _infer_retryable(result: Dict[str, Any], tool_name: str) -> bool:
    if result.get("is_successful", False):
        return False
    error_type = str(result.get("error_type", "")).lower()
    error_message = str(result.get("error_message", "")).lower()
    if "timeout" in error_type or "timeout" in error_message:
        return True
    if "network" in error_type or "network" in error_message:
        return True
    if tool_name in {"compile_project", "compile_and_test", "execute_test_suite"}:
        return True
    return False


def _collect_artifacts(result: Dict[str, Any]) -> List[Dict[str, Any]]:
    artifacts: List[Dict[str, Any]] = []
    for file_info in result.get("generated_files", []):
        artifacts.append(
            {
                "type": "file",
                "category": file_info.get("file_category"),
                "path": file_info.get("file_path"),
            }
        )
    if result.get("file_path"):
        artifacts.append(
            {
                "type": "file",
                "category": result.get("file_category"),
                "path": result.get("file_path"),
            }
        )
    return artifacts


def _truncate_output_field(
    result: Dict[str, Any], max_chars: int = AIConfig.OUTPUT_EXCERPT_CHARS
) -> Optional[str]:
    output = result.get("output_excerpt") or result.get("output")
    if not output:
        return None
    text = str(output)
    return text if len(text) <= max_chars else text[-max_chars:]

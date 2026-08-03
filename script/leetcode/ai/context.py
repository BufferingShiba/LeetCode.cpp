#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""对话上下文的轻量压缩工具。

工具调用型 agent 最容易出现的成本问题不是单次回复，而是把每一轮的
assistant 推理、题目元数据和工具结果原样再次发送。这里不依赖额外的模型
调用，而是在安全的用户消息边界压缩旧历史，并保留对后续代码真正有用的
状态摘要。
"""

import json
from typing import Any, Dict, Iterable, List, Tuple


def estimate_chars(messages: Iterable[Dict[str, Any]]) -> int:
    """估算发送给 provider 的上下文大小（字符数，不冒充 token 数）。"""
    total = 0
    for message in messages:
        try:
            total += len(json.dumps(message, ensure_ascii=False, separators=(",", ":")))
        except (TypeError, ValueError):
            total += len(str(message))
    return total


def compact_messages(
    messages: List[Dict[str, Any]],
    *,
    max_chars: int,
    keep_messages: int = 10,
    summary_max_chars: int = 10_000,
) -> Tuple[List[Dict[str, Any]], int]:
    """在不破坏 tool-call 协议的前提下压缩旧消息。

    返回 ``(消息, 丢弃的消息数)``。system prompt 和最初的 user 请求始终保留；
    尾部从一个 user 边界开始保留，避免留下没有对应 assistant tool-call 的
    ``role=tool`` 消息。历史摘要使用普通 user 消息注入，不需要再次调用模型。
    """
    if max_chars <= 0 or len(messages) <= 3 or estimate_chars(messages) <= max_chars:
        return messages, 0

    prefix_count = min(2, len(messages))
    candidate = max(prefix_count, len(messages) - max(2, keep_messages))
    start = _safe_tail_start(messages, candidate, prefix_count)

    # 极端情况下尾部本身仍然超过上限：逐个寻找更晚的 user 边界，至少保留
    # 最近一轮的反馈/工具结果。正常运行通常只会走一次这里。
    while start < len(messages) - 2 and estimate_chars(messages[start:]) > max_chars:
        later = _next_user_boundary(messages, start + 1)
        if later is None:
            break
        start = later

    dropped = messages[prefix_count:start]
    if not dropped:
        return messages, 0

    summary = summarize_messages(dropped, max_chars=summary_max_chars)
    summary_message = {
        "role": "user",
        "content": (
            "【系统维护的历史摘要】旧的推理和工具原文已压缩。以下摘要只用于保持"
            "题目、文件和验证状态，不要重复已经完成的探索：\n"
            f"{summary}"
        ),
    }
    compacted = messages[:prefix_count] + [summary_message] + messages[start:]

    # 这里不删除最新消息；如果单条消息异常巨大，保留它比截断代码/编译错误
    # 更安全。下一轮会继续尝试在新的 user 边界压缩。
    return compacted, len(dropped)


def summarize_messages(
    messages: Iterable[Dict[str, Any]], *, max_chars: int = 10_000
) -> str:
    """提取旧消息中的可恢复状态，忽略大段重复推理。"""
    important: List[str] = []
    secondary: List[str] = []
    for message in messages:
        role = str(message.get("role", "unknown"))
        if role == "tool":
            # 工具状态比旧 assistant 推理更可恢复；优先放在摘要头部，避免
            # 一个很长的思考把题目元数据挤出 summary 的字符上限。
            important.append(_summarize_tool_message(message))
        elif role == "assistant":
            tool_calls = message.get("tool_calls") or []
            names = [
                str(call.get("function", {}).get("name", "unknown"))
                for call in tool_calls
            ]
            content = _clip(str(message.get("content") or ""), 700)
            if names:
                secondary.append(f"assistant 工具调用: {', '.join(names)}")
            elif content:
                secondary.append(f"assistant: {content}")
        elif role == "user":
            content = str(message.get("content") or "")
            if content.startswith("【系统维护的历史摘要】"):
                secondary.append("已存在一份历史摘要，以上文摘要为准。")
            elif content:
                secondary.append(f"user/系统反馈: {_clip(content, 900)}")

    fragments = important + secondary
    if not fragments:
        return "（无可恢复的历史状态）"
    return _clip("\n".join(fragments), max_chars)


def _safe_tail_start(
    messages: List[Dict[str, Any]], candidate: int, prefix_count: int
) -> int:
    user_boundary = _next_user_boundary(messages, candidate)
    if user_boundary is not None:
        return user_boundary

    # 没有新的 user 消息时，不能从 tool 消息开始；向前带上它对应的 assistant
    # tool-call，保证 OpenAI chat messages 仍是合法序列。
    start = min(candidate, len(messages) - 1)
    while start > prefix_count and messages[start].get("role") == "tool":
        start -= 1
    return start


def _next_user_boundary(messages: List[Dict[str, Any]], start: int) -> int | None:
    for index in range(max(0, start), len(messages)):
        if messages[index].get("role") == "user":
            return index
    return None


def _summarize_tool_message(message: Dict[str, Any]) -> str:
    raw_content = message.get("content") or ""
    try:
        payload = json.loads(raw_content) if isinstance(raw_content, str) else {}
    except (TypeError, ValueError):
        payload = {}

    tool_name = str(payload.get("tool_name") or "unknown_tool")
    if tool_name == "fetch_problem_metadata":
        title = payload.get("title") or payload.get("slug") or "未知题目"
        signature = payload.get("function_signature") or ""
        examples = payload.get("examples")
        description = payload.get("description") or ""
        example_text = _clip(_json_text(examples), 2_000) if examples else ""
        parts = [f"已获取题目元数据: {title}"]
        if signature:
            parts.append(f"签名: {_clip(str(signature), 1_000)}")
        if description:
            parts.append(f"题意摘要: {_clip(str(description), 4_500)}")
        if example_text:
            parts.append(f"官方示例: {example_text}")
        return "\n".join(parts)

    status = payload.get("status") or ("success" if payload.get("is_successful") else "error")
    message_text = payload.get("message") or payload.get("error_message") or ""
    output = payload.get("output_excerpt") or ""
    artifacts = payload.get("artifacts") or []
    parts = [f"工具 {tool_name}: {status}"]
    if message_text:
        parts.append(_clip(str(message_text), 1_000))
    if artifacts:
        parts.append(f"文件产物: {_clip(_json_text(artifacts), 1_500)}")
    if output:
        parts.append(f"输出: {_clip(str(output), 2_500)}")
    return " | ".join(parts)


def _json_text(value: Any) -> str:
    try:
        return json.dumps(value, ensure_ascii=False, separators=(",", ":"))
    except (TypeError, ValueError):
        return str(value)


def _clip(value: str, max_chars: int) -> str:
    if max_chars <= 0:
        return ""
    text = str(value)
    if len(text) <= max_chars:
        return text
    if max_chars < 80:
        return text[:max_chars]
    head = max_chars * 2 // 3
    tail = max_chars - head
    return f"{text[:head]}\n...[已压缩]...\n{text[-tail:]}"

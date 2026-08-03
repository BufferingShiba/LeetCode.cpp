#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""项目代码 → 标准 LeetCode 单文件格式的 AI 翻译。

带内容寻址缓存（`submit.cache`）：源码不变时跳过翻译。Compile Error 时调用方
负责 `cache.invalidate` 清条目再重试。
"""

import re
from datetime import datetime
from typing import Any, Dict, Optional

from script.leetcode.config import AIProvider
from script.leetcode.models import ProblemData
from script.leetcode.submit import cache
from script.leetcode.utils import ColorCode, color_text, log_with_time

_SYSTEM = "你是 C++ 代码转换专家，擅长将项目代码转换为 LeetCode 格式。只输出代码，不要有其他说明。"


def translate(
    problem_data: ProblemData,
    header_code: Optional[str],
    source_code: str,
    solution_num: int,
    *,
    client: Any,
    provider: AIProvider,
    model: str,
) -> Optional[str]:
    """缓存命中直接返回，否则调模型翻译并保留一个本地结构化兜底。"""

    def translate_with_fallback() -> Optional[str]:
        code = _call_llm(
            problem_data, header_code, source_code, solution_num,
            client=client, provider=provider, model=model,
        )
        if code:
            return code

        fallback = _deterministic_project_fallback(
            problem_data, header_code, source_code, solution_num,
        )
        if fallback:
            log_with_time(
                "🧩 AI 翻译无有效响应，已启用本地源码结构化兜底",
                ColorCode.YELLOW,
            )
        return fallback

    code = cache.get_or_translate(
        slug=problem_data.slug,
        solution_num=solution_num,
        source_content=source_code,
        translate_fn=translate_with_fallback,
    )
    normalized_code = _extract_code_block(code).strip() if code else code
    if normalized_code != code:
        # A previous translator version could cache a Markdown fence.  Never
        # send that fence to LeetCode; normalize and replace the cache entry
        # before doing the shape check.
        cache.invalidate(problem_data.slug, solution_num, source_code)
        if normalized_code:
            cache.get_or_translate(
                slug=problem_data.slug,
                solution_num=solution_num,
                source_content=source_code,
                translate_fn=lambda: normalized_code,
            )
        code = normalized_code
    if _looks_like_submission(code, problem_data):
        return code

    # 空响应 / 解释文本 / 遗漏 Solution 声明不能进入提交链路；如果来自旧缓存，
    # 先失效，避免后续每次提交重复复用同一份坏翻译。
    if code:
        cache.invalidate(problem_data.slug, solution_num, source_code)

    # 旧缓存可能是在加入兜底逻辑前生成的坏结果。清掉后再运行一次本地
    # 转换，确保缓存中的空响应不会继续阻塞持久化提交队列。
    fallback = _deterministic_project_fallback(
        problem_data, header_code, source_code, solution_num,
    )
    if _looks_like_submission(fallback, problem_data):
        cache.get_or_translate(
            slug=problem_data.slug,
            solution_num=solution_num,
            source_content=source_code,
            translate_fn=lambda: fallback,
        )
        log_with_time(
            "🧩 已用本地源码结构化兜底替换无效翻译缓存",
            ColorCode.YELLOW,
        )
        return fallback

    log_with_time("❌ 翻译结果未通过 C++ 提交格式检查，已阻止提交", ColorCode.RED)
    return None


def _call_llm(
    problem_data: ProblemData,
    header_code: Optional[str],
    source_code: str,
    solution_num: int,
    *,
    client: Any,
    provider: AIProvider,
    model: str,
) -> Optional[str]:
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"[{timestamp}] 🤖 正在使用 AI 转换代码格式...", end=" ", flush=True)

    prompt = _build_prompt(problem_data, header_code, source_code, solution_num)
    try:
        for attempt in range(2):
            extra_params: Dict[str, Any] = provider.build_request_kwargs(allow_temperature=True)
            response = client.chat.completions.create(
                model=model,
                messages=[
                    {"role": "system", "content": _SYSTEM},
                    {"role": "user", "content": prompt},
                ],
                max_tokens=4000,
                **extra_params,
            )
            raw = response.choices[0].message.content
            code = _extract_code_block(raw).strip()
            if _looks_like_submission(code, problem_data):
                print(color_text("✅ 完成", ColorCode.GREEN.value))
                return code
            if attempt == 0:
                log_with_time(
                    "⚠️ AI 返回空内容或非可提交 C++，正在用严格格式提示重试",
                    ColorCode.YELLOW,
                )
                prompt += (
                    "\n\n【重试要求】上一次输出无效。请现在只输出完整、非空的 C++ 源码；"
                    "必须包含官方模板要求的 class 和方法，禁止解释、Markdown 说明或省略号。"
                )
                continue
            raise ValueError("AI 返回为空或缺少符合官方模板的 class/method")
    except Exception as e:
        log_with_time(f"❌ AI 转换失败: {e}", ColorCode.RED)
        return None


def _build_prompt(problem_data: ProblemData, header_code: Optional[str], source_code: str, solution_num: int) -> str:
    cpp_template = problem_data.get_cpp_code_template()
    return f"""请将以下 LeetCode C++ 项目代码转换为标准 LeetCode 提交格式。

题目：{problem_data.title}
题目描述：
{problem_data.content[:1500]}...

【官方 C++ 接口模板（权威，必须严格遵守）】
{cpp_template or "(接口模板不可用，请从题目数据推断)"}

【原始头文件】
{header_code or "(无头文件)"}

【原始源文件】
{source_code}

【使用策略】使用 solution{solution_num} 函数（默认是第一个解法，可通过 --solution N 指定其他）

【转换要求】
1. 转换为标准 LeetCode class Solution 格式
2. 只包含 public 区域的解题函数，不要多策略注册代码
3. 移除项目特定的命名空间 (leetcode::problem_XXX)
4. 保留所有必要的辅助函数和类定义，但把它们放到 Solution 类内部或改为私有；
   C++ 中任何类型、别名、辅助函数或成员声明都必须先于引用它们的成员，尤其不要
   在 unordered_set/unordered_map 等成员声明之后才定义其 Hash 类型
5. 确保代码可以直接在 LeetCode 上编译运行
6. 只输出最终代码，不要有其他说明文字
7. 官方 C++ 接口模板中的方法名、返回类型、参数类型和参数顺序是线上评测的唯一权威；
   必须逐字保持，尤其不要把单数/复数方法名互相改写。
8. 如果辅助函数被放入 `Solution` 类并在 lambda 中调用，lambda 必须使用 `[this]` 或
   `[&]` 捕获，或者将辅助函数声明为 `static`；禁止用 `[]` 调用非静态成员函数。

【LeetCode 格式示例】
```cpp
class Solution {{
public:
    vector<int> twoSum(vector<int>& nums, int target) {{
        // 实现
    }}
}};
```

请输出转换后的代码："""


def _extract_code_block(raw: Optional[str]) -> str:
    if not raw:
        return ""
    if "```cpp" in raw:
        m = re.search(r"```cpp\s*(.*?)\s*```", raw, re.DOTALL)
        if m:
            return m.group(1)
    if "```" in raw:
        m = re.search(r"```\s*(.*?)\s*```", raw, re.DOTALL)
        if m:
            return m.group(1)
    return raw


def _looks_like_submission(code: Optional[str], problem_data: ProblemData) -> bool:
    """轻量校验翻译结果，拦截空响应和明显不能提交的模型输出。"""
    if not code or not code.strip():
        return False
    if "```" in code:
        return False

    template = problem_data.get_cpp_code_template() or ""
    class_names = re.findall(r"\bclass\s+([A-Za-z_]\w*)", template)
    # Problem templates often contain commented helper definitions such as
    # TreeNode/ListNode/Node before the actual submission class.  Those types
    # are provided by LeetCode's judge and must not be required in the model's
    # ``class Solution`` output.
    if "Solution" in class_names:
        class_names = ["Solution"]
    if class_names:
        if not any(re.search(rf"\bclass\s+{re.escape(name)}\b", code) for name in class_names):
            return False
    elif not re.search(r"\bclass\s+Solution\b", code):
        return False

    # 普通题模板通常只有一个方法；若能解析出方法名，也要求它出现在结果中.
    # Strip the commented helper class first: e.g. an N-ary template contains
    # ``Node()`` constructors before ``Solution::postorder``.
    signature_template = re.sub(r"/\*.*?\*/", "", template, flags=re.DOTALL)
    signature_template = re.sub(r"//[^\n]*", "", signature_template)
    solution_body = re.search(
        r"\bclass\s+Solution\b[^\{]*\{(.*?)\}",
        signature_template,
        flags=re.DOTALL,
    )
    method_scope = solution_body.group(1) if solution_body else signature_template
    method_match = re.search(
        r"\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*(?:\{|;)",
        method_scope,
    )
    if method_match and not re.search(rf"\b{re.escape(method_match.group(1))}\s*\(", code):
        return False
    return True


def _extract_registered_implementations(source_code: str) -> list[str]:
    """Extract final strategy function names without being confused by nested calls."""
    names: list[str] = []
    search_from = 0
    while True:
        marker = re.search(r"\bregisterStrategy\s*\(", source_code[search_from:])
        if not marker:
            break
        open_index = search_from + marker.end() - 1
        close_index = _matching_parenthesis(source_code, open_index)
        if close_index is None:
            break
        registration = source_code[open_index + 1:close_index]
        implementation_match = re.search(
            r",\s*&?\s*([A-Za-z_]\w*)\s*$",
            registration.strip(),
            flags=re.DOTALL,
        )
        if implementation_match:
            names.append(implementation_match.group(1))
        search_from = close_index + 1
    return names


def _matching_parenthesis(source_code: str, open_index: int) -> Optional[int]:
    """Find a C++ parenthesis close while ignoring strings and comments."""
    depth = 0
    quote: Optional[str] = None
    escaped = False
    in_line_comment = False
    in_block_comment = False
    index = open_index
    while index < len(source_code):
        char = source_code[index]
        next_char = source_code[index + 1] if index + 1 < len(source_code) else ""
        if in_line_comment:
            if char == "\n":
                in_line_comment = False
        elif in_block_comment:
            if char == "*" and next_char == "/":
                in_block_comment = False
                index += 1
        elif quote:
            if escaped:
                escaped = False
            elif char == "\\":
                escaped = True
            elif char == quote:
                quote = None
        elif char == "/" and next_char == "/":
            in_line_comment = True
            index += 1
        elif char == "/" and next_char == "*":
            in_block_comment = True
            index += 1
        elif char in {'"', "'"}:
            quote = char
        elif char == "(":
            depth += 1
        elif char == ")":
            depth -= 1
            if depth == 0:
                return index
        index += 1
    return None


def _deterministic_project_fallback(
    problem_data: ProblemData,
    header_code: Optional[str],
    source_code: str,
    solution_num: int,
) -> Optional[str]:
    """把项目中的单策略源码机械地包成 ``class Solution``。

    绝大多数项目题解都遵循同一个边界：匿名命名空间中是纯算法实现，
    构造函数负责注册策略，末尾的成员函数只是把参数转发给当前策略。
    当模型服务返回空响应时，直接复用这两个稳定边界比再次提交空代码更
    安全；如果源码不符合这个形状则返回 ``None``，继续走人工/模型路径。
    """
    class_match = re.search(
        r"\bclass\s+([A-Za-z_]\w*)\s*:[^{;]*\bSolutionBase\b",
        header_code or source_code,
    )
    if not class_match:
        class_match = re.search(
            r"\bclass\s+([A-Za-z_]\w*)\s*(?::|\{)",
            header_code or source_code,
        )
    if not class_match:
        return None
    class_name = class_match.group(1)

    implementation_names = _extract_registered_implementations(source_code)
    if not implementation_names:
        return None
    implementation_index = max(1, solution_num) - 1
    if implementation_index >= len(implementation_names):
        implementation_index = len(implementation_names) - 1
    implementation_name = implementation_names[implementation_index]

    # 只抓取项目的匿名命名空间，避开 SolutionBase、元信息和策略注册代码。
    anonymous_namespace = re.search(
        r"\bnamespace\s*\{\s*(.*?)\n\s*\}\s*//\s*namespace",
        source_code,
        flags=re.DOTALL,
    )
    if not anonymous_namespace:
        return None

    wrapper = re.search(
        rf"^[ \t]*(?P<return_type>[A-Za-z_][^\n{{}}]*?)[ \t]+"
        rf"{re.escape(class_name)}::(?P<method>[A-Za-z_]\w*)\s*"
        rf"\((?P<params>.*?)\)\s*\{{\s*"
        rf"return\s+(?:this->)?getSolution\(\)\s*\("
        rf"(?P<args>.*?)\)\s*;\s*\}}",
        source_code,
        flags=re.DOTALL | re.MULTILINE,
    )
    if not wrapper and header_code:
        # Some generated project headers keep the forwarding method inline;
        # the source then contains only the implementation and registration.
        wrapper = re.search(
            r"^[ \t]*(?P<return_type>[A-Za-z_][^\n{{}}]*?)[ \t]+"
            r"(?P<method>[A-Za-z_]\w*)\s*\((?P<params>.*?)\)\s*\{\s*"
            r"return\s+(?:this->)?getSolution\(\)\s*\("
            r"(?P<args>.*?)\)\s*;\s*\}",
            header_code,
            flags=re.DOTALL | re.MULTILINE,
        )
    if not wrapper:
        return None

    return_type = " ".join(wrapper.group("return_type").split())
    method = wrapper.group("method")
    params = " ".join(wrapper.group("params").split())
    args = " ".join(wrapper.group("args").split())
    body = anonymous_namespace.group(1).strip()
    if not body or not return_type:
        return None

    return (
        "#include <bits/stdc++.h>\n\n"
        "namespace {\n"
        f"{body}\n"
        "}  // namespace\n\n"
        "class Solution {\n"
        "public:\n"
        f"    {return_type} {method}({params}) {{\n"
        f"        return {implementation_name}({args});\n"
        "    }\n"
        "};\n"
    )

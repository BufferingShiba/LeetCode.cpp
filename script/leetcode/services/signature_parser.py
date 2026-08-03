#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""C++ 函数签名解析：从 LeetCode 代码模板里扒出返回类型 / 名称 / 参数列表。

处理模板嵌套参数（`vector<pair<int,int>>`）；跳过构造/析构函数；返回结构化
`FunctionSignature`。
"""

import re
from typing import List, Optional

from script.leetcode.exceptions import SignatureError
from script.leetcode.models import FunctionParameter, FunctionSignature


class SignatureParser:
    SIGNATURE_PATTERN = re.compile(
        r"^\s*(?P<return_type>.+?)\s+"  # 返回类型（允许嵌套模板）
        r"(?P<name>[A-Za-z_]\w*)\s*"  # 函数名
        r"\((?P<params>.*)\)\s*$",  # 参数列表
        re.DOTALL,
    )

    @classmethod
    def extract_from_code_template(cls, code_template: str) -> Optional[str]:
        """从 `class Solution` 里摘第一个非构造/析构的方法签名。

        LeetCode 的返回类型经常包含嵌套模板，例如
        ``vector<vector<int>>``。旧实现只允许一层 ``<...>``，遇到这类
        签名就会退回 ``void solve()``，让 scaffold 与线上接口脱节。这里
        先定位 Solution 类本体，再在类体中匹配方法，避免被 N 叉树模板里
        注释掉的 Node 辅助类干扰。
        """
        cleaned = cls._strip_cpp_comments(code_template)
        class_match = re.search(r"\bclass\s+Solution\s*\{", cleaned)
        if not class_match:
            return None

        open_index = class_match.end() - 1
        close_index = cls._matching_brace(cleaned, open_index)
        if close_index is None:
            return None

        class_body = cleaned[open_index + 1:close_index]
        # Access labels are not part of a C++ type and should not be absorbed
        # when a template method signature spans multiple lines.
        class_body = re.sub(
            r"(?m)^\s*(?:public|private|protected)\s*:\s*", "", class_body
        )
        pattern = re.compile(
            r"(?m)^\s*(?P<return_type>[A-Za-z_][^(){};]*?)\s+"
            r"(?P<name>[A-Za-z_]\w*)\s*"
            r"\((?P<params>[^{}]*)\)\s*"
            r"(?:const\s*)?\{",
            re.DOTALL,
        )

        for match in pattern.finditer(class_body):
            return_type = match.group("return_type").strip()
            func_name = match.group("name").strip()
            params = match.group("params").strip()
            if func_name == "Solution" or func_name.startswith("~"):
                continue
            if not return_type or return_type in {":", ",", "{", "}"}:
                continue
            return f"{return_type} {func_name}({params})"
        return None

    @staticmethod
    def _strip_cpp_comments(code: str) -> str:
        """删除 C++ 注释但保留换行，避免模板辅助类污染签名扫描。"""
        code = re.sub(
            r"/\*.*?\*/",
            lambda match: "\n" * match.group(0).count("\n"),
            code,
            flags=re.DOTALL,
        )
        return re.sub(r"//[^\n]*", "", code)

    @staticmethod
    def _matching_brace(code: str, open_index: int) -> Optional[int]:
        """查找类体右花括号，忽略字符串/字符字面量中的花括号。"""
        depth = 0
        quote: Optional[str] = None
        escaped = False
        for index in range(open_index, len(code)):
            char = code[index]
            if quote:
                if escaped:
                    escaped = False
                elif char == "\\":
                    escaped = True
                elif char == quote:
                    quote = None
                continue
            if char in {'"', "'"}:
                quote = char
            elif char == "{":
                depth += 1
            elif char == "}":
                depth -= 1
                if depth == 0:
                    return index
        return None

    @classmethod
    def parse(cls, signature: str) -> FunctionSignature:
        signature = signature.strip()
        match = cls.SIGNATURE_PATTERN.match(signature)
        if not match:
            raise SignatureError(f"无效的函数签名格式: {signature}")

        return_type = match.group(1).strip()
        func_name = match.group(2).strip()
        params_str = match.group(3).strip()

        parameters = []
        if params_str:
            for param in cls._split_parameters(params_str):
                param = param.strip()
                if not param:
                    continue
                parts = param.rsplit(" ", 1)
                if len(parts) == 2:
                    param_type, param_name = parts
                    parameters.append(FunctionParameter(
                        type=param_type.strip(),
                        name=param_name.strip(),
                    ))
                else:
                    parameters.append(FunctionParameter(type=param.strip(), name=""))

        return FunctionSignature(
            return_type=return_type,
            name=func_name,
            parameters=parameters,
        )

    @staticmethod
    def _split_parameters(params_str: str) -> List[str]:
        """按顶层逗号切参数；模板/括号/数组内部的逗号保留。"""
        params, current = [], []
        angle_depth = paren_depth = bracket_depth = brace_depth = 0
        for char in params_str:
            if char == "<":
                angle_depth += 1
                current.append(char)
            elif char == ">":
                angle_depth = max(0, angle_depth - 1)
                current.append(char)
            elif char == "(":
                paren_depth += 1
                current.append(char)
            elif char == ")":
                paren_depth = max(0, paren_depth - 1)
                current.append(char)
            elif char == "[":
                bracket_depth += 1
                current.append(char)
            elif char == "]":
                bracket_depth = max(0, bracket_depth - 1)
                current.append(char)
            elif char == "{":
                brace_depth += 1
                current.append(char)
            elif char == "}":
                brace_depth = max(0, brace_depth - 1)
                current.append(char)
            elif char == "," and not any(
                (angle_depth, paren_depth, bracket_depth, brace_depth)
            ):
                params.append("".join(current))
                current = []
            else:
                current.append(char)
        if current:
            params.append("".join(current))
        return params

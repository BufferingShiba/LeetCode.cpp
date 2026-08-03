#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
文件生成器
"""

from pathlib import Path
from typing import List, Optional, Tuple

from script.leetcode.config import FileTypeConfig
from script.leetcode.exceptions import FileOperationError
from script.leetcode.models import DesignClassDefinition, FunctionSignature, ProblemInfo
from script.leetcode.services.design_class_extractor import DesignClassExtractor
from script.leetcode.services.naming import class_name_from_slug
from script.leetcode.services.template_renderer import TemplateRenderer
from script.leetcode.utils import ColorCode, color_text


class FileGenerator:
    """题目文件生成器"""
    
    def __init__(
        self, 
        problem_info: ProblemInfo,
        is_design: bool = False,
        design_class_def: Optional[DesignClassDefinition] = None,
        function_signature: Optional[FunctionSignature] = None
    ):
        self.problem_info = problem_info
        self.is_design = is_design
        self.design_class_def = design_class_def
        self.function_signature = function_signature
    
    @property
    def solution_class_name(self) -> str:
        """生成解决方案类名基础部分"""
        return class_name_from_slug(self.problem_info.slug)
    
    def _get_file_paths(self) -> Tuple[Path, Path, Path]:
        """获取三个文件的生成路径"""
        header_path = Path(FileTypeConfig.HEADER.placeholder.format(self.problem_info.slug))
        source_path = Path(FileTypeConfig.SOURCE.placeholder.format(self.problem_info.slug))
        test_path = Path(FileTypeConfig.TEST.placeholder.format(self.problem_info.slug))
        return header_path, source_path, test_path
    
    def _build_context(self) -> dict:
        """构建模板上下文"""
        base_context = {
            "problem_id": self.problem_info.id,
            "problem_title": self.problem_info.title,
            "problem_slug": self.problem_info.slug,
            "leetcode_url_prefix": "https://leetcode.com/problems/",
            "solution_class_name": self.solution_class_name,
            "solution_class_suffix": "Solution",
            "test_class_suffix": "Test",
        }
        
        if self.is_design:
            if self.design_class_def:
                # 设计题的可提交类名来自 LeetCode C++ 模板，可能与 slug
                # 推导名不同（例如 My Calendar II -> MyCalendarTwo）。
                base_context["solution_class_name"] = self.design_class_def.class_name
                base_context['method_declarations'] = DesignClassExtractor.format_method_declarations(
                    self.design_class_def
                )
                base_context['method_implementations'] = DesignClassExtractor.format_method_implementations(
                    self.design_class_def
                )
            else:
                base_context['method_declarations'] = "  // TODO: 添加方法声明"
                base_context['method_implementations'] = "// TODO: 添加方法实现"
        else:
            # 普通题目需要函数签名
            if self.function_signature:
                sig = self.function_signature
                base_context.update({
                    "solution_return_type": sig.return_type,
                    "solution_func_name": sig.name,
                    "solution_param": sig.param_declaration,
                    "solution_param_type": sig.param_types,
                    "solution_param_name": sig.param_names,
                })
            else:
                # 默认函数签名
                base_context.update({
                    "solution_return_type": "void",
                    "solution_func_name": "solve",
                    "solution_param": "",
                    "solution_param_type": "",
                    "solution_param_name": "",
                })
        
        return base_context
    
    def generate_files(self, force: bool = False) -> List[Path]:
        """生成所有三个文件
        
        Args:
            force: 是否强制覆盖已存在的文件
        
        Returns:
            生成的文件路径列表
        """
        header_path, source_path, test_path = self._get_file_paths()
        context = self._build_context()
        
        # 先渲染全部内容，再开始写盘。模板错误不能留下只有 header 或 source
        # 的半成品，否则随机解题的下一轮会把它误判为已有文件并污染工作区。
        rendered = [
            (header_path, TemplateRenderer.render('header', self.is_design, **context)),
            (source_path, TemplateRenderer.render('source', self.is_design, **context)),
            (test_path, TemplateRenderer.render('test', self.is_design, **context)),
        ]

        generated = []
        for file_path, content in rendered:
            if self._write_file(file_path, content, force):
                generated.append(file_path)
        
        return generated
    
    def _write_file(self, file_path: Path, content: str, force: bool) -> bool:
        """写入单个文件
        
        Returns:
            如果文件已存在且未强制覆盖返回 False，否则返回 True
        """
        highlighted_path = color_text(str(file_path), ColorCode.BLUE.value)
        
        if file_path.exists() and not force:
            print(f"文件已存在: {highlighted_path}")
            return False
        
        try:
            # 确保目录存在
            file_path.parent.mkdir(parents=True, exist_ok=True)
            
            # 写入文件
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(content)
            
            print(f"已创建文件: {highlighted_path}")
            return True
        except IOError as e:
            raise FileOperationError(f"无法写入文件 {file_path}: {e}")
    
    def remove_files(self) -> List[Path]:
        """删除所有三个文件
        
        Returns:
            删除的文件路径列表
        """
        header_path, source_path, test_path = self._get_file_paths()
        removed = []
        
        for file_path in [header_path, source_path, test_path]:
            highlighted_path = color_text(str(file_path), ColorCode.RED.value)
            
            if file_path.exists():
                file_path.unlink()
                print(f"已删除文件: {highlighted_path}")
                removed.append(file_path)
            else:
                print(f"文件不存在: {highlighted_path}")
        
        return removed
    
    def files_exist(self) -> bool:
        """检查文件是否都已存在"""
        header_path, source_path, test_path = self._get_file_paths()
        return header_path.exists() and source_path.exists() and test_path.exists()

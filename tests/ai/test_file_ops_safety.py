#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from pathlib import Path
from types import SimpleNamespace
from unittest.mock import patch

from script.leetcode.ai.tools.file_ops import FileOps


class _Repo:
    def get_by_id(self, _problem_id: int):
        return SimpleNamespace(slug="example-problem")


def test_rejects_partial_parameterized_test_overwrite(tmp_path: Path) -> None:
    paths = {
        "header": tmp_path / "example-problem.h",
        "source": tmp_path / "example-problem.cpp",
        "test": tmp_path / "example-problem-test.cpp",
    }
    original = (
        '#include "example-problem.h"\n'
        "TEST_P(ExampleTest, OfficialExample1) {}\n"
        "INSTANTIATE_TEST_SUITE_P(LeetCode, ExampleTest, Values(1));\n"
    )
    paths["test"].write_text(original, encoding="utf-8")

    with patch(
        "script.leetcode.ai.tools.file_ops._category_paths", return_value=paths
    ):
        result = FileOps(_Repo(), {}).create_or_update(
            1,
            [{"file_category": "test", "content": "TEST_P(ExampleTest, Extra) {}"}],
            overwrite_existing=True,
        )

    assert not result["is_successful"]
    assert "append_test_case" in result["error_message"]
    assert paths["test"].read_text(encoding="utf-8") == original

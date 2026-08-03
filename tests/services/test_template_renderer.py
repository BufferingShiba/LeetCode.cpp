import unittest
from unittest.mock import Mock, patch

from script.leetcode.models import ProblemInfo
from script.leetcode.services.file_generator import FileGenerator
from script.leetcode.services.naming import class_name_from_slug
from script.leetcode.services.template_renderer import TemplateRenderer


class TestTemplateRenderer(unittest.TestCase):
    def test_ordinary_source_escapes_designated_initializer_braces(self) -> None:
        source = TemplateRenderer.render(
            "source",
            False,
            problem_id=2859,
            problem_title="Sum of Values at Indices With K Set Bits",
            problem_slug="sum-of-values-at-indices-with-k-set-bits",
            leetcode_url_prefix="https://leetcode.com/problems/",
            solution_class_name="SumOfValuesAtIndicesWithKSetBits",
            solution_class_suffix="Solution",
            solution_return_type="int",
            solution_func_name="sumIndicesWithKSetBits",
            solution_param="vector<int>& nums, int k",
            solution_param_type="vector<int>&, int",
            solution_param_name="nums, k",
        )

        self.assertIn('registerStrategy({.name = "Brute Force"}, solution1);', source)
        self.assertIn("sumIndicesWithKSetBits(vector<int>& nums, int k)", source)

    def test_file_generator_does_not_write_partial_templates(self) -> None:
        generator = FileGenerator(
            ProblemInfo(
                id=2859,
                title="Sum of Values at Indices With K Set Bits",
                slug="sum-of-values-at-indices-with-k-set-bits",
            )
        )
        writer = Mock(return_value=True)

        def render(template_type: str, is_design: bool = False, **context: object) -> str:
            if template_type == "source":
                raise ValueError("broken source template")
            return template_type

        with patch.object(generator, "_write_file", writer), patch.object(
            TemplateRenderer, "render", side_effect=render
        ):
            with self.assertRaisesRegex(ValueError, "broken source template"):
                generator.generate_files()

        writer.assert_not_called()

    def test_digit_leading_slug_gets_valid_cpp_identifier_prefix(self) -> None:
        self.assertEqual(
            class_name_from_slug("1-bit-and-2-bit-characters"),
            "Problem1BitAnd2BitCharacters",
        )
        self.assertEqual(
            FileGenerator(
                ProblemInfo(717, "1-bit and 2-bit Characters", "1-bit-and-2-bit-characters")
            ).solution_class_name,
            "Problem1BitAnd2BitCharacters",
        )


if __name__ == "__main__":
    unittest.main()

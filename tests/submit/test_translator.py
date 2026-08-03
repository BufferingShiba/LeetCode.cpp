from script.leetcode.models import ProblemData
from script.leetcode.submit.translator import (
    _build_prompt,
    _deterministic_project_fallback,
    _extract_code_block,
    _looks_like_submission,
)


def test_build_prompt_includes_authoritative_cpp_signature() -> None:
    problem = ProblemData(
        question_id="3871",
        question_frontend_id="3545",
        title="Minimum Deletions",
        title_slug="minimum-deletions",
        difficulty="Easy",
        is_paid_only=False,
        content="Delete characters.",
        code_snippets=[
            {
                "langSlug": "cpp",
                "code": "class Solution { public: int minDeletion(string s, int k); };",
            }
        ],
    )

    prompt = _build_prompt(problem, None, "int solve();", 1)

    assert "int minDeletion(string s, int k)" in prompt
    assert "不要把单数/复数方法名互相改写" in prompt
    assert "Hash 类型" in prompt


def test_build_prompt_handles_missing_cpp_signature() -> None:
    problem = ProblemData(
        question_id="1",
        question_frontend_id="1",
        title="Example",
        title_slug="example",
        difficulty="Easy",
        is_paid_only=False,
        content="Example.",
        code_snippets=None,
    )

    prompt = _build_prompt(problem, None, "int solve();", 1)

    assert "接口模板不可用" in prompt


def test_extract_code_block_handles_empty_model_response() -> None:
    assert _extract_code_block(None) == ""
    assert _extract_code_block("") == ""


def test_translation_shape_requires_official_class_and_method() -> None:
    problem = ProblemData(
        question_id="3871",
        question_frontend_id="3545",
        title="Minimum Deletions",
        title_slug="minimum-deletions",
        difficulty="Easy",
        is_paid_only=False,
        content="Delete characters.",
        code_snippets=[
            {
                "langSlug": "cpp",
                "code": "class Solution { public: int minDeletion(string s, int k); };",
            }
        ],
    )

    valid = "class Solution { public: int minDeletion(string, int) { return 0; } };"
    assert _looks_like_submission(valid, problem)
    assert not _looks_like_submission("", problem)
    assert not _looks_like_submission("class Solution {};", problem)


def test_deterministic_fallback_wraps_registered_project_strategy() -> None:
    problem = ProblemData(
        question_id="1",
        question_frontend_id="1",
        title="Example",
        title_slug="example",
        difficulty="Easy",
        is_paid_only=False,
        content="Example.",
        code_snippets=[
            {
                "langSlug": "cpp",
                "code": "class Solution { public: int solve(int x); };",
            }
        ],
    )
    header = """
    class ExampleSolution : public SolutionBase<Func> {
     public:
      ExampleSolution();
      int solve(int x);
    };
    """
    source = """
    namespace example {
    namespace {
    int solveImpl(int x) { return x + 1; }
    }  // namespace
    ExampleSolution::ExampleSolution() {
      registerStrategy({.name = "simple"}, solveImpl);
    }
    int ExampleSolution::solve(int x) {
      return getSolution()(x);
    }
    }  // namespace example
    """

    translated = _deterministic_project_fallback(problem, header, source, 1)

    assert translated is not None
    assert "class Solution" in translated
    assert "return solveImpl(x);" in translated
    assert _looks_like_submission(translated, problem)


def test_deterministic_fallback_handles_nested_registration_and_inline_wrapper() -> None:
    problem = ProblemData(
        question_id="1",
        question_frontend_id="1",
        title="Example",
        title_slug="example-inline",
        difficulty="Easy",
        is_paid_only=False,
        content="Example.",
        code_snippets=[
            {
                "langSlug": "cpp",
                "code": "class Solution { public: int solve(int x); };",
            }
        ],
    )
    header = """
    class ExampleSolution : public SolutionBase<Func> {
     public:
      ExampleSolution();
      int solve(int x) { return getSolution()(x); }
    };
    """
    source = """
    namespace example {
    namespace {
    int solveImpl(int x) { return x + 1; }
    }  // namespace
    ExampleSolution::ExampleSolution() {
      registerStrategy({.name = "nested f(x)", .note = "a); b"}, &solveImpl);
    }
    }  // namespace example
    """

    translated = _deterministic_project_fallback(problem, header, source, 1)

    assert translated is not None
    assert "return solveImpl(x);" in translated
    assert _looks_like_submission(translated, problem)


def test_deterministic_fallback_skips_problem_node_class() -> None:
    problem = ProblemData(
        question_id="590",
        question_frontend_id="590",
        title="N-ary Tree Postorder Traversal",
        title_slug="n-ary-tree-postorder-traversal",
        difficulty="Easy",
        is_paid_only=False,
        content="Traverse an N-ary tree.",
        code_snippets=[
            {
                "langSlug": "cpp",
                "code": "class Solution { public: vector<int> postorder(Node* root); };",
            }
        ],
    )
    header = """
    class Node { public: int val; };
    class ExampleSolution : public SolutionBase<Func> {
     public:
      ExampleSolution();
      vector<int> postorder(Node* root);
    };
    """
    source = """
    namespace example {
    namespace {
    vector<int> postorderImpl(Node* root) { return {}; }
    }  // namespace
    ExampleSolution::ExampleSolution() {
      registerStrategy({.name = "iterative"}, postorderImpl);
    }
    vector<int> ExampleSolution::postorder(Node* root) {
      return getSolution()(root);
    }
    }  // namespace example
    """

    translated = _deterministic_project_fallback(problem, header, source, 1)

    assert translated is not None
    assert "return postorderImpl(root);" in translated
    assert _looks_like_submission(translated, problem)

#include "leetcode/problems/maximum-nesting-depth-of-the-parentheses.h"

namespace leetcode {
namespace problem_1614 {

namespace {

int maxDepthImpl(const std::string& s) {
  int depth = 0;
  int max_depth = 0;
  for (char c : s) {
    if (c == '(') {
      ++depth;
      if (depth > max_depth) max_depth = depth;
    } else if (c == ')') {
      --depth;
    }
  }
  return max_depth;
}

}  // namespace

MaximumNestingDepthOfTheParenthesesSolution::
    MaximumNestingDepthOfTheParenthesesSolution() {
  setMetaInfo({.id = 1614,
               .title = "Maximum Nesting Depth of the Parentheses",
               .url =
                   "https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/"});
  registerStrategy(
      {"single-pass-counter", "Accepted", "O(n)", "O(1)",
       {"String", "Stack"}},
      [](std::string s) -> int { return maxDepthImpl(s); });
}

int MaximumNestingDepthOfTheParenthesesSolution::maxDepth(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1614
}  // namespace leetcode

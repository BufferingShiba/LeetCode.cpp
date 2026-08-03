#include "leetcode/problems/remove-outermost-parentheses.h"

#include <string>

namespace leetcode::problem_1021 {

static std::string removeOuterParenthesesImpl(std::string s) {
  std::string result;
  result.reserve(s.size());

  int balance = 0;
  for (char c : s) {
    if (c == '(') {
      if (balance > 0) {
        result.push_back(c);
      }
      ++balance;
    } else {
      --balance;
      if (balance > 0) {
        result.push_back(c);
      }
    }
  }

  return result;
}

RemoveOutermostParenthesesSolution::RemoveOutermostParenthesesSolution() {
  setMetaInfo({.id = 1021,
               .title = "Remove Outermost Parentheses",
               .url = "https://leetcode.com/problems/remove-outermost-parentheses/"});

  registerStrategy(
      {.name = "BalanceCounter",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack"}},
      removeOuterParenthesesImpl);
}

std::string RemoveOutermostParenthesesSolution::removeOuterParentheses(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1021

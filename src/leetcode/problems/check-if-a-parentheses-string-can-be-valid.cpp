#include "leetcode/problems/check-if-a-parentheses-string-can-be-valid.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_2116 {

namespace {

bool canBeValidImpl(const std::string& s, const std::string& locked) {
  int n = static_cast<int>(s.size());
  if (n % 2 == 1) {
    return false;
  }

  // Left-to-right: ensure enough potential '(' to cover locked ')'
  int balance = 0;
  for (int i = 0; i < n; ++i) {
    if (locked[i] == '0' || s[i] == '(') {
      ++balance;
    } else {
      --balance;
    }
    if (balance < 0) {
      return false;
    }
  }

  // Right-to-left: ensure enough potential ')' to cover locked '('
  balance = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (locked[i] == '0' || s[i] == ')') {
      ++balance;
    } else {
      --balance;
    }
    if (balance < 0) {
      return false;
    }
  }

  return true;
}

}  // namespace

CheckIfAParenthesesStringCanBeValidSolution::
    CheckIfAParenthesesStringCanBeValidSolution() {
  setMetaInfo({.id = 2116,
               .title = "Check if a Parentheses String Can Be Valid",
               .url = "https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/"});
  registerStrategy(
      {.name = "TwoPassGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Stack", "Greedy"}},
      canBeValidImpl);
}

bool CheckIfAParenthesesStringCanBeValidSolution::canBeValid(
    std::string s, std::string locked) {
  return getSolution()(std::move(s), std::move(locked));
}

}  // namespace problem_2116
}  // namespace leetcode

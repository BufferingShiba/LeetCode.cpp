#include "leetcode/problems/thousand-separator.h"

#include <string>

namespace leetcode::problem_1556 {

namespace {

std::string thousandSeparatorImpl(int n) {
  if (n == 0) {
    return "0";
  }

  std::string result;
  int count = 0;
  while (n > 0) {
    if (count != 0 && count % 3 == 0) {
      result.push_back('.');
    }
    result.push_back(static_cast<char>('0' + (n % 10)));
    n /= 10;
    ++count;
  }

  // The digits were collected in reverse order; reverse the result.
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

ThousandSeparatorSolution::ThousandSeparatorSolution() {
  setMetaInfo({.id = 1556,
               .title = "Thousand Separator",
               .url =
                   "https://leetcode.com/problems/thousand-separator/"});
  registerStrategy(
      {.name = "string-iteration",
       .expected = "Accepted",
       .time_complexity = "O(len(n))",
       .space_complexity = "O(len(n))",
       .tags = {"String"}},
      thousandSeparatorImpl);
}

std::string ThousandSeparatorSolution::thousandSeparator(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_1556

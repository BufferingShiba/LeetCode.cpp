#include "leetcode/problems/largest-3-same-digit-number-in-string.h"

namespace leetcode::problem_2264 {

namespace {

std::string largestGoodIntegerImpl(std::string num) {
  std::string result;
  for (std::size_t i = 0; i + 2 < num.size(); ++i) {
    if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
      if (result.empty() || num[i] > result[0]) {
        result = std::string(3, num[i]);
      }
    }
  }
  return result;
}

}  // namespace

Largest3SameDigitNumberInStringSolution::Largest3SameDigitNumberInStringSolution() {
  setMetaInfo({.id = 2264,
               .title = "Largest 3-Same-Digit Number in String",
               .url = "https://leetcode.com/problems/largest-3-same-digit-number-in-string/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Enumeration"}},
                   largestGoodIntegerImpl);
}

std::string Largest3SameDigitNumberInStringSolution::largestGoodInteger(
    std::string num) {
  return getSolution()(std::move(num));
}

}  // namespace leetcode::problem_2264

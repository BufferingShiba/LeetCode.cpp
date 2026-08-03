#include "leetcode/problems/check-if-number-has-equal-digit-count-and-digit-value.h"

#include <array>

namespace leetcode {
namespace problem_2283 {

namespace {

bool digitCountImpl(std::string num) {
  std::array<int, 10> count{};
  for (char c : num) {
    ++count[c - '0'];
  }
  for (int i = 0; i < static_cast<int>(num.size()); ++i) {
    if (count[i] != num[i] - '0') {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckIfNumberHasEqualDigitCountAndDigitValueSolution::
    CheckIfNumberHasEqualDigitCountAndDigitValueSolution() {
  setMetaInfo({.id = 2283,
               .title = "Check if Number Has Equal Digit Count and Digit Value",
               .url = "https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/"});
  registerStrategy(
      {"CountArray", "Accepted", "O(n)", "O(1)",
       {"Hash Table", "String", "Counting"}},
      digitCountImpl);
}

bool CheckIfNumberHasEqualDigitCountAndDigitValueSolution::digitCount(
    std::string num) {
  return getSolution()(std::move(num));
}

}  // namespace problem_2283
}  // namespace leetcode

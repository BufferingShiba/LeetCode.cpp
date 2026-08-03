#include "leetcode/problems/concatenate-non-zero-digits-and-multiply-by-sum-i.h"

#include <string>

namespace leetcode::problem_3754 {

namespace {

long long sumAndMultiplyImpl(int n) {
  const std::string digits = std::to_string(n);
  long long x = 0;
  long long sum = 0;
  for (char c : digits) {
    if (c != '0') {
      x = x * 10 + (c - '0');
      sum += (c - '0');
    }
  }
  return x * sum;
}

}  // namespace

long long ConcatenateNonZeroDigitsAndMultiplyBySumISolution::sumAndMultiply(
    int n) {
  return getSolution()(n);
}

ConcatenateNonZeroDigitsAndMultiplyBySumISolution::
    ConcatenateNonZeroDigitsAndMultiplyBySumISolution() {
  setMetaInfo({.id = 3754,
               .title = "Concatenate Non-Zero Digits and Multiply by Sum I",
               .url = "https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/"});
  registerStrategy(
      {.name = "simulation",
       .expected = "Accepted",
       .time_complexity = "O(d)",
       .space_complexity = "O(d)",
       .tags = {"Math", "Simulation"}},
      &sumAndMultiplyImpl);
}

}  // namespace leetcode::problem_3754

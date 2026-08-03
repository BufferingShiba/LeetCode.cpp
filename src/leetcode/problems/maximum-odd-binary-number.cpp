#include "leetcode/problems/maximum-odd-binary-number.h"

#include <string>

namespace leetcode::problem_2864 {

namespace {

// Greedy: count '1's. Keep one '1' at the end (odd number), place the rest
// count-1 ones at the front for maximum value, zeros in the middle.
std::string maximumOddBinaryNumberImpl(std::string s) {
  int ones = 0;
  for (char c : s) {
    if (c == '1') {
      ++ones;
    }
  }
  const int zeros = static_cast<int>(s.size()) - ones;
  return std::string(ones - 1, '1') + std::string(zeros, '0') + '1';
}

}  // namespace

MaximumOddBinaryNumberSolution::MaximumOddBinaryNumberSolution() {
  setMetaInfo({.id = 2864,
               .title = "Maximum Odd Binary Number",
               .url = "https://leetcode.com/problems/maximum-odd-binary-number/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Math", "String", "Greedy"}},
      maximumOddBinaryNumberImpl);
}

std::string MaximumOddBinaryNumberSolution::maximumOddBinaryNumber(
    std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2864

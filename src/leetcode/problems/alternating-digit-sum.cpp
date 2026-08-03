#include "leetcode/problems/alternating-digit-sum.h"

#include <string>

namespace leetcode {
namespace problem_2544 {

namespace {

int alternateDigitSumImpl(int n) {
  const std::string s = std::to_string(n);
  int sign = 1;
  int sum = 0;
  for (char c : s) {
    int digit = c - '0';
    sum += sign * digit;
    sign = -sign;
  }
  return sum;
}

}  // namespace

AlternatingDigitSumSolution::AlternatingDigitSumSolution() {
  setMetaInfo({.id = 2544,
               .title = "Alternating Digit Sum",
               .url = "https://leetcode.com/problems/alternating-digit-sum/"});
  registerStrategy(
      {"string-iteration",
       "Accepted",
       "O(d)",
       "O(d)",
       {"Math"},
       "Convert n to string and traverse digits with alternating signs."},
      alternateDigitSumImpl);
}

int AlternatingDigitSumSolution::alternateDigitSum(int n) {
  return getSolution()(n);
}

}  // namespace problem_2544
}  // namespace leetcode

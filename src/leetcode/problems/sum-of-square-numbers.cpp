#include "leetcode/problems/sum-of-square-numbers.h"

namespace leetcode {
namespace problem_633 {

static bool solution1(int c) {
  long long left = 0;
  long long right = 0;
  while ((right + 1) * (right + 1) <= c) ++right;

  while (left <= right) {
    const long long sum = left * left + right * right;
    if (sum == c) return true;
    if (sum < c) {
      ++left;
    } else {
      --right;
    }
  }
  return false;
}

SumOfSquareNumbersSolution::SumOfSquareNumbersSolution() {
  setMetaInfo({
      .id = 633,
      .title = "Sum of Square Numbers",
      .url = "https://leetcode.com/problems/sum-of-square-numbers"
  });
  registerStrategy({.name = "Two Pointers"}, solution1);
}

bool SumOfSquareNumbersSolution::judgeSquareSum(int c) {
  return getSolution()(c);
}

}  // namespace problem_633
}  // namespace leetcode

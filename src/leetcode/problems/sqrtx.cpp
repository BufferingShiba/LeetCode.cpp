#include "leetcode/problems/sqrtx.h"

namespace leetcode::problem_69 {

namespace {

int mySqrtImpl(int x) {
  if (x < 2) return x;
  int lo = 1, hi = x;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid <= x / mid) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return hi;
}

}  // namespace

SqrtxSolution::SqrtxSolution() {
  setMetaInfo({.id = 69,
               .title = "Sqrt(x)",
               .url = "https://leetcode.com/problems/sqrtx/"});
  registerStrategy(
      {.name = "binary_search",
       .expected = "Accepted",
       .time_complexity = "O(log x)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Binary Search"}},
      mySqrtImpl);
}

int SqrtxSolution::mySqrt(int x) { return getSolution()(x); }

}  // namespace leetcode::problem_69

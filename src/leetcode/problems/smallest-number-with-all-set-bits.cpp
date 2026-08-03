#include "leetcode/problems/smallest-number-with-all-set-bits.h"

namespace leetcode::problem_3370 {

namespace {

int smallestNumberImpl(int n) {
  int x = 1;
  while (x < n) {
    x = (x << 1) | 1;
  }
  return x;
}

}  // namespace

SmallestNumberWithAllSetBitsSolution::SmallestNumberWithAllSetBitsSolution() {
  setMetaInfo({.id = 3370,
               .title = "Smallest Number With All Set Bits",
               .url = "https://leetcode.com/problems/smallest-number-with-all-set-bits/"});
  registerStrategy(
      {.name = "BitManipulation",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"}},
      smallestNumberImpl);
}

int SmallestNumberWithAllSetBitsSolution::smallestNumber(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3370

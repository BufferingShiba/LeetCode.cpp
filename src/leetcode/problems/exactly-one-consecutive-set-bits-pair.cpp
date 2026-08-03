#include "leetcode/problems/exactly-one-consecutive-set-bits-pair.h"

namespace leetcode::problem_3950 {

namespace {

bool consecutiveSetBitsImpl(int n) {
  int count = 0;
  for (int i = 0; i + 1 < 32; ++i) {
    if (((n >> i) & 3) == 3) {
      ++count;
    }
  }
  return count == 1;
}

}  // namespace

ExactlyOneConsecutiveSetBitsPairSolution::
    ExactlyOneConsecutiveSetBitsPairSolution() {
  setMetaInfo({.id = 3950,
               .title = "Exactly One Consecutive Set Bits Pair",
               .url =
                   "https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/"});

  registerStrategy(
      {.name = "bitwise-scan",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      consecutiveSetBitsImpl);
}

bool ExactlyOneConsecutiveSetBitsPairSolution::consecutiveSetBits(
    int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3950

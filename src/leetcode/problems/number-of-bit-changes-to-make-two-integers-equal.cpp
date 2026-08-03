#include "leetcode/problems/number-of-bit-changes-to-make-two-integers-equal.h"

namespace leetcode {
namespace problem_3226 {

namespace {

int minChangesImpl(int n, int k) {
  // If k has a 1 bit where n has a 0 bit, it is impossible (we can only turn
  // 1 bits into 0).
  if ((n & k) != k) {
    return -1;
  }
  // Otherwise each differing bit position must be changed from 1 to 0.
  return __builtin_popcount(n ^ k);
}

}  // namespace

NumberOfBitChangesToMakeTwoIntegersEqualSolution::
    NumberOfBitChangesToMakeTwoIntegersEqualSolution() {
  setMetaInfo(
      {.id = 3226,
       .title = "Number of Bit Changes to Make Two Integers Equal",
       .url = "https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/"});
  registerStrategy(
      {.name = "BitManipulation",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      minChangesImpl);
}

int NumberOfBitChangesToMakeTwoIntegersEqualSolution::minChanges(int n,
                                                                 int k) {
  return getSolution()(n, k);
}

}  // namespace problem_3226
}  // namespace leetcode

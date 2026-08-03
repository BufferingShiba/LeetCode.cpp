#include "leetcode/problems/minimum-adjacent-swaps-to-partition-array.h"

namespace leetcode {
namespace problem_3994 {

namespace {

int minAdjacentSwapsImpl(std::vector<int>& nums, int a, int b) {
  constexpr long long kMod = 1000000007LL;
  long long inv = 0;
  long long cntL = 0;  // elements < a
  long long cntM = 0;  // elements in [a, b]
  long long cntR = 0;  // elements > b
  // Desired order: type L (0) < M (1) < R (2).
  // For each new element, sum preceding elements whose type is strictly
  // larger than the current element's type (these form inversions).
  for (int x : nums) {
    if (x < a) {               // type L = 0, inversions with M and R
      inv += cntM + cntR;
      ++cntL;
    } else if (x > b) {        // type R = 2, inversions with none
      ++cntR;
    } else {                   // type M = 1, inversions with R
      inv += cntR;
      ++cntM;
    }
    inv %= kMod;
  }
  return static_cast<int>(inv % kMod);
}

}  // namespace

MinimumAdjacentSwapsToPartitionArraySolution::
    MinimumAdjacentSwapsToPartitionArraySolution() {
  setMetaInfo({.id = 3994,
               .title = "Minimum Adjacent Swaps to Partition Array",
               .url =
                   "https://leetcode.com/problems/minimum-adjacent-swaps-to-"
                   "partition-array/"});
  registerStrategy({.name = "InversionCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},
                   minAdjacentSwapsImpl);
}

int MinimumAdjacentSwapsToPartitionArraySolution::minAdjacentSwaps(
    std::vector<int>& nums, int a, int b) {
  return getSolution()(nums, a, b);
}

}  // namespace problem_3994
}  // namespace leetcode

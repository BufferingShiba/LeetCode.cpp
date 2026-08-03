#include "leetcode/problems/smallest-index-with-digit-sum-equal-to-index.h"

namespace leetcode::problem_3550 {

namespace {

int digitSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int smallestIndexImpl(std::vector<int>& nums) {
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (digitSum(nums[i]) == i) {
      return i;
    }
  }
  return -1;
}

}  // namespace

SmallestIndexWithDigitSumEqualToIndexSolution::
    SmallestIndexWithDigitSumEqualToIndexSolution() {
  setMetaInfo({
      .id = 3550,
      .title = "Smallest Index With Digit Sum Equal to Index",
      .url = "https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/",
  });

  registerStrategy({.name = "linear",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},
                   smallestIndexImpl);
}

int SmallestIndexWithDigitSumEqualToIndexSolution::smallestIndex(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3550

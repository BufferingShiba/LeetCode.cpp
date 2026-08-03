#include "leetcode/problems/largest-number-at-least-twice-of-others.h"

namespace leetcode {
namespace problem_747 {

namespace {

int dominantIndexImpl(std::vector<int>& nums) {
  int maxIdx = 0;
  int secondMax = -1;
  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] > nums[maxIdx]) {
      secondMax = nums[maxIdx];
      maxIdx = i;
    } else if (nums[i] > secondMax) {
      secondMax = nums[i];
    }
  }
  if (nums[maxIdx] >= 2 * secondMax) {
    return maxIdx;
  }
  return -1;
}

}  // namespace

LargestNumberAtLeastTwiceOfOthersSolution::
    LargestNumberAtLeastTwiceOfOthersSolution() {
  setMetaInfo({747, "Largest Number At Least Twice of Others",
               "https://leetcode.com/problems/largest-number-at-least-twice-of-others/"});
  registerStrategy(
      {"SingleScan", "Accepted", "O(n)", "O(1)",
       {"Array", "Sorting"}},
      dominantIndexImpl);
}

int LargestNumberAtLeastTwiceOfOthersSolution::dominantIndex(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_747
}  // namespace leetcode

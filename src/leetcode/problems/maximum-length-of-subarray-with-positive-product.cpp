#include "leetcode/problems/maximum-length-of-subarray-with-positive-product.h"

namespace leetcode::problem_1567 {

namespace {

int getMaxLenImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int ans = 0;
  int firstNeg = -1;      // index of first negative in current segment
  int segStart = 0;       // start index of current segment
  int negCount = 0;       // negative count in current segment (mod parity tracked below)
  int negParity = 0;      // 0 = even negatives, 1 = odd

  for (int i = 0; i < n; ++i) {
    if (nums[i] == 0) {
      // reset segment
      segStart = i + 1;
      firstNeg = -1;
      negCount = 0;
      negParity = 0;
      continue;
    }
    if (nums[i] < 0) {
      if (firstNeg == -1) firstNeg = i;
      negCount++;
      negParity ^= 1;
    }
    if (negParity == 0) {
      // even negatives: whole segment from segStart to i is valid
      ans = std::max(ans, i - segStart + 1);
    } else {
      // odd negatives: exclude the first negative -> start from firstNeg+1
      ans = std::max(ans, i - (firstNeg + 1) + 1);
    }
  }

  return ans;
}

}  // namespace

MaximumLengthOfSubarrayWithPositiveProductSolution::MaximumLengthOfSubarrayWithPositiveProductSolution() {
  this->setMetaInfo({1567, "Maximum Length of Subarray With Positive Product",
                     "https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/"});
  this->registerStrategy(
      {.name = "Greedy Single Pass", .expected = "Accepted",
       .time_complexity = "O(n)", .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      [](std::vector<int>& nums) { return getMaxLenImpl(nums); });
}

int MaximumLengthOfSubarrayWithPositiveProductSolution::getMaxLen(
    std::vector<int>& nums) {
  return this->getSolution()(nums);
}

}  // namespace leetcode::problem_1567

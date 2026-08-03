#include "leetcode/problems/maximum-average-subarray-i.h"

namespace leetcode::problem_643 {
namespace {

double findMaxAverageImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  long long window_sum = 0;
  for (int i = 0; i < k; ++i) {
    window_sum += nums[i];
  }
  long long max_sum = window_sum;
  for (int i = k; i < n; ++i) {
    window_sum += nums[i] - nums[i - k];
    if (window_sum > max_sum) {
      max_sum = window_sum;
    }
  }
  return static_cast<double>(max_sum) / k;
}

}  // namespace

MaximumAverageSubarrayISolution::MaximumAverageSubarrayISolution() {
  setMetaInfo(
      {.id = 643,
       .title = "Maximum Average Subarray I",
       .url =
           "https://leetcode.com/problems/maximum-average-subarray-i/"});
  registerStrategy(
      {.name = "SlidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      findMaxAverageImpl);
}

double MaximumAverageSubarrayISolution::findMaxAverage(std::vector<int>& nums,
                                                       int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_643

#include "leetcode/problems/count-subarrays-with-score-less-than-k.h"

namespace leetcode::problem_2302 {

namespace {

long long countSubarraysImpl(std::vector<int>& nums, long long k) {
  int n = static_cast<int>(nums.size());
  long long ans = 0;
  long long sum = 0;
  int left = 0;

  for (int right = 0; right < n; ++right) {
    sum += nums[right];
    while (sum * (right - left + 1) >= k) {
      sum -= nums[left];
      ++left;
    }
    ans += right - left + 1;
  }

  return ans;
}

}  // namespace

CountSubarraysWithScoreLessThanKSolution::CountSubarraysWithScoreLessThanKSolution() {
  setMetaInfo({.id = 2302,
               .title = "Count Subarrays With Score Less Than K",
               .url = "https://leetcode.com/problems/count-subarrays-with-score-less-than-k/"});

  registerStrategy(
      {.name = "Sliding Window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sliding Window"}},
      countSubarraysImpl);
}

long long CountSubarraysWithScoreLessThanKSolution::countSubarrays(std::vector<int>& nums, long long k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_2302

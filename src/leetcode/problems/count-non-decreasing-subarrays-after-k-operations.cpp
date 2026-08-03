#include "leetcode/problems/count-non-decreasing-subarrays-after-k-operations.h"

#include <deque>

namespace leetcode {
namespace problem_3420 {

namespace {

long long countFeasibleSubarrays(std::vector<int>& nums, int k) {
  // For a fixed [left, right], the cheapest non-decreasing target is the
  // running maximum from left to right.  The deque stores its constant-value
  // plateaus, from the left end of the window to the right end.
  std::deque<std::pair<long long, int>> plateaus;
  long long sum_target = 0;
  long long sum_values = 0;
  long long answer = 0;
  int right = static_cast<int>(nums.size()) - 1;

  for (int left = right; left >= 0; --left) {
    const long long value = nums[left];
    sum_values += value;

    int merged_count = 1;
    while (!plateaus.empty() && plateaus.front().first <= value) {
      const auto [old_value, count] = plateaus.front();
      plateaus.pop_front();
      sum_target -= old_value * count;
      merged_count += count;
    }
    sum_target += value * merged_count;
    plateaus.push_front({value, merged_count});

    while (right >= left && sum_target - sum_values > k) {
      auto& [last_value, count] = plateaus.back();
      sum_target -= last_value;
      sum_values -= nums[right];
      --right;
      if (--count == 0) {
        plateaus.pop_back();
      }
    }
    answer += right - left + 1;
  }
  return answer;
}

}  // namespace

CountNonDecreasingSubarraysAfterKOperationsSolution::
    CountNonDecreasingSubarraysAfterKOperationsSolution() {
  setMetaInfo({.id = 3420,
               .title = "Count Non-Decreasing Subarrays After K Operations",
               .url = "https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/"});
  registerStrategy({.name = "ReverseWindowMonotonicDeque",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Sliding Window", "Monotonic Queue"}},
                   countFeasibleSubarrays);
}

}  // namespace problem_3420
}  // namespace leetcode

#include "leetcode/problems/shortest-subarray-with-sum-at-least-k.h"

#include <algorithm>
#include <deque>
#include <vector>

namespace leetcode {
namespace problem_862 {

namespace {

int shortestSubarrayImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
  }

  // Monotonic increasing deque of prefix-sum indices.
  std::deque<int> dq;
  int ans = n + 1;

  for (int i = 0; i <= n; ++i) {
    // If prefix[i] - prefix[dq.front()] >= k, the front is the leftmost
    // index that can start a valid subarray ending at i. Pop it so later
    // candidates use a more right-aligned start (hence potentially shorter).
    while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
      ans = std::min(ans, i - dq.front());
      dq.pop_front();
    }

    // Maintain monotonic increasing prefix values in the deque. If the new
    // prefix is not larger than the back's, the back index is strictly worse
    // (larger index, larger-or-equal prefix), so discard it.
    while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }

  return ans <= n ? ans : -1;
}

}  // namespace

ShortestSubarrayWithSumAtLeastKSolution::ShortestSubarrayWithSumAtLeastKSolution() {
  setMetaInfo({.id = 862,
               .title = "Shortest Subarray with Sum at Least K",
               .url = "https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/"});
  registerStrategy(
      {.name = "monotonic-queue",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Queue", "Sliding Window", "Prefix Sum", "Monotonic Queue"}},
      shortestSubarrayImpl);
}

int ShortestSubarrayWithSumAtLeastKSolution::shortestSubarray(std::vector<int>& nums,
                                                                int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_862
}  // namespace leetcode

#include "leetcode/problems/jump-game-vi.h"

#include <deque>
#include <vector>

namespace leetcode {
namespace problem_1696 {

namespace {

int maxResultImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> dp(n);
  std::deque<int> dq;          // stores indices, dp values strictly decreasing
  dp[0] = nums[0];
  dq.push_back(0);
  for (int i = 1; i < n; ++i) {
    // Remove indices out of the window [i-k, i-1]
    while (!dq.empty() && dq.front() < i - k) {
      dq.pop_front();
    }
    dp[i] = nums[i] + dp[dq.front()];
    // Maintain monotonicity: pop back while dp of back index <= dp[i]
    while (!dq.empty() && dp[dq.back()] <= dp[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  return dp[n - 1];
}

}  // namespace

JumpGameViSolution::JumpGameViSolution() {
  setMetaInfo({.id = 1696,
               .title = "Jump Game VI",
               .url = "https://leetcode.com/problems/jump-game-vi/"});
  registerStrategy(
      {.name = "DP with Monotonic Queue",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Queue", "Monotonic Queue"}},
      maxResultImpl);
}

}  // namespace problem_1696
}  // namespace leetcode

#include "leetcode/problems/constrained-subsequence-sum.h"

#include <algorithm>
#include <deque>

namespace leetcode::problem_1425 {

static int constrainedSubsetSumImpl(std::vector<int>& nums, int k) {
  int n = static_cast<int>(nums.size());
  std::deque<std::pair<int, int>> dq;  // (index, dp_value)
  int ans = nums[0];

  for (int i = 0; i < n; ++i) {
    // Remove indices that slide out of the window
    while (!dq.empty() && dq.front().first < i - k) {
      dq.pop_front();
    }

    int prev_max = dq.empty() ? 0 : dq.front().second;
    int dp = nums[i] + std::max(0, prev_max);
    ans = std::max(ans, dp);

    // Maintain monotonic decreasing order by dp value
    while (!dq.empty() && dq.back().second <= dp) {
      dq.pop_back();
    }
    dq.emplace_back(i, dp);
  }

  return ans;
}

ConstrainedSubsequenceSumSolution::ConstrainedSubsequenceSumSolution() {
  setMetaInfo({.id = 1425,
               .title = "Constrained Subsequence Sum",
               .url = "https://leetcode.com/problems/constrained-subsequence-sum/"});
  registerStrategy({.name = "Monotonic Queue",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(k)",
                    .tags = {"Array", "Dynamic Programming", "Queue", "Sliding Window",
                             "Monotonic Queue"}},
                   constrainedSubsetSumImpl);
}

int ConstrainedSubsequenceSumSolution::constrainedSubsetSum(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_1425

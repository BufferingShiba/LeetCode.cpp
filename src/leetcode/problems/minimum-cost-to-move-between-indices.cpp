#include "leetcode/problems/minimum-cost-to-move-between-indices.h"

namespace leetcode::problem_3919 {

namespace {

std::vector<int> minCostImpl(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  const int n = static_cast<int>(nums.size());
  // upCost[i]: minimum cost to move from index i to i+1.
  // downCost[i]: minimum cost to move from index i+1 to i.
  // For interior node k (1 <= k <= n-2), closest(k) = k-1 when
  // diff_{k-1} <= diff_k (tiebreak smaller index, i.e. left).
  //   - forward unit move available iff closest(k) = k+1, i.e. diff_k < diff_{k-1}.
  //   - backward unit move available iff closest(k) = k-1, i.e. diff_{k-1} <= diff_k.
  std::vector<long long> upCost(n - 1, 0), downCost(n - 1, 0);
  for (int i = 0; i + 1 < n; ++i) {
    const long long d = static_cast<long long>(nums[i + 1]) - nums[i];
    bool canUp = false, canDown = false;

    // Move up from index i to i+1 (cost 1 iff closest(i) == i+1).
    if (i == 0) {
      canUp = true;  // node 0 only has right neighbor.
    } else if (i < n - 1) {
      const long long leftDiff = static_cast<long long>(nums[i]) - nums[i - 1];
      if (d < leftDiff) canUp = true;
    }

    // Move down from index i+1 to i (cost 1 iff closest(i+1) == i).
    if (i + 1 == n - 1) {
      canDown = true;  // node n-1 only has left neighbor.
    } else {
      const long long rightDiff = static_cast<long long>(nums[i + 2]) - nums[i + 1];
      if (d <= rightDiff) canDown = true;
    }

    upCost[i] = canUp ? 1 : d;
    downCost[i] = canDown ? 1 : d;
  }

  // Prefix sums: prefUp[i] = sum of upCost[0..i-1].
  std::vector<long long> prefUp(n, 0), prefDown(n, 0);
  for (int i = 0; i + 1 < n; ++i) {
    prefUp[i + 1] = prefUp[i] + upCost[i];
    prefDown[i + 1] = prefDown[i] + downCost[i];
  }

  std::vector<int> ans;
  ans.reserve(queries.size());
  for (const auto& q : queries) {
    const int l = q[0], r = q[1];
    if (l < r) {
      ans.push_back(static_cast<int>(prefUp[r] - prefUp[l]));
    } else {
      ans.push_back(static_cast<int>(prefDown[l] - prefDown[r]));
    }
  }
  return ans;
}

}  // namespace

std::vector<int> MinimumCostToMoveBetweenIndicesSolution::minCost(
    std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

MinimumCostToMoveBetweenIndicesSolution::MinimumCostToMoveBetweenIndicesSolution() {
  setMetaInfo({.id = 3919, .title = "Minimum Cost to Move Between Indices",
               .url = "https://leetcode.com/problems/minimum-cost-to-move-between-indices/"});
  registerStrategy(
      {.name = "prefix-sum-on-directional-edge-costs",
       .expected = "Accepted",
       .time_complexity = "O(n + q)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy", "Prefix Sum"}},
      minCostImpl);
}

}  // namespace leetcode::problem_3919

#include "leetcode/problems/maximum-path-intersection-sum-in-a-grid.h"
#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_3938 {

namespace {

// Kadane variant: max subarray sum with length >= 2
long long maxSubarrayLenAtLeast2(const std::vector<int>& arr) {
  long long ans = LLONG_MIN;
  long long pref = 0;       // prefix sum up to current index (exclusive)
  long long minPref = 0;    // min prefix sum seen up to i-2
  for (size_t i = 0; i < arr.size(); ++i) {
    long long oldPref = pref;
    pref += arr[i];
    if (i >= 1) {
      ans = std::max(ans, pref - minPref);
    }
    minPref = std::min(minPref, oldPref);
  }
  return ans;
}

int maxScoreImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  long long ans = LLONG_MIN;

  // 1. Single interior cells (feasible as isolated intersection)
  if (m >= 3 && n >= 3) {
    for (int r = 1; r < m - 1; ++r) {
      for (int c = 1; c < n - 1; ++c) {
        ans = std::max(ans, static_cast<long long>(grid[r][c]));
      }
    }
  }

  // 2. Max subarray length >= 2 in each row
  for (int r = 0; r < m; ++r) {
    ans = std::max(ans, maxSubarrayLenAtLeast2(grid[r]));
  }

  // 3. Max subarray length >= 2 in each column
  for (int c = 0; c < n; ++c) {
    std::vector<int> col(m);
    for (int r = 0; r < m; ++r) {
      col[r] = grid[r][c];
    }
    ans = std::max(ans, maxSubarrayLenAtLeast2(col));
  }

  return static_cast<int>(ans);
}

}  // namespace

MaximumPathIntersectionSumInAGridSolution::MaximumPathIntersectionSumInAGridSolution() {
  setMetaInfo({.id = 3938,
               .title = "Maximum Path Intersection Sum in a Grid",
               .url = "https://leetcode.com/problems/maximum-path-intersection-sum-in-a-grid/"});
  registerStrategy({.name = "DP with Kadane on rows and columns",
                    .expected = "Accepted",
                    .time_complexity = "O(m * n)",
                    .space_complexity = "O(1) extra",
                    .tags = {"Array", "Dynamic Programming", "Matrix", "Prefix Sum"}},
                   maxScoreImpl);
}

int MaximumPathIntersectionSumInAGridSolution::maxScore(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3938
}  // namespace leetcode

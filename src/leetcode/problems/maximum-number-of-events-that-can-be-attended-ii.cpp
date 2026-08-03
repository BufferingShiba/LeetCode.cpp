#include "leetcode/problems/maximum-number-of-events-that-can-be-attended-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1751 {

namespace {

int maxValueImpl(std::vector<std::vector<int>>& events, int k) {
  const int n = static_cast<int>(events.size());
  // Sort by end day so that DP transitions by previous compatible event
  // can be found with binary search.
  std::sort(events.begin(), events.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] < b[1];
            });

  // prev[i] = index of the last event with end < events[i].start, or -1.
  std::vector<int> prev(n, -1);
  for (int i = 0; i < n; ++i) {
    int lo = 0, hi = i - 1, best = -1;
    const int start = events[i][0];
    while (lo <= hi) {
      const int mid = lo + (hi - lo) / 2;
      if (events[mid][1] < start) {
        best = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    prev[i] = best;
  }

  // dp[i][j] = max value considering the first i+1 events choosing up to j
  // events.
  std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      int take = events[i][2];
      if (prev[i] >= 0) {
        take += dp[prev[i]][j - 1];
      }
      int best = take;
      if (i - 1 >= 0) {
        best = std::max(best, dp[i - 1][j]);
      }
      dp[i][j] = best;
    }
  }

  return dp[n - 1][k];
}

}  // namespace

MaximumNumberOfEventsThatCanBeAttendedIiSolution::
    MaximumNumberOfEventsThatCanBeAttendedIiSolution() {
  setMetaInfo({.id = 1751,
               .title = "Maximum Number of Events That Can Be Attended II",
               .url = "https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/"});
  registerStrategy(
      {.name = "DP with Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(n*k*log n)",
       .space_complexity = "O(n*k)",
       .tags = {"Array", "Binary Search", "Dynamic Programming", "Sorting"}},
      maxValueImpl);
}

int MaximumNumberOfEventsThatCanBeAttendedIiSolution::maxValue(
    std::vector<std::vector<int>>& events, int k) {
  return getSolution()(events, k);
}

}  // namespace problem_1751
}  // namespace leetcode

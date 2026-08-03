#include "leetcode/problems/minimum-number-of-work-sessions-to-finish-the-tasks.h"

#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

namespace leetcode::problem_1986 {

namespace {

int minSessionsImpl(std::vector<int>& tasks, int sessionTime) {
  int n = static_cast<int>(tasks.size());
  int fullMask = (1 << n) - 1;

  // dp[mask] = {sessions, usedTimeInLastSession}
  std::vector<std::pair<int, int>> dp(1 << n, {INT_MAX, INT_MAX});
  dp[0] = {0, 0};

  for (int mask = 1; mask <= fullMask; ++mask) {
    for (int i = 0; i < n; ++i) {
      if ((mask >> i) & 1) {
        int prevMask = mask ^ (1 << i);
        auto [s, t] = dp[prevMask];
        std::pair<int, int> cand;
        if (s == 0) {
          cand = {1, tasks[i]};
        } else if (t + tasks[i] <= sessionTime) {
          cand = {s, t + tasks[i]};
        } else {
          cand = {s + 1, tasks[i]};
        }
        dp[mask] = std::min(dp[mask], cand,
                            [](const auto& a, const auto& b) {
                              if (a.first != b.first) return a.first < b.first;
                              return a.second < b.second;
                            });
      }
    }
  }

  return dp[fullMask].first;
}

}  // namespace

MinimumNumberOfWorkSessionsToFinishTheTasksSolution::
    MinimumNumberOfWorkSessionsToFinishTheTasksSolution() {
  setMetaInfo({.id = 1986,
               .title = "Minimum Number of Work Sessions to Finish the Tasks",
               .url = "https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/"});

  registerStrategy(
      {.name = "DP with Bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n * 2^n)",
       .space_complexity = "O(2^n)",
       .tags = {"Array", "Dynamic Programming", "Backtracking", "Bit Manipulation",
                "Bitmask"}},
      minSessionsImpl);
}

int MinimumNumberOfWorkSessionsToFinishTheTasksSolution::minSessions(
    std::vector<int>& tasks, int sessionTime) {
  return getSolution()(tasks, sessionTime);
}

}  // namespace leetcode::problem_1986

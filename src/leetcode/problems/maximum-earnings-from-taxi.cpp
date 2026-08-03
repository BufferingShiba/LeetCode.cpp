#include "leetcode/problems/maximum-earnings-from-taxi.h"

namespace leetcode {
namespace problem_2008 {
namespace {

long long maxTaxiEarnings(const std::vector<std::vector<int>>& rides, int n) {
  int m = static_cast<int>(rides.size());
  // for each end point, collect rides (start, end, tip)
  std::vector<std::vector<std::pair<int, int>>> byEnd(n + 1);
  for (int i = 0; i < m; ++i) {
    int start = rides[i][0];
    int end = rides[i][1];
    int tip = rides[i][2];
    byEnd[end].push_back({start, end - start + tip});
  }

  std::vector<long long> dp(n + 1, 0);
  for (int x = 1; x <= n; ++x) {
    dp[x] = dp[x - 1];
    for (const auto& [start, earning] : byEnd[x]) {
      dp[x] = std::max(dp[x], dp[start] + earning);
    }
  }
  return dp[n];
}

}  // namespace

MaximumEarningsFromTaxiSolution::MaximumEarningsFromTaxiSolution() {
  setMetaInfo({.id = 2008,
               .title = "Maximum Earnings From Taxi",
               .url = "https://leetcode.com/problems/maximum-earnings-from-taxi/"});

  auto solution1 = [](int n, std::vector<std::vector<int>>& rides) -> long long {
    return maxTaxiEarnings(static_cast<const std::vector<std::vector<int>>&>(rides), n);
  };

  registerStrategy({.name = "dp-by-end-point",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m)",
                    .space_complexity = "O(n + m)",
                    .tags = {"Dynamic Programming", "Array"}},
                   solution1);
}

}  // namespace problem_2008
}  // namespace leetcode

#include "leetcode/problems/minimum-skips-to-arrive-at-meeting-on-time.h"

namespace leetcode {
namespace problem_1883 {

namespace {

constexpr long long kInf = 4e18;

long long ceilToMultiple(long long v, long long speed) {
  if (v % speed == 0) return v;
  return ((v / speed) + 1) * speed;
}

int minSkipsImpl(std::vector<int>& dist, int speed, int hoursBefore) {
  const int n = static_cast<int>(dist.size());
  const long long limit = static_cast<long long>(hoursBefore) * speed;

  // dp[j] = min total time (in units of 1/speed hour, already integer) to
  // finish the roads processed so far, using exactly j skips, where waiting
  // for intermediate roads has been applied.
  std::vector<long long> dp(n + 1, kInf);
  dp[0] = 0;

  // Process middle roads (all but the last) applying ceiling on non-skip.
  for (int i = 0; i < n - 1; ++i) {
    std::vector<long long> ndp(n + 1, kInf);
    for (int j = 0; j <= i + 1; ++j) {
      // Skip the wait after this road (need at least one prior skip slot).
      if (j >= 1 && dp[j - 1] < kInf) {
        ndp[j] = std::min(ndp[j], dp[j - 1] + dist[i]);
      }
      // Do not skip: travel then wait to next integer hour boundary.
      if (dp[j] < kInf) {
        ndp[j] = std::min(ndp[j], ceilToMultiple(dp[j] + dist[i], speed));
      }
    }
    dp.swap(ndp);
  }

  // Final road: no waiting needed.
  for (int j = 0; j < n; ++j) {
    if (dp[j] < kInf && dp[j] + dist[n - 1] <= limit) {
      return j;
    }
  }
  return -1;
}

}  // namespace

MinimumSkipsToArriveAtMeetingOnTimeSolution::MinimumSkipsToArriveAtMeetingOnTimeSolution() {
  setMetaInfo({.id = 1883,
               .title = "Minimum Skips to Arrive at Meeting On Time",
               .url = "https://leetcode.com/problems/minimum-skips-to-arrive-at-meeting-on-time/"});
  registerStrategy(
      {.name = "dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Dynamic Programming", "Memoization"}},
      minSkipsImpl);
}

}  // namespace problem_1883
}  // namespace leetcode

#include "leetcode/problems/race-car.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_818 {

namespace {

int racecarImpl(int target) {
  std::vector<int> dp(target + 1, INT_MAX);
  dp[0] = 0;

  for (int t = 1; t <= target; ++t) {
    // Find smallest k such that (1 << k) - 1 >= t
    int k = 1;
    while ((1 << k) - 1 < t) {
      ++k;
    }
    int forward = (1 << k) - 1;

    if (forward == t) {
      dp[t] = k;
      continue;
    }

    // Case 1: overshoot (go forward k steps, reverse, then handle the excess)
    dp[t] = k + 1 + dp[forward - t];

    // Case 2: undershoot (go forward k-1 steps, reverse, go backward j steps,
    //          reverse again, then handle the remaining distance)
    int k1 = k - 1;
    for (int j = 0; j < k1; ++j) {
      int remaining = t - ((1 << k1) - 1) + ((1 << j) - 1);
      dp[t] = std::min(dp[t], k1 + 1 + j + 1 + dp[remaining]);
    }
  }

  return dp[target];
}

}  // namespace

int RaceCarSolution::racecar(int target) {
  return getSolution()(target);
}

RaceCarSolution::RaceCarSolution() {
  setMetaInfo({.id = 818, .title = "Race Car", .url = "https://leetcode.com/problems/race-car/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(T log^2 T)",
       .space_complexity = "O(T)",
       .tags = {"Dynamic Programming"}},
      racecarImpl);
}

}  // namespace problem_818
}  // namespace leetcode

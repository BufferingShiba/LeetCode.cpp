#include "leetcode/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1269 {

namespace {

constexpr int kMod = 1'000'000'007;

int numWaysImpl(int steps, int arrLen) {
  // The farthest position reachable is bounded by steps (cannot move further
  // than one step per move) and by arrLen - 1.
  int maxPos = std::min(steps, arrLen - 1);
  if (maxPos < 0) maxPos = 0;  // arrLen could be 1

  // DP with two rows for space optimization.
  std::vector<int> prev(maxPos + 1, 0);
  prev[0] = 1;  // 0 steps, at position 0: 1 way

  for (int i = 1; i <= steps; ++i) {
    std::vector<int> cur(maxPos + 1, 0);
    // j ranges from 0 to min(i, maxPos) because after i steps we cannot be
    // beyond position i.
    int limit = std::min(i, maxPos);
    for (int j = 0; j <= limit; ++j) {
      long long ways = prev[j];  // stay
      if (j > 0) {
        ways += prev[j - 1];  // move right from j-1
      }
      if (j < maxPos) {
        ways += prev[j + 1];  // move left from j+1
      }
      cur[j] = static_cast<int>(ways % kMod);
    }
    prev = std::move(cur);
  }

  return prev[0];
}

}  // namespace

NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution::
    NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution() {
  setMetaInfo({.id = 1269,
               .title = "Number of Ways to Stay in the Same Place After Some Steps",
               .url = "https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/"});
  registerStrategy(
      {.name = "DP with space optimization",
       .expected = "Accepted",
       .time_complexity = "O(steps * min(steps, arrLen))",
       .space_complexity = "O(min(steps, arrLen))",
       .tags = {"Dynamic Programming"}},
      numWaysImpl);
}

int NumberOfWaysToStayInTheSamePlaceAfterSomeStepsSolution::numWays(
    int steps, int arrLen) {
  return getSolution()(steps, arrLen);
}

}  // namespace problem_1269
}  // namespace leetcode

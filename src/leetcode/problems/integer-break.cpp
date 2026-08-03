#include "leetcode/problems/integer-break.h"

namespace leetcode {
namespace problem_343 {

static int solution1(int n) {
  // dp[i] = maximum product obtainable by breaking i into a sum of k>=2
  // positive integers. For a single piece we use max(j, dp[j]) so the result is
  // the best over all ways to split the whole n into at least two parts.
  std::vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i] = std::max(dp[i], std::max(j, dp[j]) * std::max(i - j, dp[i - j]));
    }
  }
  return dp[n];
}

IntegerBreakSolution::IntegerBreakSolution() {
  setMetaInfo({
      .id = 343,
      .title = "Integer Break",
      .url = "https://leetcode.com/problems/integer-break"
  });
  registerStrategy(
      {.name = "Dynamic Programming",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Math", "Dynamic Programming"}},
      solution1);
}

int IntegerBreakSolution::integerBreak(int n) {
  return getSolution()(n);
}

}  // namespace problem_343
}  // namespace leetcode

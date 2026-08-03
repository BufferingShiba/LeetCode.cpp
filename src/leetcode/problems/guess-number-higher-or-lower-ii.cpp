#include "leetcode/problems/guess-number-higher-or-lower-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_375 {

namespace {

// Interval DP: dp[l][r] = minimum worst-case money for range [l, r].
int getMoneyAmountImpl(int n) {
  // Use 1-indexed ranges [1, n].
  std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
  for (int len = 2; len <= n; ++len) {
    for (int l = 1; l + len - 1 <= n; ++l) {
      int r = l + len - 1;
      int best = INT_MAX;
      for (int k = l; k <= r; ++k) {
        int left = (k - 1 >= l) ? dp[l][k - 1] : 0;
        int right = (k + 1 <= r) ? dp[k + 1][r] : 0;
        int cost = k + std::max(left, right);
        best = std::min(best, cost);
      }
      dp[l][r] = best;
    }
  }
  return (n >= 1) ? dp[1][n] : 0;
}

}  // namespace

GuessNumberHigherOrLowerIiSolution::GuessNumberHigherOrLowerIiSolution() {
  setMetaInfo({.id = 375,
               .title = "Guess Number Higher or Lower II",
               .url = "https://leetcode.com/problems/guess-number-higher-or-lower-ii/"});
  registerStrategy({.name = "interval-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n^3)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Math", "Dynamic Programming", "Game Theory"}},
                   getMoneyAmountImpl);
}

int GuessNumberHigherOrLowerIiSolution::getMoneyAmount(int n) {
  return getSolution()(n);
}

}  // namespace problem_375
}  // namespace leetcode

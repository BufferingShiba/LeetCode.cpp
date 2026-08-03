#include "leetcode/problems/stone-game-vii.h"

#include <vector>

namespace leetcode::problem_1690 {

namespace {

int stoneGameVIIImpl(std::vector<int>& stones) {
  const int n = static_cast<int>(stones.size());
  // prefix sum array
  std::vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + stones[i];
  }

  // sum of stones[i..j]
  auto rangeSum = [&](int i, int j) { return prefix[j + 1] - prefix[i]; };

  // dp[i][j] = max score difference current player can achieve on subarray [i..j]
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

  // Fill by increasing subarray length.
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      int j = i + len - 1;
      // Remove left stone -> gain sum of [i+1..j], opponent then acts on [i+1..j]
      int takeLeft = rangeSum(i + 1, j) - dp[i + 1][j];
      // Remove right stone -> gain sum of [i..j-1], opponent then acts on [i..j-1]
      int takeRight = rangeSum(i, j - 1) - dp[i][j - 1];
      dp[i][j] = std::max(takeLeft, takeRight);
    }
  }

  return dp[0][n - 1];
}

}  // namespace

StoneGameViiSolution::StoneGameViiSolution() {
  setMetaInfo({.id = 1690,
               .title = "Stone Game VII",
               .url = "https://leetcode.com/problems/stone-game-vii/"});
  registerStrategy({.name = "interval-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Array", "Dynamic Programming", "Game Theory"}},
                   stoneGameVIIImpl);
}

int StoneGameViiSolution::stoneGameVII(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace leetcode::problem_1690

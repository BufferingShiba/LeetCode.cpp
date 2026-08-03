#include "leetcode/problems/dungeon-game.h"

#include <algorithm>

namespace leetcode::problem_174 {

namespace {

int calculateMinimumHPImpl(std::vector<std::vector<int>>& dungeon) {
  int m = static_cast<int>(dungeon.size());
  int n = static_cast<int>(dungeon[0].size());
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT32_MAX));
  // dp[i][j] = min health needed BEFORE entering (i,j) to safely reach the end.
  // A sentinel row/col of INT32_MAX makes the boundary pick the single reachable neighbor.
  dp[m][n - 1] = 1;
  dp[m - 1][n] = 1;
  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      int need = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
      dp[i][j] = std::max(1, need);
    }
  }
  return dp[0][0];
}

}  // namespace

DungeonGameSolution::DungeonGameSolution() {
  this->setMetaInfo({.id = 174,
                     .title = "Dungeon Game",
                     .url = "https://leetcode.com/problems/dungeon-game/"});
  this->registerStrategy(
      {.name = "reverse-dp",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Dynamic Programming", "Matrix"}},
      calculateMinimumHPImpl);
}

int DungeonGameSolution::calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
  return getSolution()(dungeon);
}

}  // namespace leetcode::problem_174

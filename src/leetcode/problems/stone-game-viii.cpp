#include "leetcode/problems/stone-game-viii.h"

#include <algorithm>

namespace leetcode::problem_1872 {

namespace {

int stoneGameVIIIImpl(std::vector<int>& stones) {
  int n = static_cast<int>(stones.size());

  // 计算前缀和数组 P，直接复用 stones 或单独存储
  // 由于只需要从后往前遍历一次，可以原地计算前缀和
  for (int i = 1; i < n; ++i) {
    stones[i] += stones[i - 1];
  }

  // dp[n-1] = P[n-1] - 0 = stones[n-1]
  int suffixMax = stones[n - 1];

  // 从 n-2 到 1 遍历
  for (int i = n - 2; i >= 1; --i) {
    // dp[i] = P[i] - suffixMax
    int dp_i = stones[i] - suffixMax;
    suffixMax = std::max(suffixMax, dp_i);
  }

  // 答案 = max_{j>=1} dp[j] = suffixMax
  return suffixMax;
}

}  // namespace

StoneGameViiiSolution::StoneGameViiiSolution() {
  setMetaInfo({.id = 1872,
               .title = "Stone Game VIII",
               .url = "https://leetcode.com/problems/stone-game-viii/"});

  registerStrategy(
      {.name = "DP + Prefix Sum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Dynamic Programming", "Prefix Sum",
                "Game Theory"}},
      stoneGameVIIIImpl);
}

int StoneGameViiiSolution::stoneGameVIII(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace leetcode::problem_1872

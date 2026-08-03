#include "leetcode/problems/number-of-dice-rolls-with-target-sum.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1155 {

namespace {

constexpr int kMod = 1'000'000'007;

int numRollsToTargetImpl(int n, int k, int target) {
  // Impossible sum range.
  if (target < n || target > n * k) {
    return 0;
  }

  // dp[s] = ways to reach sum s with the current number of dice.
  std::vector<int> dp(target + 1, 0);
  dp[0] = 1;  // 0 dice → sum 0 in 1 way.

  for (int dice = 1; dice <= n; ++dice) {
    std::vector<int> next(target + 1, 0);
    for (int face = 1; face <= k; ++face) {
      for (int s = face; s <= target; ++s) {
        next[s] = (next[s] + dp[s - face]) % kMod;
      }
    }
    dp = std::move(next);
  }

  return dp[target];
}

}  // namespace

NumberOfDiceRollsWithTargetSumSolution::NumberOfDiceRollsWithTargetSumSolution() {
  setMetaInfo({.id = 1155,
               .title = "Number of Dice Rolls With Target Sum",
               .url = "https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/"});

  registerStrategy({.name = "DP (1D rolling array)",
                    .expected = "Accepted",
                    .time_complexity = "O(n * k * target)",
                    .space_complexity = "O(target)",
                    .tags = {"Dynamic Programming"}},
                   numRollsToTargetImpl);
}

int NumberOfDiceRollsWithTargetSumSolution::numRollsToTarget(int n, int k, int target) {
  return getSolution()(n, k, target);
}

}  // namespace problem_1155
}  // namespace leetcode

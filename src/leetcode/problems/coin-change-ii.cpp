#include "leetcode/problems/coin-change-ii.h"

#include <algorithm>
#include <cstdint>
#include <limits>

namespace leetcode {
namespace problem_518 {
namespace {

int oneDimensionalDp(int amount, std::vector<int>& coins) {
  constexpr std::int64_t kLimit = std::numeric_limits<int>::max();
  std::vector<std::int64_t> dp(static_cast<std::size_t>(amount) + 1, 0);
  dp[0] = 1;

  for (int coin : coins) {
    if (coin > amount) continue;
    for (int value = coin; value <= amount; ++value) {
      dp[value] = std::min(kLimit, dp[value] + dp[value - coin]);
    }
  }
  return static_cast<int>(dp[amount]);
}

}  // namespace

CoinChangeIiSolution::CoinChangeIiSolution() {
  setMetaInfo({.id = 518,
               .title = "Coin Change II",
               .url = "https://leetcode.com/problems/coin-change-ii/"});
  registerStrategy({.name = "one_dimensional_dp",
                    .expected = "Accepted",
                    .time_complexity = "O(amount * coins)",
                    .space_complexity = "O(amount)",
                    .tags = {"Dynamic Programming", "Knapsack"}},
                   oneDimensionalDp);
}

int CoinChangeIiSolution::change(int amount, std::vector<int>& coins) {
  return getSolution()(amount, coins);
}

}  // namespace problem_518
}  // namespace leetcode

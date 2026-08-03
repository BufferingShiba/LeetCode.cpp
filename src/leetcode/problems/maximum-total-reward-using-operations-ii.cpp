#include "leetcode/problems/maximum-total-reward-using-operations-ii.h"

#include <algorithm>
#include <bitset>

namespace leetcode {
namespace problem_3181 {

namespace {

int maxTotalRewardImpl(std::vector<int>& rewardValues) {
  // 去重（相同值取一次即可，标记后 x >= value，同值再也无法选中）
  std::sort(rewardValues.begin(), rewardValues.end());
  rewardValues.erase(std::unique(rewardValues.begin(), rewardValues.end()),
                     rewardValues.end());

  // 每次转移要求 x < v 且 x += v，所以新 x = x+v > 2x，x 严格翻倍增长。
  // 最终 x < 2 * max(value) <= 2 * 50000 = 100000。
  const int MAX = 100001;
  std::bitset<MAX> allOnes;
  allOnes.set();

  std::bitset<MAX> dp;
  dp[0] = 1;

  for (int v : rewardValues) {
    if (v >= MAX) break;
    // lowMask = 低位 v 个 1（即所有 < v 的状态）。
    std::bitset<MAX> lowMask = allOnes >> (MAX - v);
    dp |= (dp & lowMask) << v;
  }

  // 找最大可达 total reward
  for (int x = MAX - 1; x >= 0; --x) {
    if (dp[x]) return x;
  }
  return 0;
}

}  // namespace

MaximumTotalRewardUsingOperationsIiSolution::
    MaximumTotalRewardUsingOperationsIiSolution() {
  setMetaInfo({.id = 3181,
               .title = "Maximum Total Reward Using Operations II",
               .url = "https://leetcode.com/problems/maximum-total-reward-using-operations-ii/"});
  registerStrategy(
      {"BitsetDP", "Accepted", "O(n * B / 64)", "O(B / 8)",
       {"Bitset", "Dynamic Programming", "Sorting"}},
      maxTotalRewardImpl);
}

int MaximumTotalRewardUsingOperationsIiSolution::maxTotalReward(
    std::vector<int>& rewardValues) {
  return getSolution()(rewardValues);
}

}  // namespace problem_3181
}  // namespace leetcode

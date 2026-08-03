
#include "leetcode/problems/taking-maximum-energy-from-the-mystic-dungeon.h"

namespace leetcode {
namespace problem_3147 {

// 反向 DP（后缀和）
// dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0)
// 即从 i 出发一路跳到末尾累积的能量。
// 从后往前遍历，所有索引的 dp 最大值即为答案。
// 时间复杂度: O(n), 空间复杂度: O(n)
static int solution1(vector<int>& energy, int k) {
  const int n = energy.size();
  vector<int> dp(n);
  int ans = INT_MIN;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
    ans = max(ans, dp[i]);
  }
  return ans;
}

TakingMaximumEnergyFromTheMysticDungeonSolution::
    TakingMaximumEnergyFromTheMysticDungeonSolution() {
  setMetaInfo({.id = 3147,
               .title = "Taking Maximum Energy From the Mystic Dungeon",
               .url = "https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon"});
  registerStrategy({.name = "Reverse DP (Suffix Sum)",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming"}},
                   solution1);
}

int TakingMaximumEnergyFromTheMysticDungeonSolution::maximumEnergy(
    vector<int>& energy, int k) {
  return getSolution()(energy, k);
}

}  // namespace problem_3147
}  // namespace leetcode


#include "leetcode/problems/minimum-number-of-coins-to-be-added.h"

namespace leetcode {
namespace problem_2952 {

// 贪心 + 区间覆盖扩展
// 维护 reach 表示当前已可覆盖 [1, reach]。排序后遍历硬币：
// - 若 c <= reach+1，则可无缝扩展 reach += c；
// - 否则说明存在缺口 reach+1，贪心添加硬币 reach+1，reach 变为 2*reach+1。
// 时间复杂度: O(n log n), 空间复杂度: O(log n)（排序栈）
static int solution1(std::vector<int>& coins, int target) {
  std::sort(coins.begin(), coins.end());
  long long reach = 0;  // 已覆盖区间上界
  int ans = 0;
  int i = 0;
  const int n = coins.size();
  while (reach < target) {
    if (i < n && coins[i] <= reach + 1) {
      reach += coins[i];
      ++i;
    } else {
      // 添加硬币 reach+1
      ++ans;
      reach = 2 * reach + 1;
    }
  }
  return ans;
}

MinimumNumberOfCoinsToBeAddedSolution::MinimumNumberOfCoinsToBeAddedSolution() {
  setMetaInfo({.id = 2952,
               .title = "Minimum Number of Coins to be Added",
               .url = "https://leetcode.com/problems/minimum-number-of-coins-to-be-added"});
  registerStrategy(
      {.name = "Greedy Interval Expansion",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(log n)",
       .tags = {"Greedy", "Sorting", "Interval"}},
      solution1);
}

int MinimumNumberOfCoinsToBeAddedSolution::minimumAddedCoins(
    std::vector<int>& coins, int target) {
  return getSolution()(coins, target);
}

}  // namespace problem_2952
}  // namespace leetcode

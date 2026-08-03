
#include "leetcode/problems/find-the-minimum-amount-of-time-to-brew-potions.h"

namespace leetcode {
namespace problem_3494 {

// 流水线贪心模拟
// skill[i] * mana[j] 为巫师 i 处理药剂 j 的耗时。
// 设 prefix[i] = sum_{k<=i} skill[k]。对药剂 j，若其在巫师 0 开始的时刻为 start，
// 则巫师 i 完成该瓶的时刻为 start + mana[j] * prefix[i]，
// 而巫师 i（i>=1）开始该瓶的时刻为 start + mana[j] * prefix[i-1]。
//
// 关键约束「无等待传递」：巫师 i 开始处理药剂 j 的时刻，必须不早于巫师 i
// 完成上一瓶药剂 j-1 的时刻 end[i]（否则巫师 i 无法立即接手）。即
//   start + mana[j] * prefix[i-1] >= end[i]
//   => start >= end[i] - mana[j] * prefix[i-1]
// 取所有巫师下界的最大值即为每瓶的最早可行开始时刻。
//
// 时间复杂度: O(n*m), 空间复杂度: O(n)
static long long solution1(vector<int>& skill, vector<int>& mana) {
  const int n = skill.size();   // 巫师数
  const int m = mana.size();    // 药剂数

  vector<long long> prefix(n);
  long long acc = 0;
  for (int i = 0; i < n; ++i) {
    acc += skill[i];
    prefix[i] = acc;
  }

  vector<long long> end(n, 0);  // end[i] = 巫师 i 完成已排药剂的最早时刻

  for (int j = 0; j < m; ++j) {
    long long start = 0;
    for (int i = 0; i < n; ++i) {
      // 巫师 i 开始本瓶的时刻 = start + mana[j]*prefix[i-1]
      long long prevPrefix = (i == 0) ? 0 : prefix[i - 1];
      long long need = end[i] - (long long)mana[j] * prevPrefix;
      if (need > start) start = need;
    }
    for (int i = 0; i < n; ++i) {
      end[i] = start + (long long)mana[j] * prefix[i];
    }
  }

  return end[n - 1];
}

FindTheMinimumAmountOfTimeToBrewPotionsSolution::
    FindTheMinimumAmountOfTimeToBrewPotionsSolution() {
  setMetaInfo({.id = 3494,
               .title = "Find the Minimum Amount of Time to Brew Potions",
               .url = "https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions"});
  registerStrategy(
      {.name = "Pipeline Greedy Simulation",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Simulation", "Prefix Sum"}},
      solution1);
}

long long FindTheMinimumAmountOfTimeToBrewPotionsSolution::minTime(
    vector<int>& skill, vector<int>& mana) {
  return getSolution()(skill, mana);
}

}  // namespace problem_3494
}  // namespace leetcode

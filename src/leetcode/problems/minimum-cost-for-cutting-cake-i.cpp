
#include "leetcode/problems/minimum-cost-for-cutting-cake-i.h"

namespace leetcode {
namespace problem_3218 {

// 贪心：按切割成本从大到小依次执行
// 关键观察：一次切割的实际代价 = 段成本 * (当前反方向已切刀数 + 1)。
// 因为每次沿某条线切割时，它要贯穿当前所有被切开的块。切一条水平线时，
// 它穿过的块数 = 已有的垂直切口数 + 1（反之亦然）。
// 更大的成本应尽早执行（此时反向切口少，乘的系数小），
// 交换论证可证明该贪心最优。
// 时间复杂度: O((m+n) log(m+n)), 空间复杂度: O(1)
static int solution1(int m, int n, std::vector<int>& horizontalCut,
                     std::vector<int>& verticalCut) {
  std::sort(horizontalCut.begin(), horizontalCut.end());
  std::sort(verticalCut.begin(), verticalCut.end());

  int h = (int)horizontalCut.size();
  int v = (int)verticalCut.size();
  int hi = h - 1, vi = v - 1;
  int hCount = 0, vCount = 0;  // 已切水平、垂直线数
  long long total = 0;

  while (hi >= 0 || vi >= 0) {
    if (hi >= 0 && vi >= 0) {
      // 取成本更大的一刀先切
      if (horizontalCut[hi] > verticalCut[vi]) {
        total += 1LL * horizontalCut[hi] * (vCount + 1);
        --hi;
        ++hCount;
      } else {
        total += 1LL * verticalCut[vi] * (hCount + 1);
        --vi;
        ++vCount;
      }
    } else if (hi >= 0) {
      total += 1LL * horizontalCut[hi] * (vCount + 1);
      --hi;
      ++hCount;
    } else {
      total += 1LL * verticalCut[vi] * (hCount + 1);
      --vi;
      ++vCount;
    }
  }

  return (int)total;
}

MinimumCostForCuttingCakeISolution::MinimumCostForCuttingCakeISolution() {
  setMetaInfo({.id = 3218,
               .title = "Minimum Cost for Cutting Cake I",
               .url = "https://leetcode.com/problems/minimum-cost-for-cutting-cake-i"});
  registerStrategy(
      {.name = "Greedy (Descending Cost)",
       .expected = "Accepted",
       .time_complexity = "O((m+n) log(m+n))",
       .space_complexity = "O(1)",
       .tags = {"Greedy", "Sorting"},
       .notes =
           "每次取成本更大的线段先切，因为它贯穿的块更少（反向切口少），"
           "从而乘以更小的系数。交换论证保证贪心最优。"},
      solution1);
}

int MinimumCostForCuttingCakeISolution::minimumCost(
    int m, int n, std::vector<int>& horizontalCut,
    std::vector<int>& verticalCut) {
  return getSolution()(m, n, horizontalCut, verticalCut);
}

}  // namespace problem_3218
}  // namespace leetcode

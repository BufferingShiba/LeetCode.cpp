
#include "leetcode/problems/count-total-number-of-colored-cells.h"

namespace leetcode {
namespace problem_2579 {

// 数学公式：第 n 分钟时共着色 1 + 4*(1+2+...+(n-1)) = 2n² - 2n + 1 个格子。
// 推导：每一步向外扩展一圈，第 k 层（k>=1，即第 k+1 分钟）新增 4*k 个格子。
// 时间复杂度: O(1), 空间复杂度: O(1)
static long long solution1(int n) {
  long long m = n;
  return 2LL * m * m - 2LL * m + 1LL;
}

CountTotalNumberOfColoredCellsSolution::CountTotalNumberOfColoredCellsSolution() {
  setMetaInfo({.id = 2579,
               .title = "Count Total Number of Colored Cells",
               .url = "https://leetcode.com/problems/count-total-number-of-colored-cells"});
  registerStrategy(
      {.name = "Closed Form",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"},
       .notes = "coloredCells(n) = 1 + 4*(1+2+...+(n-1)) = 2n² - 2n + 1"},
      solution1);
}

long long CountTotalNumberOfColoredCellsSolution::coloredCells(int n) {
  return getSolution()(n);
}

}  // namespace problem_2579
}  // namespace leetcode

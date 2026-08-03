#include "leetcode/problems/find-the-width-of-columns-of-a-grid.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_2639 {

namespace {

std::vector<int> findColumnWidthImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  std::vector<int> ans(n, 0);
  for (int col = 0; col < n; ++col) {
    for (int row = 0; row < m; ++row) {
      int len = static_cast<int>(std::to_string(grid[row][col]).size());
      ans[col] = std::max(ans[col], len);
    }
  }
  return ans;
}

}  // namespace

std::vector<int> FindTheWidthOfColumnsOfAGrid::findColumnWidth(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

FindTheWidthOfColumnsOfAGridSolution::FindTheWidthOfColumnsOfAGridSolution() {
  setMetaInfo({.id = 2639,
               .title = "Find the Width of Columns of a Grid",
               .url = "https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/"});
  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Matrix"}},
      findColumnWidthImpl);
}

}  // namespace problem_2639
}  // namespace leetcode

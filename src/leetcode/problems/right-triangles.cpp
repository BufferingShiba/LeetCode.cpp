#include "leetcode/problems/right-triangles.h"

namespace leetcode {
namespace problem_3128 {

static long long numberOfRightTrianglesImpl(std::vector<std::vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();

  std::vector<int> rowCnt(m, 0);
  std::vector<int> colCnt(n, 0);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        rowCnt[i]++;
        colCnt[j]++;
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        ans += static_cast<long long>(rowCnt[i] - 1) * (colCnt[j] - 1);
      }
    }
  }

  return ans;
}

RightTrianglesSolution::RightTrianglesSolution() {
  setMetaInfo({.id = 3128, .title = "Right Triangles",
               .url = "https://leetcode.com/problems/right-triangles/"});
  registerStrategy(
      {.name = "Counting",
       .expected = "Accepted",
       .time_complexity = "O(m * n)",
       .space_complexity = "O(m + n)",
       .tags = {"Array", "Hash Table", "Math", "Combinatorics", "Counting"}},
      numberOfRightTrianglesImpl);
}

long long RightTrianglesSolution::numberOfRightTriangles(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3128
}  // namespace leetcode

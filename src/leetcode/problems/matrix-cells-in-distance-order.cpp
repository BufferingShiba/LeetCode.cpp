#include "leetcode/problems/matrix-cells-in-distance-order.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_1030 {

static std::vector<std::vector<int>> allCellsDistOrderBFS(int rows, int cols,
                                                           int rCenter,
                                                           int cCenter) {
  std::vector<std::vector<int>> result;
  result.reserve(rows * cols);

  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
  std::queue<std::pair<int, int>> q;
  q.push({rCenter, cCenter});
  visited[rCenter][cCenter] = true;

  const int dirs[5] = {0, 1, 0, -1, 0};

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    result.push_back({r, c});

    for (int d = 0; d < 4; ++d) {
      int nr = r + dirs[d];
      int nc = c + dirs[d + 1];
      if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }

  return result;
}

MatrixCellsInDistanceOrderSolution::MatrixCellsInDistanceOrderSolution() {
  setMetaInfo({.id = 1030,
               .title = "Matrix Cells in Distance Order",
               .url = "https://leetcode.com/problems/matrix-cells-in-distance-order/"});
  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(rows * cols)",
       .space_complexity = "O(rows * cols)",
       .tags = {"Array", "Math", "Geometry", "Sorting", "Matrix"}},
      allCellsDistOrderBFS);
}

std::vector<std::vector<int>> MatrixCellsInDistanceOrderSolution::allCellsDistOrder(
    int rows, int cols, int rCenter, int cCenter) {
  return getSolution()(rows, cols, rCenter, cCenter);
}

}  // namespace problem_1030
}  // namespace leetcode

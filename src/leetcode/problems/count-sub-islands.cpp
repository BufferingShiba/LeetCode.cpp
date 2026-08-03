#include "leetcode/problems/count-sub-islands.h"

namespace leetcode {
namespace problem_1905 {

namespace {
const int kDirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
}

// 对 grid2 中的一个岛屿做洪泛，判断其所有格子是否在 grid1 中均为陆。
// 遍历时原地把 grid2 访问过的陆置 0，避免重复计数且无需额外 visited 数组。
// 使用显式栈而不是递归，避免 500*500 的细长/连通岛屿耗尽调用栈。
static bool dfsIsSub(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
                     int r, int c, int m, int n) {
  bool isSub = true;
  vector<pair<int, int>> pending;
  pending.emplace_back(r, c);
  grid2[r][c] = 0;

  while (!pending.empty()) {
    auto [currentR, currentC] = pending.back();
    pending.pop_back();
    isSub = isSub && (grid1[currentR][currentC] == 1);

    for (const auto& d : kDirs) {
      int nextR = currentR + d[0];
      int nextC = currentC + d[1];
      if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n &&
          grid2[nextR][nextC] == 1) {
        grid2[nextR][nextC] = 0;
        pending.emplace_back(nextR, nextC);
      }
    }
  }
  return isSub;
}

static int solution1(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  const int m = static_cast<int>(grid1.size());
  const int n = m == 0 ? 0 : static_cast<int>(grid1[0].size());
  int count = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (grid2[r][c] == 1 && dfsIsSub(grid1, grid2, r, c, m, n)) {
        ++count;
      }
    }
  }
  return count;
}

CountSubIslandsSolution::CountSubIslandsSolution() {
  setMetaInfo({
      .id = 1905,
      .title = "Count Sub Islands",
      .url = "https://leetcode.com/problems/count-sub-islands"
  });
  registerStrategy(
      {.name = "DFS Flood Fill",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n) worst for recursion",
       .tags = {"DFS", "BFS", "Graph", "Matrix"}},
      solution1);
}

int CountSubIslandsSolution::countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  return getSolution()(grid1, grid2);
}

}  // namespace problem_1905
}  // namespace leetcode

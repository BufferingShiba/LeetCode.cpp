#include "leetcode/problems/regions-cut-by-slashes.h"

#include <vector>
#include <functional>

namespace leetcode {
namespace problem_959 {
namespace {

// Scale each cell into a 3x3 grid; slashes become solid diagonal walls
// made of 3 connected pixels. Then count the connected components formed by
// the empty ('0') pixels via flood fill. Each component == one region.
int regionsBySlashesImpl(std::vector<std::string>& grid) {
  const int n = static_cast<int>(grid.size());
  const int m = n * 3;
  std::vector<std::vector<int>> wall(
      m, std::vector<int>(m, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch = grid[i][j];
      if (ch == '/') {
        // Diagonal from top-right to bottom-left inside the 3x3 block.
        wall[i * 3 + 0][j * 3 + 2] = 1;
        wall[i * 3 + 1][j * 3 + 1] = 1;
        wall[i * 3 + 2][j * 3 + 0] = 1;
      } else if (ch == '\\') {
        // Diagonal from top-left to bottom-right inside the 3x3 block.
        wall[i * 3 + 0][j * 3 + 0] = 1;
        wall[i * 3 + 1][j * 3 + 1] = 1;
        wall[i * 3 + 2][j * 3 + 2] = 1;
      }
      // ' ' leaves the whole block empty.
    }
  }

  std::vector<std::vector<int>> visited(
      m, std::vector<int>(m, 0));
  const std::vector<std::pair<int, int>> dirs = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  std::function<void(int, int)> dfs = [&](int r, int c) {
    visited[r][c] = 1;
    for (const auto& d : dirs) {
      int nr = r + d.first, nc = c + d.second;
      if (nr < 0 || nr >= m || nc < 0 || nc >= m) continue;
      if (visited[nr][nc] || wall[nr][nc]) continue;
      dfs(nr, nc);
    }
  };

  int regions = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < m; ++c) {
      if (!visited[r][c] && !wall[r][c]) {
        ++regions;
        dfs(r, c);
      }
    }
  }
  return regions;
}

}  // namespace

RegionsCutBySlashesSolution::RegionsCutBySlashesSolution() {
  setMetaInfo({.id = 959,
               .title = "Regions Cut By Slashes",
               .url = "https://leetcode.com/problems/regions-cut-by-slashes/"});
  registerStrategy(
      {.name = "ScaleAndFloodFill",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Array",
                "Hash Table", "Union-Find", "Matrix"}},
      regionsBySlashesImpl);
}

int RegionsCutBySlashesSolution::regionsBySlashes(std::vector<std::string>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_959
}  // namespace leetcode

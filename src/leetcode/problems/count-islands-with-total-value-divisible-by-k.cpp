#include "leetcode/problems/count-islands-with-total-value-divisible-by-k.h"

#include <functional>

namespace leetcode {
namespace problem_3619 {

static const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

static long long dfs(vector<vector<int>>& grid, int r, int c) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  long long sum = grid[r][c];
  grid[r][c] = 0;  // mark visited
  for (int d = 0; d < 4; ++d) {
    int nr = r + dirs[d][0];
    int nc = c + dirs[d][1];
    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
    if (grid[nr][nc] > 0) {
      sum += dfs(grid, nr, nc);
    }
  }
  return sum;
}

static int solution1(vector<vector<int>>& grid, int k) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());
  int count = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] > 0) {
        long long sum = dfs(grid, i, j);
        if (sum % k == 0) {
          ++count;
        }
      }
    }
  }
  return count;
}

CountIslandsWithTotalValueDivisibleByKSolution::CountIslandsWithTotalValueDivisibleByKSolution() {
  setMetaInfo({
      .id = 3619,
      .title = "Count Islands With Total Value Divisible by K",
      .url = "https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k"
  });
  registerStrategy({.name = "DFS Connected Components"}, solution1);
}

int CountIslandsWithTotalValueDivisibleByKSolution::countIslands(vector<vector<int>>& grid, int k) {
  return getSolution()(grid, k);
}

}  // namespace problem_3619
}  // namespace leetcode

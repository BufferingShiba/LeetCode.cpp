#include "leetcode/problems/longest-increasing-path-in-a-matrix.h"

#include <algorithm>

namespace leetcode {
namespace problem_329 {
namespace {

int longestIncreasingPathImpl(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty() || matrix[0].empty()) {
    return 0;
  }
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());

  std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
  const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  std::function<int(int, int)> dfs = [&](int r, int c) -> int {
    if (memo[r][c] != 0) {
      return memo[r][c];
    }
    int best = 1;
    for (const auto& d : dirs) {
      const int nr = r + d[0];
      const int nc = c + d[1];
      if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
          matrix[nr][nc] > matrix[r][c]) {
        best = std::max(best, 1 + dfs(nr, nc));
      }
    }
    memo[r][c] = best;
    return best;
  };

  int answer = 0;
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      answer = std::max(answer, dfs(r, c));
    }
  }
  return answer;
}

}  // namespace

LongestIncreasingPathInAMatrixSolution::LongestIncreasingPathInAMatrixSolution() {
  setMetaInfo({.id = 329,
               .title = "Longest Increasing Path in a Matrix",
               .url =
                   "https://leetcode.com/problems/longest-increasing-path-in-a-matrix/"});
  registerStrategy({.name = "DFS+Memoization",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m*n)",
                    .tags = {"Depth-First Search", "Memoization", "Dynamic Programming"},
                    .notes =
                        "Each state computed once; strictly increasing edges form a DAG."},
                   longestIncreasingPathImpl);
}

int LongestIncreasingPathInAMatrixSolution::longestIncreasingPath(
    std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_329
}  // namespace leetcode

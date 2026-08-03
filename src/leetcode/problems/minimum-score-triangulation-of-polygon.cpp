#include "leetcode/problems/minimum-score-triangulation-of-polygon.h"

#include <algorithm>
#include <climits>
#include <functional>

namespace leetcode {
namespace problem_1039 {

// Interval DP (top-down with memoization).
// dp[i][j] = min total score to triangulate the sub-polygon formed by vertices
// i..j (inclusive). For a triangle (j - i == 2) the only choice is k = i + 1.
// Transition: pick k in (i, j) as the third vertex of triangle (i, k, j), then
// dp[i][j] = min(dp[i][k] + dp[k][j] + values[i]*values[k]*values[j]).
static int solution1(vector<int>& values) {
  int n = static_cast<int>(values.size());
  std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));

  std::function<int(int, int)> dfs = [&](int i, int j) -> int {
    if (j - i < 2) return 0;  // fewer than 3 vertices: no triangle
    if (memo[i][j] != -1) return memo[i][j];
    int best = INT_MAX;
    for (int k = i + 1; k < j; ++k) {
      best = std::min(best, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
    }
    memo[i][j] = best;
    return best;
  };

  return dfs(0, n - 1);
}

MinimumScoreTriangulationOfPolygonSolution::MinimumScoreTriangulationOfPolygonSolution() {
  setMetaInfo({
      .id = 1039,
      .title = "Minimum Score Triangulation of Polygon",
      .url = "https://leetcode.com/problems/minimum-score-triangulation-of-polygon"
  });
  registerStrategy({.name = "Interval DP",
                    .time_complexity = "O(n^3)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Dynamic Programming"}},
                   solution1);
}

int MinimumScoreTriangulationOfPolygonSolution::minScoreTriangulation(vector<int>& values) {
  return getSolution()(values);
}

}  // namespace problem_1039
}  // namespace leetcode

#include "leetcode/problems/out-of-boundary-paths.h"

#include <vector>

namespace leetcode {
namespace problem_576 {

namespace {

constexpr int kMod = 1'000'000'007;

int findPathsImpl(int m, int n, int maxMove, int startRow, int startColumn,
                  std::vector<std::vector<std::vector<int>>>& memo) {
  if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n) {
    return 1;
  }
  if (maxMove == 0) {
    return 0;
  }
  if (memo[startRow][startColumn][maxMove] != -1) {
    return memo[startRow][startColumn][maxMove];
  }

  long long total = 0;
  total += findPathsImpl(m, n, maxMove - 1, startRow - 1, startColumn, memo);
  total += findPathsImpl(m, n, maxMove - 1, startRow + 1, startColumn, memo);
  total += findPathsImpl(m, n, maxMove - 1, startRow, startColumn - 1, memo);
  total += findPathsImpl(m, n, maxMove - 1, startRow, startColumn + 1, memo);

  return memo[startRow][startColumn][maxMove] =
             static_cast<int>(total % kMod);
}

}  // namespace

OutOfBoundaryPathsSolution::OutOfBoundaryPathsSolution() {
  setMetaInfo({.id = 576,
               .title = "Out of Boundary Paths",
               .url = "https://leetcode.com/problems/out-of-boundary-paths/"});

  registerStrategy(
      {.name = "Top-Down DP (Memoization)",
       .time_complexity = "O(m * n * maxMove)",
       .space_complexity = "O(m * n * maxMove)",
       .tags = {"Dynamic Programming", "Memoization"}},
      [](int m, int n, int maxMove, int startRow, int startColumn) {
        // memo[i][j][k] = paths from (i,j) with k remaining moves
        // -1 means uncomputed
        std::vector<std::vector<std::vector<int>>> memo(
            m, std::vector<std::vector<int>>(
                   n, std::vector<int>(maxMove + 1, -1)));
        return findPathsImpl(m, n, maxMove, startRow, startColumn, memo);
      });
}

int OutOfBoundaryPathsSolution::findPaths(int m, int n, int maxMove,
                                          int startRow, int startColumn) {
  return getSolution()(m, n, maxMove, startRow, startColumn);
}

}  // namespace problem_576
}  // namespace leetcode

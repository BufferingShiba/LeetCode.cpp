#include "leetcode/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix.h"

#include <queue>
#include <utility>

namespace leetcode::problem_1284 {

namespace {

constexpr int kDirRow[4] = {-1, 1, 0, 0};
constexpr int kDirCol[4] = {0, 0, -1, 1};

// Encodes the matrix into a bitmask. Cell (i,j) -> bit (i * n + j).
int encode(const std::vector<std::vector<int>>& mat) {
  int m = static_cast<int>(mat.size());
  int n = static_cast<int>(mat[0].size());
  int mask = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 1) mask |= (1 << (i * n + j));
    }
  }
  return mask;
}

// BFS from the startMask to the all-zero mask.
int minFlipsImpl(std::vector<std::vector<int>>& mat) {
  int m = static_cast<int>(mat.size());
  int n = static_cast<int>(mat[0].size());
  int startMask = encode(mat);
  if (startMask == 0) return 0;
  constexpr int kMaxMask = 1 << 9;
  int dist[kMaxMask];
  for (int i = 0; i < kMaxMask; ++i) dist[i] = -1;
  std::queue<int> q;
  dist[startMask] = 0;
  q.push(startMask);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int curDepth = dist[cur];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // Flipping cell (i,j) toggles itself and orthogonally adjacent cells.
        int next = cur;
        next ^= (1 << (i * n + j));
        for (int d = 0; d < 4; ++d) {
          int ni = i + kDirRow[d];
          int nj = j + kDirCol[d];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            next ^= (1 << (ni * n + nj));
          }
        }
        if (next == 0) return curDepth + 1;
        if (dist[next] == -1) {
          dist[next] = curDepth + 1;
          q.push(next);
        }
      }
    }
  }
  return -1;
}

}  // namespace

MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution::
    MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution() {
  setMetaInfo({.id = 1284,
               .title = "Minimum Number of Flips to Convert Binary Matrix to Zero Matrix",
               .url = "https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/"});
  registerStrategy({.name = "BFS on bitmask states",
                    .expected = "Accepted",
                    .time_complexity = "O(2^(m*n) * m * n)",
                    .space_complexity = "O(2^(m*n))",
                    .tags = {"Breadth-First Search", "Bit Manipulation", "Matrix"}},
                   minFlipsImpl);
}

int MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution::minFlips(
    std::vector<std::vector<int>>& mat) {
  return getSolution()(mat);
}

}  // namespace leetcode::problem_1284

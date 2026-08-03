#include "leetcode/problems/length-of-longest-v-shaped-diagonal-segment.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_3459 {

namespace {

constexpr int kDi[] = {1, 1, -1, -1};
constexpr int kDj[] = {1, -1, -1, 1};

}  // namespace

int LengthOfLongestVShapedDiagonalSegmentSolution::lenOfVDiagonal(
    std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  const int m = static_cast<int>(grid[0].size());

  std::vector<std::vector<std::array<std::array<int, 2>, 4>>> F(
      n, std::vector<std::array<std::array<int, 2>, 4>>(m));

  for (int d = 0; d < 4; ++d) {
    const int di = kDi[d];
    const int dj = kDj[d];
    for (int i = (di > 0 ? n - 1 : 0); di > 0 ? i >= 0 : i < n;
         i += (di > 0 ? -1 : 1)) {
      for (int j = (dj > 0 ? m - 1 : 0); dj > 0 ? j >= 0 : j < m;
           j += (dj > 0 ? -1 : 1)) {
        const int ni = i + di;
        const int nj = j + dj;
        const bool hasNext = ni >= 0 && ni < n && nj >= 0 && nj < m;
        for (int p = 0; p < 2; ++p) {
          const int pv = (p == 0) ? 0 : 2;
          int len = 0;
          if (grid[i][j] == pv) {
            len = 1;
            if (hasNext) len += F[ni][nj][d][1 - p];
          }
          F[i][j][d][p] = len;
        }
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] != 1) continue;
      for (int d = 0; d < 4; ++d) {
        const int di = kDi[d];
        const int dj = kDj[d];
        const int sf1 = i + di, sf2 = j + dj;
        int arm = 1;
        if (sf1 >= 0 && sf1 < n && sf2 >= 0 && sf2 < m) {
          arm += F[sf1][sf2][d][1];
        }
        const int d2 = (d + 1) % 4;
        const int rd = kDi[d2], rdj = kDj[d2];
        int ci = i, cj = j;
        for (int k = 0; k < arm; ++k) {
          const int ti = ci + rd, tj = cj + rdj;
          int leg2 = 0;
          if (ti >= 0 && ti < n && tj >= 0 && tj < m) {
            const int phase = ((k & 1) == 0) ? 1 : 0;
            leg2 = F[ti][tj][d2][phase];
          }
          int total = (k + 1) + leg2;
          if (total > ans) ans = total;
          ci += di;
          cj += dj;
        }
      }
    }
  }

  return ans;
}

}  // namespace problem_3459
}  // namespace leetcode

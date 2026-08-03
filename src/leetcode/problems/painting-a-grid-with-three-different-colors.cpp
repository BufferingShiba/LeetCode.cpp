#include "leetcode/problems/painting-a-grid-with-three-different-colors.h"

#include <cstdint>

namespace leetcode {
namespace problem_1931 {

namespace {

const int kMod = 1000000007;

// Enumerate all valid column colorings and run a column-by-column DP.
// A valid column is a sequence of m colors (0,1,2) where vertically
// adjacent cells differ. Columns a and b are compatible if horizontal
// adjacent cells (same row) differ.
int colorTheGridImpl(int m, int n) {
  // Generate all valid columns.
  std::vector<int> columns;
  int total = 1;
  for (int i = 0; i < m; ++i) total *= 3;
  for (int mask = 0; mask < total; ++mask) {
    int x = mask;
    bool valid = true;
    int prev = -1;
    for (int r = 0; r < m; ++r) {
      int c = x % 3;
      x /= 3;
      if (prev == c) {
        valid = false;
        break;
      }
      prev = c;
    }
    if (valid) columns.push_back(mask);
  }

  int s = static_cast<int>(columns.size());

  // compatible[i][j]: column i and j can be placed adjacently.
  std::vector<std::vector<bool>> compatible(s, std::vector<bool>(s, true));
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      int a = columns[i];
      int b = columns[j];
      bool ok = true;
      for (int r = 0; r < m; ++r) {
        if (a % 3 == b % 3) {
          ok = false;
          break;
        }
        a /= 3;
        b /= 3;
      }
      compatible[i][j] = ok;
    }
  }

  // dp over columns.
  std::vector<int> dp(s, 1);  // single column: each valid column is 1 way.
  std::vector<int> next(s, 0);
  for (int col = 1; col < n; ++col) {
    for (int j = 0; j < s; ++j) {
      long long sum = 0;
      for (int i = 0; i < s; ++i) {
        if (compatible[i][j]) sum += dp[i];
      }
      next[j] = static_cast<int>(sum % kMod);
    }
    dp.swap(next);
    std::fill(next.begin(), next.end(), 0);
  }

  long long ans = 0;
  for (int i = 0; i < s; ++i) ans += dp[i];
  return static_cast<int>(ans % kMod);
}

}  // namespace

PaintingAGridWithThreeDifferentColorsSolution::
    PaintingAGridWithThreeDifferentColorsSolution() {
  setMetaInfo({.id = 1931,
               .title = "Painting a Grid With Three Different Colors",
               .url = "https://leetcode.com/problems/painting-a-grid-with-three-different-colors/"});
  registerStrategy(
      {.name = "column-state-compression-dp",
       .expected = "Accepted",
       .time_complexity = "O(n * S^2)",
       .space_complexity = "O(S^2)",
       .tags = {"Dynamic Programming", "Bitmask", "Matrix"}},
      colorTheGridImpl);
}

int PaintingAGridWithThreeDifferentColorsSolution::colorTheGrid(int m,
                                                                int n) {
  return getSolution()(m, n);
}

}  // namespace problem_1931
}  // namespace leetcode

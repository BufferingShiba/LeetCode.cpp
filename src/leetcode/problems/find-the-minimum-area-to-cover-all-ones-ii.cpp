#include "leetcode/problems/find-the-minimum-area-to-cover-all-ones-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3197 {
namespace {

// Much larger than any real answer (max real is 3 * 900 = 2700), but small
// enough that a few additions of kInf never overflow int.
constexpr int kInf = 1000000;

// Bounding-box area of all 1's in sub-rectangle [r1..r2] x [c1..c2].
int areaOf(const std::vector<std::vector<int>>& grid, int r1, int c1, int r2,
           int c2) {
  int minR = r2 + 1, maxR = r1 - 1, minC = c2 + 1, maxC = c1 - 1;
  bool found = false;
  for (int r = r1; r <= r2; ++r) {
    for (int c = c1; c <= c2; ++c) {
      if (grid[r][c] == 1) {
        found = true;
        minR = std::min(minR, r);
        maxR = std::max(maxR, r);
        minC = std::min(minC, c);
        maxC = std::max(maxC, c);
      }
    }
  }
  if (!found) return kInf;
  return (maxR - minR + 1) * (maxC - minC + 1);
}

// Minimum area to cover all 1's in sub-rectangle with exactly k=2 rectangles.
int twoMin(const std::vector<std::vector<int>>& grid, int r1, int c1, int r2,
           int c2) {
  int best = kInf;
  // Horizontal split.
  for (int r = r1; r < r2; ++r) {
    int a = areaOf(grid, r1, c1, r, c2);
    int b = areaOf(grid, r + 1, c1, r2, c2);
    best = std::min(best, a + b);
  }
  // Vertical split.
  for (int c = c1; c < c2; ++c) {
    int a = areaOf(grid, r1, c1, r2, c);
    int b = areaOf(grid, r1, c + 1, r2, c2);
    best = std::min(best, a + b);
  }
  return best;
}

int minimumSumImpl(std::vector<std::vector<int>>& grid) {
  const int rows = static_cast<int>(grid.size());
  const int cols = static_cast<int>(grid[0].size());

  int best = kInf;

  // Split into one region (two rectangles) + one region (one rectangle);
  // horizontal cut.
  for (int r = 0; r < rows - 1; ++r) {
    best = std::min(best, twoMin(grid, 0, 0, r, cols - 1) +
                              areaOf(grid, r + 1, 0, rows - 1, cols - 1));
    best = std::min(best, areaOf(grid, 0, 0, r, cols - 1) +
                              twoMin(grid, r + 1, 0, rows - 1, cols - 1));
  }

  // Vertical cut.
  for (int c = 0; c < cols - 1; ++c) {
    best = std::min(best, twoMin(grid, 0, 0, rows - 1, c) +
                              areaOf(grid, 0, c + 1, rows - 1, cols - 1));
    best = std::min(best, areaOf(grid, 0, 0, rows - 1, c) +
                              twoMin(grid, 0, c + 1, rows - 1, cols - 1));
  }

  // Three horizontal strips.
  for (int r1_ = 0; r1_ < rows - 2; ++r1_) {
    for (int r2_ = r1_ + 1; r2_ < rows - 1; ++r2_) {
      best = std::min(best, areaOf(grid, 0, 0, r1_, cols - 1) +
                                areaOf(grid, r1_ + 1, 0, r2_, cols - 1) +
                                areaOf(grid, r2_ + 1, 0, rows - 1, cols - 1));
    }
  }

  // Three vertical strips.
  for (int c1_ = 0; c1_ < cols - 2; ++c1_) {
    for (int c2_ = c1_ + 1; c2_ < cols - 1; ++c2_) {
      best = std::min(best, areaOf(grid, 0, 0, rows - 1, c1_) +
                                areaOf(grid, 0, c1_ + 1, rows - 1, c2_) +
                                areaOf(grid, 0, c2_ + 1, rows - 1, cols - 1));
    }
  }

  return best;
}

}  // namespace

FindTheMinimumAreaToCoverAllOnesIiSolution::
    FindTheMinimumAreaToCoverAllOnesIiSolution() {
  setMetaInfo({.id = 3197,
               .title = "Find the Minimum Area to Cover All Ones II",
               .url = "https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/"});
  registerStrategy(
      {.name = "EnumerateCuts",
       .expected = "Accepted",
       .time_complexity = "O(n^4)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Matrix", "Enumeration"}},
      minimumSumImpl);
}

int FindTheMinimumAreaToCoverAllOnesIiSolution::minimumSum(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_3197
}  // namespace leetcode

#include "leetcode/problems/spiral-matrix-iii.h"

namespace leetcode {
namespace problem_885 {

static vector<vector<int>> solution1(int rows, int cols, int rStart, int cStart) {
  // Clockwise spiral walk: right, down, left, up, with step length growing
  // by 1 every two direction changes.
  static const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  vector<vector<int>> result;
  result.reserve(rows * cols);

  int r = rStart, c = cStart;
  result.push_back({r, c});

  int step = 1;   // current step length
  int dir = 0;    // direction index, start facing east
  while (result.size() < static_cast<size_t>(rows) * cols) {
    for (int k = 0; k < 2; ++k) {       // each step length used twice (two directions)
      for (int i = 0; i < step; ++i) {
        r += dirs[dir][0];
        c += dirs[dir][1];
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
          result.push_back({r, c});
        }
      }
      dir = (dir + 1) % 4;
    }
    ++step;
  }

  return result;
}

SpiralMatrixIiiSolution::SpiralMatrixIiiSolution() {
  setMetaInfo({
      .id = 885,
      .title = "Spiral Matrix III",
      .url = "https://leetcode.com/problems/spiral-matrix-iii"
  });
  registerStrategy({.name = "Spiral Walk", .time_complexity = "O(rows*cols)",
                    .space_complexity = "O(rows*cols)", .tags = {"Array", "Matrix", "Simulation"}},
                   solution1);
}

vector<vector<int>> SpiralMatrixIiiSolution::spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
  return getSolution()(rows, cols, rStart, cStart);
}

}  // namespace problem_885
}  // namespace leetcode

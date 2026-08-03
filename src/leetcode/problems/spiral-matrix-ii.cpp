#include "leetcode/problems/spiral-matrix-ii.h"

namespace leetcode {
namespace problem_59 {

static std::vector<std::vector<int>> generateMatrixImpl(int n) {
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
  int top = 0, bottom = n - 1, left = 0, right = n - 1;
  int num = 1;

  while (top <= bottom && left <= right) {
    // 从左到右
    for (int col = left; col <= right; ++col) {
      matrix[top][col] = num++;
    }
    ++top;

    // 从上到下
    for (int row = top; row <= bottom; ++row) {
      matrix[row][right] = num++;
    }
    --right;

    // 从右到左（需要检查 top <= bottom，防止重复填充）
    if (top <= bottom) {
      for (int col = right; col >= left; --col) {
        matrix[bottom][col] = num++;
      }
      --bottom;
    }

    // 从下到上（需要检查 left <= right）
    if (left <= right) {
      for (int row = bottom; row >= top; --row) {
        matrix[row][left] = num++;
      }
      ++left;
    }
  }

  return matrix;
}

SpiralMatrixIiSolution::SpiralMatrixIiSolution() {
  setMetaInfo({.id = 59,
               .title = "Spiral Matrix II",
               .url = "https://leetcode.com/problems/spiral-matrix-ii/"});
  registerStrategy(
      {.name = "SimulationBoundary",
       .expected = "Accepted",
       .time_complexity = "O(n²)",
       .space_complexity = "O(n²)",
       .tags = {"Array", "Matrix", "Simulation"}},
      generateMatrixImpl);
}

std::vector<std::vector<int>> SpiralMatrixIiSolution::generateMatrix(int n) {
  return getSolution()(n);
}

}  // namespace problem_59
}  // namespace leetcode

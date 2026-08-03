#include "leetcode/problems/projection-area-of-3d-shapes.h"

namespace leetcode::problem_883 {

namespace {

int projectionAreaImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  int xy = 0;  // top view: every non-zero cell
  int yz = 0;  // front view: max per row
  int zx = 0;  // side view: max per column
  for (int i = 0; i < n; ++i) {
    int rowMax = 0;
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] > 0) {
        ++xy;
      }
      rowMax = std::max(rowMax, grid[i][j]);
    }
    yz += rowMax;
  }
  for (int j = 0; j < n; ++j) {
    int colMax = 0;
    for (int i = 0; i < n; ++i) {
      colMax = std::max(colMax, grid[i][j]);
    }
    zx += colMax;
  }
  return xy + yz + zx;
}

}  // namespace

ProjectionAreaOf3dShapesSolution::ProjectionAreaOf3dShapesSolution() {
  setMetaInfo({.id = 883,
               .title = "Projection Area of 3D Shapes",
               .url = "https://leetcode.com/problems/projection-area-of-3d-shapes/"});
  registerStrategy(
      {.name = "single-pass",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Geometry", "Matrix"}},
      projectionAreaImpl);
}

int ProjectionAreaOf3dShapesSolution::projectionArea(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_883

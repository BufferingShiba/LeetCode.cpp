#include "leetcode/problems/surface-area-of-3d-shapes.h"

namespace leetcode {
namespace problem_892 {

namespace {

int surfaceAreaImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int total = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int v = grid[i][j];
      if (v == 0) continue;
      total += 2;  // top and bottom faces
      for (int d = 0; d < 4; ++d) {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        int neighbor = 0;
        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
          neighbor = grid[ni][nj];
        }
        total += (v > neighbor) ? (v - neighbor) : 0;
      }
    }
  }
  return total;
}

}  // namespace

SurfaceAreaOf3dShapesSolution::SurfaceAreaOf3dShapesSolution() {
  setMetaInfo({.id = 892,
               .title = "Surface Area of 3D Shapes",
               .url = "https://leetcode.com/problems/surface-area-of-3d-shapes/"});
  registerStrategy({.name = "cellwise-count",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math", "Geometry", "Matrix"}},
                   surfaceAreaImpl);
}

int SurfaceAreaOf3dShapesSolution::surfaceArea(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_892
}  // namespace leetcode

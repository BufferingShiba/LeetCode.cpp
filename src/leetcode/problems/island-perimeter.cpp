#include "leetcode/problems/island-perimeter.h"

namespace leetcode::problem_463 {

namespace {

int islandPerimeterImpl(std::vector<std::vector<int>>& grid) {
  int rows = grid.size();
  int cols = grid[0].size();
  int lands = 0;
  int shared = 0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (grid[i][j] == 1) {
        ++lands;
        if (i + 1 < rows && grid[i + 1][j] == 1) ++shared;
        if (j + 1 < cols && grid[i][j + 1] == 1) ++shared;
      }
    }
  }

  return 4 * lands - 2 * shared;
}

}  // namespace

IslandPerimeterSolution::IslandPerimeterSolution() {
  setMetaInfo({.id = 463, .title = "Island Perimeter",
               .url = "https://leetcode.com/problems/island-perimeter/"});

  registerStrategy(
      {.name = "Counting Edges",
       .expected = "Accepted",
       .time_complexity = "O(rows × cols)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Matrix"}},
      islandPerimeterImpl);
}

int IslandPerimeterSolution::islandPerimeter(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_463

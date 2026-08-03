#include "leetcode/problems/zigzag-grid-traversal-with-skip.h"

#include <vector>

namespace leetcode::problem_3417 {

namespace {

std::vector<int> zigzagTraversalImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  std::vector<int> result;
  result.reserve((m * n + 1) / 2);

  int index = 0;
  for (int r = 0; r < m; ++r) {
    if (r % 2 == 0) {
      for (int c = 0; c < n; ++c) {
        if (index % 2 == 0) {
          result.push_back(grid[r][c]);
        }
        ++index;
      }
    } else {
      for (int c = n - 1; c >= 0; --c) {
        if (index % 2 == 0) {
          result.push_back(grid[r][c]);
        }
        ++index;
      }
    }
  }
  return result;
}

}  // namespace

ZigzagGridTraversalWithSkipSolution::ZigzagGridTraversalWithSkipSolution() {
  setMetaInfo({.id = 3417,
               .title = "Zigzag Grid Traversal With Skip",
               .url =
                   "https://leetcode.com/problems/zigzag-grid-traversal-with-skip/"});
  registerStrategy(
      {"ZigzagWithSkip", "Accepted", "O(m*n)", "O(1) extra",
       {"Array", "Matrix", "Simulation"}},
      zigzagTraversalImpl);
}

std::vector<int> ZigzagGridTraversalWithSkipSolution::zigzagTraversal(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3417

#include "leetcode/problems/minimum-operations-to-make-a-uni-value-grid.h"

#include <algorithm>
#include <cmath>
#include <vector>

namespace leetcode::problem_2033 {

static int minOperationsImpl(std::vector<std::vector<int>>& grid, int x) {
  std::vector<int> flat;
  flat.reserve(grid.size() * grid[0].size());
  for (const auto& row : grid) {
    for (int val : row) {
      flat.push_back(val);
    }
  }

  // Check modulo consistency
  int remainder = flat[0] % x;
  for (int val : flat) {
    if (val % x != remainder) {
      return -1;
    }
  }

  // Sort and find median
  std::sort(flat.begin(), flat.end());
  int median = flat[flat.size() / 2];

  // Compute total operations
  int total = 0;
  for (int val : flat) {
    total += std::abs(val - median) / x;
  }
  return total;
}

MinimumOperationsToMakeAUniValueGridSolution::MinimumOperationsToMakeAUniValueGridSolution() {
  setMetaInfo({.id = 2033,
               .title = "Minimum Operations to Make a Uni-Value Grid",
               .url = "https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/"});
  registerStrategy({.name = "Flatten + Sort + Median",
                    .expected = "Accepted",
                    .time_complexity = "O(N log N)",
                    .space_complexity = "O(N)",
                    .tags = {"Array", "Math", "Sorting", "Matrix"}},
                   minOperationsImpl);
}

}  // namespace leetcode::problem_2033

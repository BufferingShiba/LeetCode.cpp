#include "leetcode/problems/find-missing-and-repeated-values.h"

namespace leetcode::problem_2965 {

namespace {

std::vector<int> countBased(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  const int total = n * n;
  std::vector<int> count(total + 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++count[grid[i][j]];
    }
  }
  int repeated = 0;
  int missing = 0;
  for (int x = 1; x <= total; ++x) {
    if (count[x] == 2) {
      repeated = x;
    } else if (count[x] == 0) {
      missing = x;
    }
  }
  return {repeated, missing};
}

}  // namespace

FindMissingAndRepeatedValuesSolution::FindMissingAndRepeatedValuesSolution() {
  setMetaInfo({.id = 2965,
               .title = "Find Missing and Repeated Values",
               .url = "https://leetcode.com/problems/find-missing-and-repeated-values/"});
  registerStrategy(
      {.name = "Count",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Hash Table", "Math", "Matrix"}},
      countBased);
}

std::vector<int> FindMissingAndRepeatedValuesSolution::
    findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_2965

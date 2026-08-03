#include "leetcode/problems/count-submatrices-with-top-left-element-and-sum-less-than-k.h"

namespace leetcode {
namespace problem_3070 {

namespace {

int countSubmatricesImpl(std::vector<std::vector<int>>& grid, int k) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  std::vector<std::vector<long long>> ps(m, std::vector<long long>(n, 0));

  int count = 0;
  for (int i = 0; i < m; ++i) {
    long long row_sum = 0;
    for (int j = 0; j < n; ++j) {
      row_sum += grid[i][j];
      long long above = (i > 0) ? ps[i - 1][j] : 0;
      ps[i][j] = (i > 0 ? ps[i - 1][j] : 0) + row_sum;
      if (ps[i][j] <= k) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

CountSubmatricesWithTopLeftElementAndSumLessThanKSolution::
    CountSubmatricesWithTopLeftElementAndSumLessThanKSolution() {
  setMetaInfo({.id = 3070,
               .title = "Count Submatrices with Top-Left Element and Sum Less Than k",
               .url = "https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/"});
  registerStrategy(
      {.name = "prefixSum",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Matrix", "Prefix Sum"}},
      countSubmatricesImpl);
}

int CountSubmatricesWithTopLeftElementAndSumLessThanKSolution::countSubmatrices(
    std::vector<std::vector<int>>& grid, int k) {
  return getSolution()(grid, k);
}

}  // namespace problem_3070
}  // namespace leetcode

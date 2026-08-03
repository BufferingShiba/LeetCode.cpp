#include "leetcode/problems/row-with-maximum-ones.h"

namespace leetcode {
namespace problem_2643 {

namespace {

std::vector<int> rowAndMaximumOnesImpl(std::vector<std::vector<int>>& mat) {
  int bestRow = 0;
  int bestCount = -1;
  for (int i = 0; i < static_cast<int>(mat.size()); ++i) {
    int count = 0;
    for (int v : mat[i]) {
      count += v;
    }
    if (count > bestCount) {
      bestCount = count;
      bestRow = i;
    }
  }
  return {bestRow, bestCount};
}

}  // namespace

RowWithMaximumOnesSolution::RowWithMaximumOnesSolution() {
  setMetaInfo({.id = 2643,
               .title = "Row With Maximum Ones",
               .url = "https://leetcode.com/problems/row-with-maximum-ones/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Matrix"}},
      rowAndMaximumOnesImpl);
}

std::vector<int> RowWithMaximumOnesSolution::rowAndMaximumOnes(
    std::vector<std::vector<int>>& mat) {
  return getSolution()(mat);
}

}  // namespace problem_2643
}  // namespace leetcode

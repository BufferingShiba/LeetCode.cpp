#include "leetcode/problems/pascals-triangle-ii.h"

namespace leetcode {
namespace problem_119 {

namespace {

std::vector<int> getRowImpl(int rowIndex) {
  std::vector<int> ans(1, 1);
  for (int i = 1; i <= rowIndex; ++i) {
    ans.push_back(1);
    for (int j = i - 1; j > 0; --j) {
      ans[j] += ans[j - 1];
    }
  }
  return ans;
}

}  // namespace

PascalsTriangleIiSolution::PascalsTriangleIiSolution() {
  setMetaInfo({.id = 119,
               .title = "Pascal's Triangle II",
               .url = "https://leetcode.com/problems/pascals-triangle-ii/"});
  registerStrategy(
      {.name = "InPlaceDP",
       .expected = "Accepted",
       .time_complexity = "O(rowIndex^2)",
       .space_complexity = "O(rowIndex)",
       .tags = {"Array", "Dynamic Programming"}},
      getRowImpl);
}

std::vector<int> PascalsTriangleIiSolution::getRow(int rowIndex) {
  return getSolution()(rowIndex);
}

}  // namespace problem_119
}  // namespace leetcode

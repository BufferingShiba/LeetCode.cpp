#include "leetcode/problems/pascals-triangle.h"

namespace leetcode {
namespace problem_118 {

namespace {

std::vector<std::vector<int>> generateImpl(int numRows) {
  std::vector<std::vector<int>> triangle(numRows);
  for (int i = 0; i < numRows; ++i) {
    triangle[i].resize(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
  }
  return triangle;
}

}  // namespace

PascalsTriangleSolution::PascalsTriangleSolution() {
  setMetaInfo({118, "Pascal's Triangle",
               "https://leetcode.com/problems/pascals-triangle/"});
  registerStrategy(
      {"IterativeDP", "Accepted", "O(numRows^2)", "O(numRows^2)",
       {"Array", "Dynamic Programming"}},
      generateImpl);
}

std::vector<std::vector<int>> PascalsTriangleSolution::generate(int numRows) {
  return getSolution()(numRows);
}

}  // namespace problem_118
}  // namespace leetcode

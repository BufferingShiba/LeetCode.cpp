#include "leetcode/problems/find-the-degree-of-each-vertex.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_3898 {

namespace {

std::vector<int> findDegreesImpl(std::vector<std::vector<int>>& matrix) {
  const int n = static_cast<int>(matrix.size());
  std::vector<int> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    ans[i] = std::accumulate(matrix[i].begin(), matrix[i].end(), 0);
  }
  return ans;
}

}  // namespace

FindTheDegreeOfEachVertexSolution::FindTheDegreeOfEachVertexSolution() {
  setMetaInfo({.id = 3898,
               .title = "Find the Degree of Each Vertex",
               .url = "https://leetcode.com/problems/find-the-degree-of-each-vertex/"});
  registerStrategy(
      {.name = "RowSum",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Graph Theory", "Matrix"}},
      findDegreesImpl);
}

std::vector<int> FindTheDegreeOfEachVertexSolution::findDegrees(
    std::vector<std::vector<int>>& matrix) {
  return getSolution()(matrix);
}

}  // namespace problem_3898
}  // namespace leetcode

#include "leetcode/problems/find-center-of-star-graph.h"

namespace leetcode::problem_1791 {

namespace {

int findCenterImpl(std::vector<std::vector<int>>& edges) {
  const int a = edges[0][0];
  const int b = edges[0][1];
  const int c = edges[1][0];
  const int d = edges[1][1];
  if (a == c || a == d) return a;
  return b;
}

}  // namespace

FindCenterOfStarGraphSolution::FindCenterOfStarGraphSolution() {
  setMetaInfo({.id = 1791,
               .title = "Find Center of Star Graph",
               .url = "https://leetcode.com/problems/find-center-of-star-graph/"});
  registerStrategy({.name = "FirstTwoEdges",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Graph", "Star"}},
                   findCenterImpl);
}

int FindCenterOfStarGraphSolution::findCenter(std::vector<std::vector<int>>& edges) {
  return getSolution()(edges);
}

}  // namespace leetcode::problem_1791

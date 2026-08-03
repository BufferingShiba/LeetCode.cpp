#include "leetcode/problems/all-paths-from-source-to-target.h"

#include <vector>

namespace leetcode::problem_797 {
namespace {

void dfs(int node, const std::vector<std::vector<int>>& graph,
         std::vector<int>& path, std::vector<std::vector<int>>& result) {
  if (node == static_cast<int>(graph.size()) - 1) {
    result.push_back(path);
    return;
  }
  for (int next : graph[node]) {
    path.push_back(next);
    dfs(next, graph, path, result);
    path.pop_back();
  }
}

std::vector<std::vector<int>> allPathsSourceTargetImpl(
    std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<int>> result;
  std::vector<int> path{0};
  dfs(0, graph, path, result);
  return result;
}

}  // namespace

AllPathsFromSourceToTargetSolution::AllPathsFromSourceToTargetSolution() {
  setMetaInfo({.id = 797,
               .title = "All Paths From Source to Target",
               .url = "https://leetcode.com/problems/all-paths-from-source-to-target/"});
  registerStrategy(
      {.name = "dfs_backtracking",
       .expected = "Accepted",
       .time_complexity = "O(2^n * n)",
       .space_complexity = "O(n + 2^n * n)",
       .tags = {"Backtracking", "Depth-First Search", "Graph Theory"}},
      allPathsSourceTargetImpl);
}

std::vector<std::vector<int>>
AllPathsFromSourceToTargetSolution::allPathsSourceTarget(
    std::vector<std::vector<int>>& graph) {
  return getSolution()(graph);
}

}  // namespace leetcode::problem_797

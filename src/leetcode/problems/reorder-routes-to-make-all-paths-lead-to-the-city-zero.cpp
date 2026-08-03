#include "leetcode/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1466 {

namespace {

int minReorderImpl(int n, std::vector<std::vector<int>>& connections) {
  // 构建无向邻接表，同时记录原方向信息
  // adj[u] = {v, is_original_direction_u_to_v}
  std::vector<std::vector<std::pair<int, bool>>> adj(n);
  for (auto& edge : connections) {
    int a = edge[0], b = edge[1];
    // a → b 是原方向
    adj[a].emplace_back(b, true);   // 原方向: a→b
    adj[b].emplace_back(a, false);  // 反向: b→a（不是原方向）
  }

  int flip_count = 0;

  std::function<void(int, int)> dfs = [&](int node, int parent) {
    for (auto& [neighbor, is_original] : adj[node]) {
      if (neighbor == parent) continue;
      // 如果我们沿原方向从 node→neighbor 走，说明背离根 0，需要翻转
      if (is_original) {
        ++flip_count;
      }
      dfs(neighbor, node);
    }
  };

  dfs(0, -1);
  return flip_count;
}

}  // namespace

ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution::
    ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution() {
  setMetaInfo({.id = 1466,
               .title = "Reorder Routes to Make All Paths Lead to the City Zero",
               .url = "https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/"});

  registerStrategy(
      {.name = "DFS from zero",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Graph"}},
      minReorderImpl);
}

int ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution::minReorder(
    int n, std::vector<std::vector<int>>& connections) {
  return getSolution()(n, connections);
}

}  // namespace leetcode::problem_1466

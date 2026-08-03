#include "leetcode/problems/maximum-score-after-applying-operations-on-a-tree.h"

#include <algorithm>
#include <queue>
#include <vector>

namespace leetcode::problem_2925 {

static long long maximumScoreAfterOperationsImpl(std::vector<std::vector<int>>& edges,
                                                  std::vector<int>& values) {
  int n = static_cast<int>(values.size());
  if (n == 0) return 0;

  std::vector<std::vector<int>> adj(n);
  for (auto& e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // BFS to establish parent relationships and a topological order (parents before children)
  std::vector<int> parent(n, -1);
  std::vector<int> bfs_order;
  bfs_order.reserve(n);
  std::queue<int> q;
  q.push(0);
  parent[0] = n;  // sentinel: root has no parent
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    bfs_order.push_back(u);
    for (int v : adj[u]) {
      if (parent[v] == -1) {
        parent[v] = u;
        q.push(v);
      }
    }
  }

  // Process nodes in reverse BFS order: children before parent
  std::vector<long long> totalSum(n, 0);
  std::vector<long long> g(n, 0);

  for (auto it = bfs_order.rbegin(); it != bfs_order.rend(); ++it) {
    int u = *it;
    totalSum[u] = values[u];
    long long sum_g = 0;
    bool has_child = false;
    for (int v : adj[u]) {
      if (v == parent[u]) continue;
      has_child = true;
      totalSum[u] += totalSum[v];
      sum_g += g[v];
    }
    if (!has_child) {
      // leaf: must be kept if no ancestor is kept
      g[u] = 0;
    } else {
      g[u] = std::max(static_cast<long long>(values[u]) + sum_g,
                      totalSum[u] - values[u]);
    }
  }

  return g[0];
}

MaximumScoreAfterApplyingOperationsOnATreeSolution::
    MaximumScoreAfterApplyingOperationsOnATreeSolution() {
  setMetaInfo({.id = 2925,
               .title = "Maximum Score After Applying Operations on a Tree",
               .url = "https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/"});
  registerStrategy(
      {.name = "Tree DP (post-order)",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Tree", "Depth-First Search"}},
      maximumScoreAfterOperationsImpl);
}

}  // namespace leetcode::problem_2925

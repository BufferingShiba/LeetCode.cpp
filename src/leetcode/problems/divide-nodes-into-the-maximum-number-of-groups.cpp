#include "leetcode/problems/divide-nodes-into-the-maximum-number-of-groups.h"

#include <queue>

namespace leetcode::problem_2493 {

namespace {

int magnificentSetsImpl(int n, const std::vector<std::vector<int>>& edges) {
  std::vector<std::vector<int>> adj(n + 1);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  std::vector<int> color(n + 1, 0);  // 1,2 bipartition
  std::vector<int> visited(n + 1, 0);

  int total = 0;
  for (int start = 1; start <= n; ++start) {
    if (visited[start]) continue;

    // Collect the connected component and check bipartite.
    std::vector<int> comp;
    std::queue<int> q;
    q.push(start);
    visited[start] = 1;
    color[start] = 1;
    bool bipartite = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      comp.push_back(u);
      for (int v : adj[u]) {
        if (!visited[v]) {
          visited[v] = 1;
          color[v] = 3 - color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          bipartite = false;
        }
      }
    }

    if (!bipartite) return -1;  // contains odd cycle

    // For each root in component, BFS to find max depth.
    int best = 0;
    for (int root : comp) {
      std::vector<int> depth(n + 1, -1);
      std::queue<int> bq;
      bq.push(root);
      depth[root] = 0;
      int deepest = 0;
      while (!bq.empty()) {
        int u = bq.front();
        bq.pop();
        for (int v : adj[u]) {
          if (depth[v] == -1) {
            depth[v] = depth[u] + 1;
            deepest = std::max(deepest, depth[v]);
            bq.push(v);
          }
        }
      }
      best = std::max(best, deepest + 1);
    }
    total += best;
  }
  return total;
}

}  // namespace

DivideNodesIntoTheMaximumNumberOfGroupsSolution::
    DivideNodesIntoTheMaximumNumberOfGroupsSolution() {
  setMetaInfo({.id = 2493,
               .title = "Divide Nodes Into the Maximum Number of Groups",
               .url = "https://leetcode.com/problems/divide-nodes-into-the-"
                      "maximum-number-of-groups/"});

  registerStrategy(
      {.name = "BFS layers per component",
       .expected = "Accepted",
       .time_complexity = "O(n * (n + m))",
       .space_complexity = "O(n + m)",
       .tags = {"BFS", "Graph Theory", "Bipartite"}},
      [](int n, std::vector<std::vector<int>>& edges) {
        return magnificentSetsImpl(n, edges);
      });
}

int DivideNodesIntoTheMaximumNumberOfGroupsSolution::magnificentSets(
    int n, std::vector<std::vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace leetcode::problem_2493

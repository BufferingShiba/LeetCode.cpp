#include "leetcode/problems/find-minimum-diameter-after-merging-two-trees.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3203 {
namespace {

struct BfsResult {
  int farthestNode;
  int distance;
};

BfsResult bfs(const std::vector<std::vector<int>>& adj, int start) {
  int n = static_cast<int>(adj.size());
  std::vector<int> dist(n, -1);
  std::queue<int> q;
  dist[start] = 0;
  q.push(start);
  int farthestNode = start;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dist[u] > dist[farthestNode]) {
      farthestNode = u;
    }
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return {farthestNode, dist[farthestNode]};
}

// diameter is the max tree path length; radius = ceil(diameter / 2).
std::pair<int, int> treeDiameterAndRadius(
    const std::vector<std::vector<int>>& adj) {
  if (adj.empty()) {
    return {0, 0};
  }
  BfsResult first = bfs(adj, 0);
  BfsResult second = bfs(adj, first.farthestNode);
  int diameter = second.distance;
  int radius = (diameter + 1) / 2;
  return {diameter, radius};
}

std::vector<std::vector<int>> buildAdj(const std::vector<std::vector<int>>& edges,
                                       int n) {
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }
  return adj;
}

int minimizeDiameterAfterMerge(std::vector<std::vector<int>>& edges1,
                               std::vector<std::vector<int>>& edges2) {
  int n = static_cast<int>(edges1.size()) + 1;
  int m = static_cast<int>(edges2.size()) + 1;
  auto adj1 = buildAdj(edges1, n);
  auto adj2 = buildAdj(edges2, m);

  auto [d1, r1] = treeDiameterAndRadius(adj1);
  auto [d2, r2] = treeDiameterAndRadius(adj2);

  int ans = std::max({d1, d2, r1 + 1 + r2});
  return ans;
}

}  // namespace

FindMinimumDiameterAfterMergingTwoTreesSolution::FindMinimumDiameterAfterMergingTwoTreesSolution() {
  setMetaInfo({.id = 3203,
               .title = "Find Minimum Diameter After Merging Two Trees",
               .url = "https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/"});
  registerStrategy(
      {.name = "diameter-and-radius",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"Tree", "Depth-First Search", "Breadth-First Search",
                "Graph Theory"},
       .notes =
           "Compute each tree's diameter via two BFS passes; its radius is "
           "ceil(diameter/2). Optimal answer is max(d1, d2, r1+1+r2)."},
      minimizeDiameterAfterMerge);
}

}  // namespace problem_3203
}  // namespace leetcode

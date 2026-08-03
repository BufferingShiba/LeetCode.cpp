#include "leetcode/problems/reachable-nodes-in-subdivided-graph.h"

#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_882 {

namespace {

int reachableNodesImpl(std::vector<std::vector<int>>& edges, int maxMoves,
                       int n) {
  // Build adjacency list: (neighbor, weight)
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (const auto& e : edges) {
    int u = e[0], v = e[1], cnt = e[2];
    int w = cnt + 1;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  // Dijkstra from node 0
  const long long INF = LLONG_MAX / 2;
  std::vector<long long> dist(n, INF);
  dist[0] = 0;

  using P = std::pair<long long, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.emplace(0, 0);

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (const auto& [v, w] : adj[u]) {
      long long nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.emplace(nd, v);
      }
    }
  }

  // Count reachable original nodes
  int ans = 0;
  long long maxM = maxMoves;
  for (int i = 0; i < n; ++i) {
    if (dist[i] <= maxM) ++ans;
  }

  // Count reachable intermediate nodes on each edge
  for (const auto& e : edges) {
    int u = e[0], v = e[1], cnt = e[2];
    long long from_u = std::max(0LL, maxM - dist[u]);
    long long from_v = std::max(0LL, maxM - dist[v]);
    ans += static_cast<int>(
        std::min(static_cast<long long>(cnt), from_u + from_v));
  }

  return ans;
}

}  // namespace

ReachableNodesInSubdividedGraphSolution::
    ReachableNodesInSubdividedGraphSolution() {
  setMetaInfo({.id = 882,
               .title = "Reachable Nodes In Subdivided Graph",
               .url = "https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/"});
  registerStrategy(
      {.name = "Dijkstra",
       .expected = "Accepted",
       .time_complexity = "O(E log V)",
       .space_complexity = "O(V + E)",
       .tags = {"Graph Theory", "Heap (Priority Queue)", "Shortest Path"}},
      reachableNodesImpl);
}

int ReachableNodesInSubdividedGraphSolution::reachableNodes(
    std::vector<std::vector<int>>& edges, int maxMoves, int n) {
  return getSolution()(edges, maxMoves, n);
}

}  // namespace problem_882
}  // namespace leetcode

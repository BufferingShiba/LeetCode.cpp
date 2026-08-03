#include "leetcode/problems/find-edges-in-shortest-paths.h"

#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3123 {

static std::vector<bool> findAnswerImpl(int n,
                                        std::vector<std::vector<int>>& edges) {
  int m = edges.size();

  // Build adjacency list
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (int i = 0; i < m; ++i) {
    int u = edges[i][0], v = edges[i][1], w = edges[i][2];
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }

  const long long INF = std::numeric_limits<long long>::max() / 2;

  auto dijkstra = [&](int src) -> std::vector<long long> {
    std::vector<long long> dist(n, INF);
    dist[src] = 0;
    std::priority_queue<std::pair<long long, int>,
                        std::vector<std::pair<long long, int>>,
                        std::greater<>>
        pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      if (d != dist[u]) continue;
      for (auto& [v, w] : adj[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.emplace(dist[v], v);
        }
      }
    }
    return dist;
  };

  auto dist0 = dijkstra(0);
  auto distN = dijkstra(n - 1);

  long long D = dist0[n - 1];
  std::vector<bool> ans(m, false);

  if (D == INF) return ans;

  for (int i = 0; i < m; ++i) {
    int u = edges[i][0], v = edges[i][1], w = edges[i][2];
    if (dist0[u] + w + distN[v] == D ||
        dist0[v] + w + distN[u] == D) {
      ans[i] = true;
    }
  }

  return ans;
}

FindEdgesInShortestPathsSolution::FindEdgesInShortestPathsSolution() {
  setMetaInfo({.id = 3123,
               .title = "Find Edges in Shortest Paths",
               .url = "https://leetcode.com/problems/find-edges-in-shortest-paths/"});
  registerStrategy(
      {.name = "Dijkstra",
       .expected = "Accepted",
       .time_complexity = "O((n+m) log n)",
       .space_complexity = "O(n+m)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Graph Theory",
                "Heap (Priority Queue)", "Shortest Path"}},
      findAnswerImpl);
}

std::vector<bool> FindEdgesInShortestPathsSolution::findAnswer(
    int n, std::vector<std::vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace problem_3123
}  // namespace leetcode

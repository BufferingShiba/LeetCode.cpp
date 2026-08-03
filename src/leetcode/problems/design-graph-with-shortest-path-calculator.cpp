#include "leetcode/problems/design-graph-with-shortest-path-calculator.h"

#include <limits>
#include <queue>

namespace leetcode::problem_2642 {

Graph::Graph(int n, std::vector<std::vector<int>>& edges)
    : n_(n), adj_(n) {
  for (const auto& e : edges) {
    addEdge(e);
  }
}

void Graph::addEdge(std::vector<int> edge) {
  adj_[edge[0]].push_back({edge[1], edge[2]});
}

int Graph::shortestPath(int node1, int node2) {
  constexpr int kInf = std::numeric_limits<int>::max();
  std::vector<int> dist(n_, kInf);
  dist[node1] = 0;

  using P = std::pair<int, int>;  // (distance, node)
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  pq.push({0, node1});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    if (u == node2) return d;
    for (const auto& [v, w] : adj_[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }
  return dist[node2] == kInf ? -1 : dist[node2];
}

}  // namespace leetcode::problem_2642

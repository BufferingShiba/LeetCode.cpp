#include <cstdint>
#include <queue>
#include <utility>
#include <vector>

#include "leetcode/problems/modify-graph-edge-weights.h"

namespace leetcode::problem_2699 {

namespace {

constexpr long long kBigWeight = 2000000000LL;

struct DijkstraResult {
  long long dist;
  // parentEdge[v] = index (into edges) of edge used to reach v from its parent.
  std::vector<int> parentEdge;
  std::vector<int> parentNode;
};

// Runs Dijkstra from `source` using the current weights in `eg`.
// Edges with weight == -1 are treated as weight 1 for this computation.
DijkstraResult runDijkstra(int n, const std::vector<std::vector<int>>& eg,
                           int source, int destination) {
  struct AdjInfo {
    int to;
    long long weight;
    int edgeIndex;
  };
  std::vector<std::vector<AdjInfo>> adj(n);
  for (int i = 0; i < static_cast<int>(eg.size()); ++i) {
    int w = eg[i][2] == -1 ? 1 : eg[i][2];
    int u = eg[i][0], v = eg[i][1];
    adj[u].push_back({v, w, i});
    adj[v].push_back({u, w, i});
  }

  std::vector<long long> dist(n, INT64_MAX);
  std::vector<int> parentEdge(n, -1), parentNode(n, -1);
  using P = std::pair<long long, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
  dist[source] = 0;
  pq.push({0, source});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (const auto& info : adj[u]) {
      long long nd = dist[u] + info.weight;
      if (nd < dist[info.to]) {
        dist[info.to] = nd;
        parentEdge[info.to] = info.edgeIndex;
        parentNode[info.to] = u;
        pq.push({nd, info.to});
      }
    }
  }
  return {dist[destination], std::move(parentEdge), std::move(parentNode)};
}

}  // namespace

std::vector<std::vector<int>>
ModifyGraphEdgeWeightsSolution::modifiedGraphEdgesImpl(
    int n, std::vector<std::vector<int>>& edges, int source, int destination,
    int target) {
  std::vector<std::vector<int>> eg = edges;
  std::vector<int> negIdx;
  for (int i = 0; i < static_cast<int>(eg.size()); ++i) {
    if (eg[i][2] == -1) negIdx.push_back(i);
  }

  // Feasibility bound A: with all -1 edges at their minimum (1), the shortest
  // path can never be larger than target if even this minimum already exceeds.
  long long lowDist = runDijkstra(n, eg, source, destination).dist;
  if (lowDist > target) return {};

  // Feasibility bound B: with all -1 edges at their maximum, if the shortest
  // path is still below target then no assignment can raise it to target.
  if (!negIdx.empty()) {
    for (int idx : negIdx) eg[idx][2] = static_cast<int>(kBigWeight);
    long long highDist = runDijkstra(n, eg, source, destination).dist;
    if (highDist < target) return {};
    // Restore to -1; the iterative phase will assign final weights.
    for (int idx : negIdx) eg[idx][2] = -1;
  }

  // Iterative greedy: start with all -1 edges = 1 and progressively raise an
  // edge lying on the shortest path, driving the distance toward == target.
  long long guard =
      static_cast<long long>(negIdx.size()) * n + 10;
  while (guard-- > 0) {
    DijkstraResult res = runDijkstra(n, eg, source, destination);
    long long d = res.dist;
    if (d == target) break;
    if (d > target) return {};  // unreachable while increasing only

    // d < target. Reconstruct the shortest path and find the first -1 edge.
    int negEdge = -1;
    int cur = destination;
    while (cur != source) {
      int e = res.parentEdge[cur];
      if (e < 0) return {};  // disconnected (should not happen per constraints)
      if (eg[e][2] == -1) {
        negEdge = e;
        break;
      }
      cur = res.parentNode[cur];
    }
    if (negEdge < 0) return {};  // no adjustable edge on shortest path

    long long newWeight = 1 + (target - d);
    if (newWeight > kBigWeight) return {};  // cannot reach target at all
    eg[negEdge][2] = static_cast<int>(newWeight);
  }

  // If the loop exhausted the guard without reaching target, it is impossible.
  if (runDijkstra(n, eg, source, destination).dist != target) return {};

  for (int idx : negIdx) {
    // Any -1 edge we never raised stays at its implicit value of 1.
    if (eg[idx][2] == -1) eg[idx][2] = 1;
  }
  return eg;
}

std::vector<std::vector<int>>
ModifyGraphEdgeWeightsSolution::modifiedGraphEdges(
    int n, std::vector<std::vector<int>>& edges, int source, int destination,
    int target) {
  return getSolution()(n, edges, source, destination, target);
}

}  // namespace leetcode::problem_2699

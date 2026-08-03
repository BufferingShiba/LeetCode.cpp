#include "leetcode/problems/minimum-threshold-path-with-limited-heavy-edges.h"

#include <algorithm>
#include <deque>
#include <limits>
#include <vector>

namespace leetcode {
namespace problem_3924 {

static int minimumThresholdImpl(int n, std::vector<std::vector<int>>& edges,
                                int source, int target, int k) {
  if (source == target) return 0;

  // Build adjacency list
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  int max_weight = 0;
  for (const auto& e : edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
    if (w > max_weight) max_weight = w;
  }

  // 0-1 BFS: light edge cost=0, heavy edge cost=1
  auto can_reach = [&](int threshold) -> bool {
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::deque<int> dq;
    dist[source] = 0;
    dq.push_back(source);

    while (!dq.empty()) {
      int u = dq.front();
      dq.pop_front();
      for (const auto& [v, w] : adj[u]) {
        int cost = (w > threshold) ? 1 : 0;
        if (dist[u] + cost < dist[v]) {
          dist[v] = dist[u] + cost;
          if (cost == 0) {
            dq.push_front(v);
          } else {
            dq.push_back(v);
          }
        }
      }
    }

    return dist[target] <= k;
  };

  // If unreachable even with all edges light, return -1
  if (!can_reach(max_weight)) return -1;

  // Binary search for minimum feasible threshold
  int lo = 0, hi = max_weight;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (can_reach(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  return lo;
}

MinimumThresholdPathWithLimitedHeavyEdgesSolution::
    MinimumThresholdPathWithLimitedHeavyEdgesSolution() {
  setMetaInfo(
      {.id = 3924,
       .title = "Minimum Threshold Path With Limited Heavy Edges",
       .url =
           "https://leetcode.com/problems/minimum-threshold-path-with-limited-heavy-edges/"});
  registerStrategy(
      {.name = "BinarySearchWithZeroOneBFS",
       .expected = "Accepted",
       .time_complexity = "O((V+E) log W)",
       .space_complexity = "O(V+E)",
       .tags = {"Binary Search", "Breadth-First Search", "Graph Theory"}},
      minimumThresholdImpl);
}

int MinimumThresholdPathWithLimitedHeavyEdgesSolution::minimumThreshold(
    int n, std::vector<std::vector<int>>& edges, int source, int target,
    int k) {
  return getSolution()(n, edges, source, target, k);
}

}  // namespace problem_3924
}  // namespace leetcode

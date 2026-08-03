#include "leetcode/problems/number-of-restricted-paths-from-first-to-last-node.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_1786 {

namespace {
const long long kMod = 1000000007LL;
}

// Dijkstra from node n to compute shortest distances, then DP over nodes
// sorted by their distance (restricted path only moves to strictly smaller
// distance, so the order is a DAG).
static int solution1(int n, vector<vector<int>>& edges) {
  vector<vector<pair<int, int>>> adj(n + 1);
  for (const auto& e : edges) {
    adj[e[0]].push_back({e[1], e[2]});
    adj[e[1]].push_back({e[0], e[2]});
  }

  // Dijkstra from node n.
  const long long kInf = 1e18;
  vector<long long> dist(n + 1, kInf);
  dist[n] = 0;
  using P = pair<long long, int>;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, n});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (const auto& [v, w] : adj[u]) {
      if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }

  // DP over nodes in increasing distance order. dp[u] = number of restricted
  // paths from u to n. A path may move u -> v only if dist[u] > dist[v].
  vector<long long> dp(n + 1, 0);
  dp[n] = 1;

  // Order nodes by distance ascending (n has smallest distance, and nodes
  // with larger distance depend on nodes with smaller distance).
  vector<int> order;
  order.reserve(n);
  for (int i = 1; i <= n; ++i) order.push_back(i);
  sort(order.begin(), order.end(),
       [&](int a, int b) { return dist[a] < dist[b]; });

  for (int u : order) {
    if (u == n) continue;  // dist[n]=0 is smallest, n processed first.
    long long sum = 0;
    for (const auto& [v, w] : adj[u]) {
      if (dist[u] > dist[v]) {
        sum += dp[v];
        if (sum >= kMod) sum -= kMod;
      }
    }
    dp[u] = sum;
  }

  return static_cast<int>(dp[1]);
}

NumberOfRestrictedPathsFromFirstToLastNodeSolution::NumberOfRestrictedPathsFromFirstToLastNodeSolution() {
  setMetaInfo({
      .id = 1786,
      .title = "Number of Restricted Paths From First to Last Node",
      .url = "https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node"
  });
  registerStrategy(
      {.name = "Dijkstra + Topological DP",
       .expected = "Accepted",
       .time_complexity = "O((V+E) log V)",
       .space_complexity = "O(V+E)",
       .tags = {"Graph", "Shortest Path", "Dijkstra", "Dynamic Programming", "Memoization"}},
      solution1);
}

int NumberOfRestrictedPathsFromFirstToLastNodeSolution::countRestrictedPaths(int n, vector<vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace problem_1786
}  // namespace leetcode

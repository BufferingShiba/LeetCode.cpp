#include "leetcode/problems/network-recovery-pathways.h"

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_3620 {
namespace {

constexpr long long kInf = std::numeric_limits<long long>::max() / 4;

// Check whether there exists a path from 0 to n-1 where every intermediate node
// is online, every traversed edge has cost >= x, and total edge cost <= k.
bool feasible(int n, const std::vector<std::vector<int>>& edges,
              const std::vector<bool>& online, long long k, int x) {
  // Build DAG adjacency (forward) for topological order.
  std::vector<std::vector<int>> adj(n);
  std::vector<int> indeg(n, 0);
  for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
    int u = edges[i][0], v = edges[i][1];
    if (edges[i][2] < x) continue;  // edge not usable when threshold is x
    if ((u != 0 && u != n - 1 && !online[u]) ||
        (v != 0 && v != n - 1 && !online[v])) {
      continue;  // offline nodes cannot be part of a valid path
    }
    adj[u].push_back(i);
    ++indeg[v];
  }

  // Topological order via Kahn.
  std::queue<int> q;
  for (int i = 0; i < n; ++i)
    if (indeg[i] == 0) q.push(i);

  std::vector<long long> dp(n, kInf);
  dp[0] = 0;

  int processed = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ++processed;
    for (int idx : adj[u]) {
      int v = edges[idx][1];
      long long c = edges[idx][2];
      --indeg[v];
      if (indeg[v] == 0) q.push(v);
      if (dp[u] != kInf && dp[u] + c < dp[v]) {
        dp[v] = dp[u] + c;
      }
    }
  }
  return dp[n - 1] <= k;
}

int findMaxPathScoreImpl(std::vector<std::vector<int>>& edges,
                         std::vector<bool>& online, long long k) {
  const int n = static_cast<int>(online.size());
  int maxCost = 0;
  for (const auto& e : edges) maxCost = std::max(maxCost, e[2]);

  // First, check whether at least one valid path exists at all (x = 0).
  if (!feasible(n, edges, online, k, 0)) return -1;

  // Binary search over threshold x. feasible(x) is monotone decreasing in x.
  // Answer lies in [0, maxCost].
  int lo = 0, hi = maxCost;  // invariant: feasible(lo) true, feasible(hi) unknown above
  int ans = 0;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(n, edges, online, k, mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}

}  // namespace

NetworkRecoveryPathwaysSolution::NetworkRecoveryPathwaysSolution() {
  setMetaInfo({.id = 3620,
               .title = "Network Recovery Pathways",
               .url = "https://leetcode.com/problems/network-recovery-pathways/"});
  registerStrategy({.name = "binary-search-topological-dp",
                    .expected = "Accepted",
                    .time_complexity = "O((n + m) * log(maxCost))",
                    .space_complexity = "O(n + m)",
                    .tags = {"Binary Search", "Topological Sort", "Dynamic Programming", "Shortest Path"}},
                   findMaxPathScoreImpl);
}

}  // namespace problem_3620
}  // namespace leetcode

#include "leetcode/problems/minimum-time-to-reach-target-with-limited-power.h"

#include <climits>
#include <utility>
#include <vector>

namespace leetcode::problem_3977 {

static std::vector<long long> minTimeMaxPowerImpl(int n, std::vector<std::vector<int>>& edges, int power,
                                                  std::vector<int>& cost, int source, int target) {
  // Build adjacency list: node -> list of (neighbor, time)
  std::vector<std::vector<std::pair<int, int>>> adj(n);
  for (const auto& e : edges) {
    int u = e[0], v = e[1], w = e[2];
    adj[u].emplace_back(v, w);
  }

  // dist[node][remaining_power] = minimum time to reach (node, remaining_power)
  const long long INF = LLONG_MAX;
  std::vector<std::vector<long long>> dist(n, std::vector<long long>(power + 1, INF));
  dist[source][power] = 0;

  // DP: process power levels from high to low.
  // Since any edge traversal decreases remaining power, the state graph is a DAG in the power dimension.
  for (int p = power; p >= 0; --p) {
    for (int u = 0; u < n; ++u) {
      if (dist[u][p] == INF) continue;
      if (p < cost[u]) continue;  // cannot afford to leave node u

      int np = p - cost[u];
      for (const auto& [v, w] : adj[u]) {
        long long nt = dist[u][p] + w;
        if (nt < dist[v][np]) {
          dist[v][np] = nt;
        }
      }
    }
  }

  // Extract answer from all reachable states at target
  long long min_time = INF;
  long long max_rem = -1;
  for (int p = 0; p <= power; ++p) {
    if (dist[target][p] < min_time) {
      min_time = dist[target][p];
      max_rem = p;
    } else if (dist[target][p] == min_time) {
      if (p > max_rem) max_rem = p;
    }
  }

  if (min_time == INF) {
    return {-1, -1};
  }
  return {min_time, max_rem};
}

MinimumTimeToReachTargetWithLimitedPowerSolution::MinimumTimeToReachTargetWithLimitedPowerSolution() {
  setMetaInfo({.id = 3977,
               .title = "Minimum Time to Reach Target With Limited Power",
               .url = "https://leetcode.com/problems/minimum-time-to-reach-target-with-limited-power/"});
  registerStrategy(
      {.name = "DP_decreasing_power",
       .expected = "Accepted",
       .time_complexity = "O(power * (n + E))",
       .space_complexity = "O(n * power)",
       .tags = {"Array", "Dynamic Programming", "Graph Theory", "Shortest Path"}},
      minTimeMaxPowerImpl);
}

std::vector<long long> MinimumTimeToReachTargetWithLimitedPowerSolution::minTimeMaxPower(
    int n, std::vector<std::vector<int>>& edges, int power, std::vector<int>& cost, int source, int target) {
  return getSolution()(n, edges, power, cost, source, target);
}

}  // namespace leetcode::problem_3977

#include "leetcode/problems/cheapest-flights-within-k-stops.h"

#include <algorithm>
#include <climits>

namespace leetcode::problem_787 {

static int findCheapestPriceImpl(int n, std::vector<std::vector<int>>& flights,
                                 int src, int dst, int k) {
  const int INF = INT_MAX / 2;
  std::vector<int> dist(n, INF);
  dist[src] = 0;

  for (int i = 0; i <= k; ++i) {
    std::vector<int> next = dist;  // copy: use only previous layer's paths
    for (const auto& f : flights) {
      int u = f[0], v = f[1], w = f[2];
      if (dist[u] != INF) {
        next[v] = std::min(next[v], dist[u] + w);
      }
    }
    dist = std::move(next);
  }

  return dist[dst] == INF ? -1 : dist[dst];
}

CheapestFlightsWithinKStopsSolution::CheapestFlightsWithinKStopsSolution() {
  setMetaInfo({.id = 787,
               .title = "Cheapest Flights Within K Stops",
               .url = "https://leetcode.com/problems/cheapest-flights-within-k-stops/"});
  registerStrategy(
      {.name = "Bellman-Ford DP",
       .expected = "Accepted",
       .time_complexity = "O(k * E)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Graph", "Shortest Path"}},
      findCheapestPriceImpl);
}

int CheapestFlightsWithinKStopsSolution::findCheapestPrice(
    int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
  return getSolution()(n, flights, src, dst, k);
}

}  // namespace leetcode::problem_787

#include "leetcode/problems/minimum-cost-to-buy-apples-ii.h"

#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3928 {
namespace {

struct Road {
  int to;
  long long cost;
  long long tax;
};

constexpr long long kInf = std::numeric_limits<long long>::max() / 4;

std::vector<long long> dijkstra(
    int source, const std::vector<std::vector<Road>>& graph, bool carrying) {
  std::vector<long long> distance(graph.size(), kInf);
  using State = std::pair<long long, int>;
  std::priority_queue<State, std::vector<State>, std::greater<State>> pending;
  distance[source] = 0;
  pending.push({0, source});

  while (!pending.empty()) {
    const auto [currentDistance, node] = pending.top();
    pending.pop();
    if (currentDistance != distance[node]) {
      continue;
    }
    for (const Road& road : graph[node]) {
      const long long weight = carrying ? road.cost * road.tax : road.cost;
      const long long candidate = currentDistance + weight;
      if (candidate < distance[road.to]) {
        distance[road.to] = candidate;
        pending.push({candidate, road.to});
      }
    }
  }
  return distance;
}

std::vector<int> minCostImpl(int n, std::vector<int>& prices,
                             std::vector<std::vector<int>>& roads) {
  std::vector<std::vector<Road>> graph(n);
  for (const std::vector<int>& road : roads) {
    const int u = road[0];
    const int v = road[1];
    const long long cost = road[2];
    const long long tax = road[3];
    graph[u].push_back({v, cost, tax});
    graph[v].push_back({u, cost, tax});
  }

  std::vector<int> answer(n);
  for (int source = 0; source < n; ++source) {
    const std::vector<long long> emptyDistance =
        dijkstra(source, graph, false);
    const std::vector<long long> carryingDistance =
        dijkstra(source, graph, true);

    long long best = prices[source];
    for (int shop = 0; shop < n; ++shop) {
      if (emptyDistance[shop] == kInf || carryingDistance[shop] == kInf) {
        continue;
      }
      best = std::min(best, emptyDistance[shop] + prices[shop] +
                                  carryingDistance[shop]);
    }
    answer[source] = static_cast<int>(best);
  }
  return answer;
}

}  // namespace

MinimumCostToBuyApplesIISolution::MinimumCostToBuyApplesIISolution() {
  setMetaInfo({.id = 3928,
               .title = "Minimum Cost to Buy Apples II",
               .url = "https://leetcode.com/problems/minimum-cost-to-buy-apples-ii/"});
  registerStrategy({.name = "all-sources-dual-dijkstra",
                    .expected = "Accepted",
                    .time_complexity = "O(n * (n + m) * log n)",
                    .space_complexity = "O(n + m)",
                    .tags = {"Graph", "Dijkstra", "Shortest Path"}},
                   minCostImpl);
}

}  // namespace problem_3928
}  // namespace leetcode

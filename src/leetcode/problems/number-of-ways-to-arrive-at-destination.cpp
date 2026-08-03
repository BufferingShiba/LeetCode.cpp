#include "leetcode/problems/number-of-ways-to-arrive-at-destination.h"

#include <queue>
#include <utility>

namespace leetcode::problem_1976 {

namespace {

constexpr int kMod = 1000000007;

int countPathsImpl(int n, std::vector<std::vector<int>>& roads) {
  std::vector<std::vector<std::pair<int, int>>> graph(n);
  for (const auto& road : roads) {
    int u = road[0], v = road[1], t = road[2];
    graph[u].emplace_back(v, t);
    graph[v].emplace_back(u, t);
  }

  constexpr long long kInf = 4e18;
  std::vector<long long> dist(n, kInf);
  std::vector<long long> ways(n, 0);

  // min-heap: (distance, node)
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>>
      pq;

  dist[0] = 0;
  ways[0] = 1;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;

    for (const auto& [v, t] : graph[u]) {
      long long nd = d + t;
      if (nd < dist[v]) {
        dist[v] = nd;
        ways[v] = ways[u];
        pq.push({nd, v});
      } else if (nd == dist[v]) {
        ways[v] = (ways[v] + ways[u]) % kMod;
      }
    }
  }

  return static_cast<int>(ways[n - 1]);
}

}  // namespace

NumberOfWaysToArriveAtDestinationSolution::NumberOfWaysToArriveAtDestinationSolution() {
  setMetaInfo({.id = 1976,
               .title = "Number of Ways to Arrive at Destination",
               .url = "https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/"});
  registerStrategy({"DijkstraShortestPathCounting", "Accepted",
                     "O((V+E) log V)", "O(V+E)",
                     {"Dynamic Programming", "Graph Theory", "Topological Sort",
                      "Shortest Path"}},
                    countPathsImpl);
}

int NumberOfWaysToArriveAtDestinationSolution::countPaths(int n,
                                                          std::vector<std::vector<int>>& roads) {
  return getSolution()(n, roads);
}

}  // namespace leetcode::problem_1976

#include "leetcode/problems/network-delay-time.h"

#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_743 {

static int dijkstraImpl(std::vector<std::vector<int>>& times, int n, int k) {
  // 构建邻接表
  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
  for (const auto& edge : times) {
    int u = edge[0], v = edge[1], w = edge[2];
    graph[u].emplace_back(v, w);
  }

  const int INF = INT_MAX;
  std::vector<int> dist(n + 1, INF);
  dist[k] = 0;

  // 最小堆：{distance, node}
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;
  pq.emplace(0, k);

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;  // 跳过过期条目
    for (const auto& [v, w] : graph[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.emplace(dist[v], v);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (dist[i] == INF) return -1;
    ans = std::max(ans, dist[i]);
  }
  return ans;
}

NetworkDelayTimeSolution::NetworkDelayTimeSolution() {
  setMetaInfo({.id = 743,
               .title = "Network Delay Time",
               .url = "https://leetcode.com/problems/network-delay-time/"});
  registerStrategy(
      {.name = "Dijkstra",
       .expected = "Accepted",
       .time_complexity = "O(E log V)",
       .space_complexity = "O(V + E)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Graph Theory",
                "Heap (Priority Queue)", "Shortest Path"}},
      dijkstraImpl);
  setDefaultStrategy();
}

int NetworkDelayTimeSolution::networkDelayTime(
    std::vector<std::vector<int>>& times, int n, int k) {
  return getSolution()(times, n, k);
}

}  // namespace problem_743
}  // namespace leetcode

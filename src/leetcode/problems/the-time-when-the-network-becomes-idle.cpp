#include "leetcode/problems/the-time-when-the-network-becomes-idle.h"

#include <queue>

namespace leetcode::problem_2039 {

namespace {

int networkBecomesIdleImpl(std::vector<std::vector<int>>& edges,
                           std::vector<int>& patience) {
  const int n = static_cast<int>(patience.size());
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  // BFS from master server 0 to obtain shortest distances.
  std::vector<int> dist(n, -1);
  dist[0] = 0;
  std::queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  long long answer = 0;
  for (int i = 1; i < n; ++i) {
    const int d = dist[i];
    const int roundTrip = 2 * d;                 // first reply arrive time
    const long long lastSend =
        (static_cast<long long>(roundTrip) - 1) / patience[i] * patience[i];
    const long long lastReply = lastSend + roundTrip;
    answer = std::max(answer, lastReply);
  }
  return static_cast<int>(answer + 1);
}

}  // namespace

TheTimeWhenTheNetworkBecomesIdleSolution::TheTimeWhenTheNetworkBecomesIdleSolution()
    : SolutionBase<Func>() {
  setMetaInfo({.id = 2039,
               .title = "The Time When the Network Becomes Idle",
               .url =
                   "https://leetcode.com/problems/the-time-when-the-network-"
                   "becomes-idle/"});
  registerStrategy(
      {.name = "bfs-shortest-dist",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"Breadth-First Search", "Graph Theory", "Array"}},
      networkBecomesIdleImpl);
}

int TheTimeWhenTheNetworkBecomesIdleSolution::networkBecomesIdle(
    std::vector<std::vector<int>>& edges, std::vector<int>& patience) {
  return getSolution()(edges, patience);
}

}  // namespace leetcode::problem_2039

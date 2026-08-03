#include "leetcode/problems/second-minimum-time-to-reach-destination.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_2045 {

namespace {

long long travelTime(long long steps, int time, int change) {
  // Simulate each edge traversal. At the departure moment if the signal is
  // red (i.e. (cur / change) is odd), wait until next green window.
  long long cur = 0;
  for (long long i = 0; i < steps; ++i) {
    long long period = cur / change;
    if (period % 2 == 1) {
      cur = (period + 1) * change;  // wait to the start of the next green
    }
    cur += time;
  }
  return cur;
}

int secondMinimumImpl(int n, std::vector<std::vector<int>>& edges, int time,
                      int change) {
  constexpr int INF = 0x3f3f3f3f;
  std::vector<std::vector<int>> adj(n + 1);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  // dist1[v], dist2[v] : first and second distinct minimum hop counts from 1.
  std::vector<int> dist1(n + 1, INF);
  std::vector<int> dist2(n + 1, INF);

  std::queue<std::pair<int, int>> q;  // (node, hops)
  dist1[1] = 0;
  q.push({1, 0});

  while (!q.empty()) {
    auto [u, d] = q.front();
    q.pop();
    for (int v : adj[u]) {
      int nd = d + 1;
      if (nd < dist1[v]) {
        dist2[v] = dist1[v];
        dist1[v] = nd;
        q.push({v, nd});
      } else if (nd > dist1[v] && nd < dist2[v]) {
        dist2[v] = nd;
        q.push({v, nd});
      }
    }
  }

  // The second minimum arrival time is achieved by a path whose hop count is
  // either min(n) or min(n)+1; dist2[n] carries the second distinct hop count.
  long long secondDist = std::min(static_cast<long long>(dist2[n]),
                                  static_cast<long long>(dist1[n] + 2));
  return static_cast<int>(travelTime(secondDist, time, change));
}

}  // namespace

SecondMinimumTimeToReachDestinationSolution::
    SecondMinimumTimeToReachDestinationSolution() {
  this->setMetaInfo({.id = 2045,
                     .title = "Second Minimum Time to Reach Destination",
                     .url = "https://leetcode.com/problems/second-minimum-time-to-reach-destination/"});
  this->registerStrategy(
      {.name = "BFS second-shortest hops",
       .expected = "Accepted",
       .time_complexity = "O(V + E)",
       .space_complexity = "O(V + E)",
       .tags = {"Breadth-First Search", "Shortest Path", "Graph"}},
      secondMinimumImpl);
}

int SecondMinimumTimeToReachDestinationSolution::secondMinimum(
    int n, std::vector<std::vector<int>>& edges, int time, int change) {
  return this->getSolution()(n, edges, time, change);
}

}  // namespace problem_2045
}  // namespace leetcode

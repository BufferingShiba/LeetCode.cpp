#include "leetcode/problems/minimum-score-of-a-path-between-two-cities.h"

#include <limits>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_2492 {

// The path between 1 and n may revisit roads, so the minimum possible score is
// simply the minimum edge weight among all edges in the connected component
// that contains city 1 (and city n, guaranteed reachable).
// Approach: BFS from city 1 to mark reachable cities, then scan all edges and
// take the smallest weight whose both endpoints are reachable.
static int solution1(int n, vector<vector<int>>& roads) {
  std::vector<std::vector<int>> adj(n + 1);
  for (const auto& road : roads) {
    int a = road[0], b = road[1];
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<bool> visited(n + 1, false);
  std::queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }

  int best = std::numeric_limits<int>::max();
  for (const auto& road : roads) {
    int a = road[0], b = road[1], d = road[2];
    if (visited[a] && visited[b] && d < best) {
      best = d;
    }
  }
  return best;
}

MinimumScoreOfAPathBetweenTwoCitiesSolution::MinimumScoreOfAPathBetweenTwoCitiesSolution() {
  setMetaInfo({
      .id = 2492,
      .title = "Minimum Score of a Path Between Two Cities",
      .url = "https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities"
  });
  registerStrategy({.name = "BFS", .time_complexity = "O(n + m)", .space_complexity = "O(n)", .tags = {"BFS", "Graph"}}, solution1);
}

int MinimumScoreOfAPathBetweenTwoCitiesSolution::minScore(int n, vector<vector<int>>& roads) {
  return getSolution()(n, roads);
}

}  // namespace problem_2492
}  // namespace leetcode

#include "leetcode/problems/minimum-degree-of-a-connected-trio-in-a-graph.h"

#include <algorithm>
#include <climits>

namespace leetcode::problem_1761 {

namespace {

int minTrioDegreeImpl(int n, std::vector<std::vector<int>>& edges) {
  std::vector<std::vector<bool>> adj(n + 1, std::vector<bool>(n + 1, false));
  std::vector<int> deg(n + 1, 0);
  for (const auto& e : edges) {
    int u = e[0], v = e[1];
    adj[u][v] = adj[v][u] = true;
    ++deg[u];
    ++deg[v];
  }

  int best = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (!adj[i][j]) continue;
      for (int k = j + 1; k <= n; ++k) {
        if (!adj[i][k] || !adj[j][k]) continue;
        best = std::min(best, deg[i] + deg[j] + deg[k] - 6);
      }
    }
  }
  return best == INT_MAX ? -1 : best;
}

}  // namespace

MinimumDegreeOfAConnectedTrioInAGraphSolution::
    MinimumDegreeOfAConnectedTrioInAGraphSolution() {
  setMetaInfo(
      {.id = 1761,
       .title = "Minimum Degree of a Connected Trio in a Graph",
       .url =
           "https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/"});
  registerStrategy(
      {.name = "EnumerateTrios",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n^2)",
       .tags = {"Graph Theory", "Enumeration"}},
      minTrioDegreeImpl);
}

int MinimumDegreeOfAConnectedTrioInAGraphSolution::minTrioDegree(
    int n, std::vector<std::vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace leetcode::problem_1761

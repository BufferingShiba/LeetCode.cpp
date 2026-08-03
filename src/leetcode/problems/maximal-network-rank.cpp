#include "leetcode/problems/maximal-network-rank.h"
#include <algorithm>
#include <vector>

namespace leetcode::problem_1615 {

namespace {

int maximalNetworkRankImpl(int n, std::vector<std::vector<int>>& roads) {
  std::vector<int> degree(n, 0);
  std::vector<std::vector<bool>> hasEdge(n, std::vector<bool>(n, false));

  for (const auto& road : roads) {
    int u = road[0], v = road[1];
    ++degree[u];
    ++degree[v];
    hasEdge[u][v] = true;
    hasEdge[v][u] = true;
  }

  int best = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int rank = degree[i] + degree[j] - (hasEdge[i][j] ? 1 : 0);
      best = std::max(best, rank);
    }
  }
  return best;
}

}  // namespace

MaximalNetworkRankSolution::MaximalNetworkRankSolution() {
  setMetaInfo({.id = 1615,
               .title = "Maximal Network Rank",
               .url = "https://leetcode.com/problems/maximal-network-rank/"});
  registerStrategy(
      {"BruteForcePairs",
       "Accepted",
       "O(n^2)",
       "O(n^2)",
       {"Graph Theory"},
       "Enumerate all pairs, rank = deg[i]+deg[j]-(edge exists ? 1 : 0)."},
      maximalNetworkRankImpl);
}

int MaximalNetworkRankSolution::maximalNetworkRank(
    int n, std::vector<std::vector<int>>& roads) {
  return getSolution()(n, roads);
}

}  // namespace leetcode::problem_1615

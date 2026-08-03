#include "leetcode/problems/possible-bipartition.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_886 {

namespace {

bool bfsBipartition(int n, std::vector<std::vector<int>>& dislikes) {
  // Build adjacency list (1-indexed)
  std::vector<std::vector<int>> graph(n + 1);
  for (const auto& edge : dislikes) {
    int u = edge[0];
    int v = edge[1];
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // color: 0 = uncolored, 1 and -1 are the two groups
  std::vector<int> color(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    if (color[i] != 0) continue;

    std::queue<int> q;
    q.push(i);
    color[i] = 1;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : graph[u]) {
        if (color[v] == 0) {
          color[v] = -color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          return false;
        }
      }
    }
  }

  return true;
}

}  // namespace

PossibleBipartitionSolution::PossibleBipartitionSolution() {
  setMetaInfo({.id = 886,
               .title = "Possible Bipartition",
               .url = "https://leetcode.com/problems/possible-bipartition/"});

  registerStrategy(
      {.name = "BFS Coloring",
       .expected = "Accepted",
       .time_complexity = "O(V + E)",
       .space_complexity = "O(V + E)",
       .tags = {"BFS", "Graph", "Bipartite"}},
      bfsBipartition);
}

bool PossibleBipartitionSolution::possibleBipartition(
    int n, std::vector<std::vector<int>>& dislikes) {
  return getSolution()(n, dislikes);
}

}  // namespace problem_886
}  // namespace leetcode

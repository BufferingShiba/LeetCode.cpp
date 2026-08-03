#include "leetcode/problems/find-eventual-safe-states.h"

namespace leetcode {
namespace problem_802 {

static vector<int> solution1(vector<vector<int>>& graph) {
  // Reverse the edges and peel terminal nodes.  A node becomes safe once all
  // of its outgoing neighbors have already been proved safe.  This avoids the
  // recursion depth of a long directed chain.
  const int n = static_cast<int>(graph.size());
  vector<vector<int>> reverseGraph(n);
  vector<int> outDegree(n, 0);
  std::queue<int> safe;
  for (int node = 0; node < n; ++node) {
    outDegree[node] = static_cast<int>(graph[node].size());
    if (outDegree[node] == 0) safe.push(node);
    for (int next : graph[node]) reverseGraph[next].push_back(node);
  }

  vector<bool> isSafe(n, false);
  while (!safe.empty()) {
    int node = safe.front();
    safe.pop();
    isSafe[node] = true;
    for (int predecessor : reverseGraph[node]) {
      if (--outDegree[predecessor] == 0) safe.push(predecessor);
    }
  }

  vector<int> result;
  result.reserve(n);
  for (int node = 0; node < n; ++node) {
    if (isSafe[node]) result.push_back(node);
  }
  return result;
}

FindEventualSafeStatesSolution::FindEventualSafeStatesSolution() {
  setMetaInfo({
      .id = 802,
      .title = "Find Eventual Safe States",
      .url = "https://leetcode.com/problems/find-eventual-safe-states"
  });
  registerStrategy({.name = "Reverse Graph Peeling",
                    .expected = "Accepted",
                    .time_complexity = "O(V + E)",
                    .space_complexity = "O(V)",
                    .tags = {"Breadth-First Search", "Graph", "Topological Sort"}},
                   solution1);
}

vector<int> FindEventualSafeStatesSolution::eventualSafeNodes(vector<vector<int>>& graph) {
  return getSolution()(graph);
}

}  // namespace problem_802
}  // namespace leetcode

#include "leetcode/problems/count-number-of-possible-root-nodes.h"

#include <queue>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_2581 {

static int rootCountImpl(std::vector<std::vector<int>>& edges,
                         std::vector<std::vector<int>>& guesses, int k) {
  int n = static_cast<int>(edges.size()) + 1;

  // Build adjacency list
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Store guesses for O(1) lookup: guessSet[u] = set of v where [u,v] is a guess
  std::vector<std::unordered_set<int>> guessSet(n);
  for (const auto& g : guesses) {
    guessSet[g[0]].insert(g[1]);
  }

  // BFS from node 0 to establish parent relationships and traversal order
  std::vector<int> parent(n, -1);
  std::vector<int> order;
  std::queue<int> q;
  q.push(0);
  parent[0] = -2;  // mark root with special value
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    order.push_back(u);
    for (int v : adj[u]) {
      if (parent[v] == -1) {
        parent[v] = u;
        q.push(v);
      }
    }
  }

  // dp[i] = number of correct guesses when tree is rooted at node i
  std::vector<int> dp(n, 0);

  // Compute dp[0] using the BFS tree rooted at 0
  for (int u : order) {
    for (int v : adj[u]) {
      if (parent[v] == u) {  // v is a child of u in the current rooting
        if (guessSet[u].count(v)) {
          dp[0]++;
        }
      }
    }
  }

  // Reroot: propagate dp values to children using the transition formula
  for (int u : order) {
    for (int v : adj[u]) {
      if (parent[v] != u) continue;  // only process children
      dp[v] = dp[u];
      if (guessSet[u].count(v)) dp[v]--;
      if (guessSet[v].count(u)) dp[v]++;
    }
  }

  // Count nodes with at least k correct guesses
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (dp[i] >= k) {
      ans++;
    }
  }
  return ans;
}

CountNumberOfPossibleRootNodesSolution::CountNumberOfPossibleRootNodesSolution() {
  setMetaInfo({.id = 2581,
               .title = "Count Number of Possible Root Nodes",
               .url = "https://leetcode.com/problems/count-number-of-possible-root-nodes/"});
  registerStrategy(
      {.name = "reroot_dp",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"Array", "Hash Table", "Dynamic Programming", "Tree", "Depth-First Search"}},
      rootCountImpl);
}

int CountNumberOfPossibleRootNodesSolution::rootCount(
    std::vector<std::vector<int>>& edges,
    std::vector<std::vector<int>>& guesses, int k) {
  return getSolution()(edges, guesses, k);
}

}  // namespace problem_2581
}  // namespace leetcode

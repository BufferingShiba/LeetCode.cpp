#include "leetcode/problems/count-the-number-of-good-nodes.h"

#include <functional>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_3249 {

namespace {

// Returns the subtree size rooted at `u`, computing sizes bottom-up and
// counting good nodes along the way.
int countGoodNodesImpl(std::vector<std::vector<int>>& edges) {
  int n = static_cast<int>(edges.size()) + 1;
  std::vector<std::vector<int>> adj(n);
  for (const auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  int good = 0;
  std::vector<int> subtreeSize(n, 0);
  std::function<int(int, int)> dfs = [&](int u, int parent) -> int {
    int size = 1;
    bool allEqual = true;
    int childSize = -1;
    for (int v : adj[u]) {
      if (v == parent) continue;
      int s = dfs(v, u);
      if (childSize == -1) {
        childSize = s;
      } else if (s != childSize) {
        allEqual = false;
      }
      size += s;
    }
    subtreeSize[u] = size;
    if (allEqual) ++good;
    return size;
  };
  dfs(0, -1);
  return good;
}

}  // namespace

CountTheNumberOfGoodNodesSolution::CountTheNumberOfGoodNodesSolution() {
  setMetaInfo({.id = 3249,
               .title = "Count the Number of Good Nodes",
               .url = "https://leetcode.com/problems/count-the-number-of-good-nodes/"});
  registerStrategy({.name = "DFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Tree", "Depth-First Search"}},
                   countGoodNodesImpl);
}

int CountTheNumberOfGoodNodesSolution::countGoodNodes(
    std::vector<std::vector<int>>& edges) {
  return getSolution()(edges);
}

}  // namespace problem_3249
}  // namespace leetcode

#include "leetcode/problems/redundant-connection-ii.h"

#include <vector>

namespace leetcode {
namespace problem_685 {

namespace {

class UnionFind {
 public:
  explicit UnionFind(int n) : parent_(n + 1) {
    for (int i = 0; i <= n; ++i) parent_[i] = i;
  }

  int find(int x) {
    if (parent_[x] != x) parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  // Returns false if u and v are already in the same set (cycle detected).
  bool unite(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu == pv) return false;
    parent_[pv] = pu;
    return true;
  }

 private:
  std::vector<int> parent_;
};

std::vector<int> findRedundantDirectedConnectionImpl(
    std::vector<std::vector<int>>& edges) {
  int n = static_cast<int>(edges.size());

  // parentOf[v] = u: the first time we see an edge (u, v)
  std::vector<int> parentOf(n + 1, 0);
  std::vector<int> candidate1, candidate2;

  for (auto& e : edges) {
    int u = e[0], v = e[1];
    if (parentOf[v] != 0) {
      // v already has a parent → indegree would become 2
      candidate1 = {parentOf[v], v};
      candidate2 = e;
    } else {
      parentOf[v] = u;
    }
  }

  UnionFind uf(n);
  std::vector<int> cycleEdge;

  for (auto& e : edges) {
    // Skip candidate2 to see if the rest forms a cycle
    if (!candidate2.empty() && e == candidate2) continue;

    if (!uf.unite(e[0], e[1])) {
      cycleEdge = e;
    }
  }

  // Case A: no node has indegree 2 → pure cycle scenario
  if (candidate1.empty()) {
    return cycleEdge;
  }

  // Case B: indegree-2 exists.
  // If after removing candidate2 there is still a cycle,
  // then candidate1 must be the redundant edge.
  if (!cycleEdge.empty()) {
    return candidate1;
  }

  // Otherwise, candidate2 is the answer.
  return candidate2;
}

}  // anonymous namespace

RedundantConnectionIiSolution::RedundantConnectionIiSolution() {
  setMetaInfo({.id = 685,
               .title = "Redundant Connection II",
               .url = "https://leetcode.com/problems/redundant-connection-ii/"});
  registerStrategy(
      {.name = "UnionFind",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Depth-First Search", "Breadth-First Search", "Union-Find",
                "Graph Theory"}},
      findRedundantDirectedConnectionImpl);
}

std::vector<int> RedundantConnectionIiSolution::findRedundantDirectedConnection(
    std::vector<std::vector<int>>& edges) {
  return getSolution()(edges);
}

}  // namespace problem_685
}  // namespace leetcode

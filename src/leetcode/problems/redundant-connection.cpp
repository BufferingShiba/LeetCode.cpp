#include "leetcode/problems/redundant-connection.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_684 {
namespace {

struct DSU {
  std::vector<int> parent, rank;
  explicit DSU(int n) : parent(n + 1), rank(n + 1, 0) {
    std::iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  bool unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return false;
    if (rank[ra] < rank[rb]) std::swap(ra, rb);
    parent[rb] = ra;
    if (rank[ra] == rank[rb]) ++rank[ra];
    return true;
  }
};

std::vector<int> findRedundantConnectionImpl(std::vector<std::vector<int>>& edges) {
  DSU dsu(static_cast<int>(edges.size()));
  for (const auto& e : edges) {
    if (!dsu.unite(e[0], e[1])) {
      return {e[0], e[1]};
    }
  }
  return {};
}

}  // namespace

void RedundantConnectionSolution::registerStrategy(
    const std::string& name, const Func& func) {
  SolutionBase::registerStrategy(
      {name, "Accepted", "O(n \u00b7 \u03b1(n))", "O(n)",
       {"Union-Find", "Graph"}}, func);
}

void RedundantConnectionSolution::initStrategies() {
  registerStrategy("UnionFind",
                   [](std::vector<std::vector<int>>& edges) {
                     return findRedundantConnectionImpl(edges);
                   });
}

RedundantConnectionSolution::RedundantConnectionSolution() {
  setMetaInfo({684, "Redundant Connection",
               "https://leetcode.com/problems/redundant-connection/"});
  initStrategies();
  setDefaultStrategy();
}

}  // namespace problem_684
}  // namespace leetcode

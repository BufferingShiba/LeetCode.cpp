#include "leetcode/problems/find-if-path-exists-in-graph.h"
#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1971 {

namespace {

class UnionFind {
 public:
  explicit UnionFind(int n) : parent_(n), rank_(n, 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    while (parent_[x] != x) {
      parent_[x] = parent_[parent_[x]];  // path halving
      x = parent_[x];
    }
    return x;
  }

  void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return;
    if (rank_[ra] < rank_[rb]) {
      std::swap(ra, rb);
    }
    parent_[rb] = ra;
    if (rank_[ra] == rank_[rb]) {
      ++rank_[ra];
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

bool validPathImpl(int n, std::vector<std::vector<int>>& edges, int source,
                   int destination) {
  UnionFind uf(n);
  for (const auto& edge : edges) {
    uf.unite(edge[0], edge[1]);
  }
  return uf.find(source) == uf.find(destination);
}

}  // namespace

FindIfPathExistsInGraphSolution::FindIfPathExistsInGraphSolution() {
  setMetaInfo({.id = 1971,
               .title = "Find if Path Exists in Graph",
               .url = "https://leetcode.com/problems/find-if-path-exists-in-graph/"});

  registerStrategy(
      {"union-find", "Accepted", "O((n + E) α(n))", "O(n)",
       {"Union-Find", "Graph Theory"}},
      validPathImpl);
}

bool FindIfPathExistsInGraphSolution::validPath(
    int n, std::vector<std::vector<int>>& edges, int source, int destination) {
  return getSolution()(n, edges, source, destination);
}

}  // namespace problem_1971
}  // namespace leetcode

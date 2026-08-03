#include "leetcode/problems/number-of-operations-to-make-network-connected.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1319 {

namespace {

class DSU {
 public:
  explicit DSU(int n) : parent_(n), rank_(n, 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (rank_[rx] < rank_[ry]) {
      parent_[rx] = ry;
    } else if (rank_[rx] > rank_[ry]) {
      parent_[ry] = rx;
    } else {
      parent_[ry] = rx;
      ++rank_[rx];
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

int makeConnectedImpl(int n, std::vector<std::vector<int>>& connections) {
  if (static_cast<int>(connections.size()) < n - 1) {
    return -1;
  }

  DSU dsu(n);
  for (const auto& conn : connections) {
    dsu.unite(conn[0], conn[1]);
  }

  int components = 0;
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) == i) {
      ++components;
    }
  }

  return components - 1;
}

}  // namespace

NumberOfOperationsToMakeNetworkConnectedSolution::NumberOfOperationsToMakeNetworkConnectedSolution() {
  setMetaInfo({.id = 1319,
               .title = "Number of Operations to Make Network Connected",
               .url = "https://leetcode.com/problems/number-of-operations-to-make-network-connected/"});
  registerStrategy(
      {.name = "UnionFind",
       .expected = "Accepted",
       .time_complexity = "O(E * α(N))",
       .space_complexity = "O(N)",
       .tags = {"Union-Find", "Graph Theory"}},
      makeConnectedImpl);
  setDefaultStrategy();
}

int NumberOfOperationsToMakeNetworkConnectedSolution::makeConnected(
    int n, std::vector<std::vector<int>>& connections) {
  return getSolution()(n, connections);
}

}  // namespace problem_1319
}  // namespace leetcode

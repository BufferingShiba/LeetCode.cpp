#include "leetcode/problems/graph-connectivity-with-threshold.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1627 {

namespace {

class DSU {
 public:
  explicit DSU(int n) : parent_(n + 1), rank_(n + 1, 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
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

std::vector<bool> areConnectedImpl(int n, int threshold,
                                   std::vector<std::vector<int>>& queries) {
  DSU dsu(n);
  // For every common factor z > threshold, union all multiples of z.
  for (int z = threshold + 1; z <= n; ++z) {
    for (int mult = 2 * z; mult <= n; mult += z) {
      dsu.unite(z, mult);
    }
  }
  std::vector<bool> ans;
  ans.reserve(queries.size());
  for (const auto& q : queries) {
    ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
  }
  return ans;
}

}  // namespace

GraphConnectivityWithThreshold::GraphConnectivityWithThreshold() {
  setMetaInfo({.id = 1627,
               .title = "Graph Connectivity With Threshold",
               .url = "https://leetcode.com/problems/graph-connectivity-with-threshold/"});
  registerStrategy({.name = "union_find",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n + q)",
                    .space_complexity = "O(n)",
                    .tags = {"Union-Find", "Number Theory"}},
                   areConnectedImpl);
}

std::vector<bool> GraphConnectivityWithThreshold::areConnected(
    int n, int threshold, std::vector<std::vector<int>>& queries) {
  return getSolution()(n, threshold, queries);
}

}  // namespace problem_1627
}  // namespace leetcode

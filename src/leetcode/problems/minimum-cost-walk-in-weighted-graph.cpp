#include "leetcode/problems/minimum-cost-walk-in-weighted-graph.h"

#include <vector>

namespace leetcode::problem_3108 {

namespace {

class DSU {
 public:
  explicit DSU(int n)
      : parent_(n), rank_(n, 0), comp_and_(n, ALL_ONES) {
    for (int i = 0; i < n; ++i) {
      parent_[i] = i;
    }
  }

  int find(int x) {
    if (parent_[x] != x) {
      parent_[x] = find(parent_[x]);
    }
    return parent_[x];
  }

  void unite(int x, int y, int edge_weight) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
      if (rank_[rx] < rank_[ry]) {
        parent_[rx] = ry;
        comp_and_[ry] &= comp_and_[rx];
        comp_and_[ry] &= edge_weight;
      } else if (rank_[rx] > rank_[ry]) {
        parent_[ry] = rx;
        comp_and_[rx] &= comp_and_[ry];
        comp_and_[rx] &= edge_weight;
      } else {
        parent_[ry] = rx;
        comp_and_[rx] &= comp_and_[ry];
        comp_and_[rx] &= edge_weight;
        ++rank_[rx];
      }
    } else {
      comp_and_[rx] &= edge_weight;
    }
  }

  int componentAnd(int x) {
    return comp_and_[find(x)];
  }

 private:
  static constexpr int ALL_ONES = ~0;  // all bits 1, equals -1 in two's complement
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> comp_and_;
};

std::vector<int> minimumCostImpl(int n, std::vector<std::vector<int>>& edges,
                                 std::vector<std::vector<int>>& query) {
  DSU dsu(n);
  for (const auto& edge : edges) {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];
    dsu.unite(u, v, w);
  }

  std::vector<int> answer;
  answer.reserve(query.size());
  for (const auto& q : query) {
    int s = q[0];
    int t = q[1];
    if (dsu.find(s) != dsu.find(t)) {
      answer.push_back(-1);
    } else {
      answer.push_back(dsu.componentAnd(s));
    }
  }
  return answer;
}

}  // namespace

MinimumCostWalkInWeightedGraphSolution::
    MinimumCostWalkInWeightedGraphSolution() {
  setMetaInfo({.id = 3108,
               .title = "Minimum Cost Walk in Weighted Graph",
               .url = "https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/"});
  registerStrategy(
      {.name = "DSU with component AND",
       .expected = "Accepted",
       .time_complexity = "O((n + m + q) * α(n))",
       .space_complexity = "O(n)",
       .tags = {"Array", "Bit Manipulation", "Union-Find", "Graph Theory"}},
      minimumCostImpl);
}

std::vector<int> MinimumCostWalkInWeightedGraphSolution::minimumCost(
    int n, std::vector<std::vector<int>>& edges,
    std::vector<std::vector<int>>& query) {
  return getSolution()(n, edges, query);
}

}  // namespace leetcode::problem_3108

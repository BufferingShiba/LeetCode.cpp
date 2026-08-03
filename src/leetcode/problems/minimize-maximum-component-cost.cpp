#include "leetcode/problems/minimize-maximum-component-cost.h"

#include <algorithm>
#include <numeric>

namespace leetcode::problem_3613 {

namespace {

class DSU {
 public:
  explicit DSU(int n) : parent_(n), size_(n, 1) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }
  int find(int x) {
    while (parent_[x] != x) {
      parent_[x] = parent_[parent_[x]];
      x = parent_[x];
    }
    return x;
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size_[a] < size_[b]) std::swap(a, b);
    parent_[b] = a;
    size_[a] += size_[b];
  }
  int countComponents(int n) const {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (parent_[i] == i) ++cnt;
    }
    return cnt;
  }

 private:
  std::vector<int> parent_;
  std::vector<int> size_;
};

bool feasible(int n, const std::vector<std::vector<int>>& edges, int k, long long limit) {
  DSU dsu(n);
  for (const auto& e : edges) {
    if (e[2] <= limit) dsu.unite(e[0], e[1]);
  }
  return dsu.countComponents(n) <= k;
}

int minCostImpl(int n, std::vector<std::vector<int>>& edges, int k) {
  long long lo = 0;
  long long hi = 0;
  for (const auto& e : edges) hi = std::max<long long>(hi, e[2]);
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (feasible(n, edges, k, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return static_cast<int>(lo);
}

}  // namespace

MinimizeMaximumComponentCostSolution::MinimizeMaximumComponentCostSolution() {
  setMetaInfo({.id = 3613,
               .title = "Minimize Maximum Component Cost",
               .url = "https://leetcode.com/problems/minimize-maximum-component-cost/"});
  registerStrategy({.name = "BinarySearchUnionFind",
                    .expected = "Accepted",
                    .time_complexity = "O((n+m) log W)",
                    .space_complexity = "O(n)",
                    .tags = {"Binary Search", "Union-Find", "Graph Theory"}},
                   minCostImpl);
}

int MinimizeMaximumComponentCostSolution::minCost(
    int n, std::vector<std::vector<int>>& edges, int k) {
  return getSolution()(n, edges, k);
}

}  // namespace leetcode::problem_3613

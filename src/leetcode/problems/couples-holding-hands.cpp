#include "leetcode/problems/couples-holding-hands.h"

namespace leetcode::problem_765 {

namespace {

class UnionFind {
 public:
  explicit UnionFind(int n) : parent_(n), size_(n, 1), components_(n) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int find(int x) {
    while (parent_[x] != x) {
      parent_[x] = parent_[parent_[x]];
      x = parent_[x];
    }
    return x;
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (size_[rx] < size_[ry]) std::swap(rx, ry);
    parent_[ry] = rx;
    size_[rx] += size_[ry];
    --components_;
  }

  int components() const { return components_; }

 private:
  std::vector<int> parent_;
  std::vector<int> size_;
  int components_;
};

int minSwapsCouplesImpl(std::vector<int>& row) {
  int n = static_cast<int>(row.size()) / 2;
  UnionFind uf(n);
  for (int i = 0; i < n; ++i) {
    int c1 = row[2 * i] / 2;
    int c2 = row[2 * i + 1] / 2;
    if (c1 != c2) {
      uf.unite(c1, c2);
    }
  }
  return n - uf.components();
}

}  // namespace

CouplesHoldingHandsSolution::CouplesHoldingHandsSolution() {
  setMetaInfo({.id = 765,
               .title = "Couples Holding Hands",
               .url = "https://leetcode.com/problems/couples-holding-hands/"});
  registerStrategy({.name = "UnionFind",
                     .expected = "Accepted",
                     .time_complexity = "O(n α(n))",
                     .space_complexity = "O(n)",
                     .tags = {"Union-Find", "Graph Theory", "Greedy"}},
                   minSwapsCouplesImpl);
}

int CouplesHoldingHandsSolution::minSwapsCouples(std::vector<int>& row) {
  return getSolution()(row);
}

}  // namespace leetcode::problem_765

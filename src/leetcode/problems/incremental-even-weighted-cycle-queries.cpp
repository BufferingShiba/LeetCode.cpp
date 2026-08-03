#include "leetcode/problems/incremental-even-weighted-cycle-queries.h"

namespace leetcode {
namespace problem_3887 {

// ---------- DSU with parity (XOR distance) ----------
class DSU {
  std::vector<int> parent_;
  std::vector<int> parity_;  // parity of node to its parent
  std::vector<int> size_;

 public:
  explicit DSU(int n) : parent_(n), parity_(n, 0), size_(n, 1) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  // Returns {root, parity from x to root}
  std::pair<int, int> find(int x) {
    if (parent_[x] == x) return {x, 0};
    auto [root, p] = find(parent_[x]);
    parity_[x] ^= p;
    parent_[x] = root;
    return {root, parity_[x]};
  }

  // Attempts to add edge (u,v) with weight w.
  // Returns true if consistent (edge added or already consistent),
  // false if would create an odd cycle.
  bool unite(int u, int v, int w) {
    auto [ru, pu] = find(u);
    auto [rv, pv] = find(v);
    if (ru == rv) {
      // Same component: check if the implied cycle is even
      return (pu ^ pv) == w;
    }
    // Union by size
    if (size_[ru] < size_[rv]) {
      parent_[ru] = rv;
      parity_[ru] = pu ^ w ^ pv;
      size_[rv] += size_[ru];
    } else {
      parent_[rv] = ru;
      parity_[rv] = pu ^ w ^ pv;  // same XOR equation, symmetric
      size_[ru] += size_[rv];
    }
    return true;
  }
};

// ---------- Strategy implementation ----------
static int numberOfEdgesAddedImpl(int n, std::vector<std::vector<int>>& edges) {
  DSU dsu(n);
  int count = 0;
  for (const auto& edge : edges) {
    int u = edge[0], v = edge[1], w = edge[2];
    if (dsu.unite(u, v, w)) {
      ++count;
    }
  }
  return count;
}

// ---------- Solution class ----------
IncrementalEvenWeightedCycleQueriesSolution::IncrementalEvenWeightedCycleQueriesSolution() {
  setMetaInfo({.id = 3887,
               .title = "Incremental Even-Weighted Cycle Queries",
               .url = "https://leetcode.com/problems/incremental-even-weighted-cycle-queries/"});
  registerStrategy(
      {.name = "DSU with Parity",
       .expected = "Accepted",
       .time_complexity = "O((n + m) * α(n))",
       .space_complexity = "O(n)",
       .tags = {"Union-Find", "Graph Theory"}},
      numberOfEdgesAddedImpl);
}

int IncrementalEvenWeightedCycleQueriesSolution::numberOfEdgesAdded(
    int n, std::vector<std::vector<int>>& edges) {
  return getSolution()(n, edges);
}

}  // namespace problem_3887
}  // namespace leetcode

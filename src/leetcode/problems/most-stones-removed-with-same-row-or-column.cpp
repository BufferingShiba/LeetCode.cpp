#include "leetcode/problems/most-stones-removed-with-same-row-or-column.h"

#include <unordered_set>

namespace leetcode::problem_947 {

namespace {

class DSU {
 public:
  explicit DSU(int n) : parent_(n), rank_(n, 0) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int find(int x) {
    if (parent_[x] != x) parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  void unite(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return;
    if (rank_[ra] < rank_[rb]) {
      parent_[ra] = rb;
    } else if (rank_[ra] > rank_[rb]) {
      parent_[rb] = ra;
    } else {
      parent_[rb] = ra;
      ++rank_[ra];
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

int removeStonesImpl(std::vector<std::vector<int>>& stones) {
  const int kOffset =
      10001;  // y <= 10000, so y + kOffset keeps columns distinct from rows.
  int n = static_cast<int>(stones.size());
  DSU dsu(kOffset + 10000 + 1);  // index range [0, 20001]
  std::unordered_set<int> seen;

  for (const auto& stone : stones) {
    int row = stone[0];              // 0..10000
    int col = stone[1] + kOffset;    // 10001..20001
    dsu.unite(row, col);
    seen.insert(row);
    seen.insert(col);
  }

  std::unordered_set<int> roots;
  for (int node : seen) {
    roots.insert(dsu.find(node));
  }
  // Number of connected components among rows/columns that hold stones.
  // Each component keeps exactly one stone; the rest can be removed.
  return n - static_cast<int>(roots.size());
}

}  // namespace

MostStonesRemovedWithSameRowOrColumnSolution::
    MostStonesRemovedWithSameRowOrColumnSolution() {
  setMetaInfo({.id = 947,
               .title = "Most Stones Removed with Same Row or Column",
               .url =
                   "https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/"});
  registerStrategy({.name = "union-find",
                    .expected = "Accepted",
                    .time_complexity = "O(n * alpha(n))",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "Depth-First Search", "Union-Find",
                             "Graph Theory"}},
                   removeStonesImpl);
}

int MostStonesRemovedWithSameRowOrColumnSolution::removeStones(
    std::vector<std::vector<int>>& stones) {
  return getSolution()(stones);
}

}  // namespace leetcode::problem_947

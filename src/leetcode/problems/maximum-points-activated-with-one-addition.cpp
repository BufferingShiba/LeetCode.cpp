#include "leetcode/problems/maximum-points-activated-with-one-addition.h"

#include <algorithm>
#include <cstdint>
#include <unordered_map>

namespace leetcode::problem_3873 {
namespace {

// Union-Find (Disjoint Set Union) helper.
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
    if (rank_[ra] < rank_[rb]) std::swap(ra, rb);
    parent_[rb] = ra;
    if (rank_[ra] == rank_[rb]) ++rank_[ra];
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

int maxActivatedImpl(std::vector<std::vector<int>>& points) {
  const int n = static_cast<int>(points.size());
  if (n == 0) return 0;

  // Discrete the coordinates into node ids. To keep x and y disjoint, we
  // offset y-coordinates by a large constant (beyond the coordinate range).
  std::unordered_map<int64_t, int> coordToId;
  const int64_t Y_OFFSET = 2000000002LL;

  int nextId = 0;
  auto getId = [&](int64_t c) -> int {
    auto it = coordToId.find(c);
    if (it != coordToId.end()) return it->second;
    coordToId[c] = nextId;
    return nextId++;
  };

  // At most 2n distinct coordinate nodes (each point has one x and one y).
  DSU dsu(2 * n);

  // Each point (x, y) is an edge x -- y.
  for (auto& p : points) {
    int64_t x = p[0];
    int64_t y = static_cast<int64_t>(p[1]) + Y_OFFSET;
    int idx = getId(x);
    int idy = getId(y);
    dsu.unite(idx, idy);
  }

  // Count the number of original points contributed to each component.
  std::unordered_map<int, int> compSize;
  compSize.reserve(n);
  for (auto& p : points) {
    int64_t x = p[0];
    int64_t y = static_cast<int64_t>(p[1]) + Y_OFFSET;
    int root = dsu.find(getId(x));
    ++compSize[root];
  }

  // Find the largest and second largest component sizes.
  int largest = 0, second = 0;
  for (auto& kv : compSize) {
    int sz = kv.second;
    if (sz > largest) {
      second = largest;
      largest = sz;
    } else if (sz > second) {
      second = sz;
    }
  }

  // Answer = largest + second + 1. If only one component, second == 0.
  return largest + second + 1;
}

}  // namespace

MaximumPointsActivatedWithOneAdditionSolution::
    MaximumPointsActivatedWithOneAdditionSolution()
    : SolutionBase() {
  setMetaInfo({
      .id = 3873,
      .title = "Maximum Points Activated with One Addition",
      .url = "https://leetcode.com/problems/maximum-points-activated-with-one-addition/",
  });
  registerStrategy(
      {
          "union-find-components",
          "Accepted",
          "O(n α(n))",
          "O(n)",
          {"Array", "Hash Table", "Union-Find"},
          "Model each point as an edge in a bipartite graph over x/y "
          "coords; adding one point activates the union of the two "
          "components it connects, so answer = largest + second_largest "
          "component sizes + 1.",
      },
      maxActivatedImpl);
}

int MaximumPointsActivatedWithOneAdditionSolution::maxActivated(
    std::vector<std::vector<int>>& points) {
  return getSolution()(points);
}

}  // namespace leetcode::problem_3873

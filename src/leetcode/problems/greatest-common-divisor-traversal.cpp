#include "leetcode/problems/greatest-common-divisor-traversal.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_2709 {
namespace {

class DSU {
 public:
  explicit DSU(int n) : parent_(n), size_(n, 1) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  int find(int x) {
    if (parent_[x] != x) parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size_[a] < size_[b]) std::swap(a, b);
    parent_[b] = a;
    size_[a] += size_[b];
  }

 private:
  std::vector<int> parent_;
  std::vector<int> size_;
};

bool canTraverseAllPairsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n == 1) return true;

  int maxVal = 0;
  for (int x : nums) maxVal = std::max(maxVal, x);

  // Nodes: indices 0..n-1 are the nums indices.
  // Nodes n+p are dummy prime nodes for prime value p.
  DSU dsu(n + maxVal + 1);

  for (int i = 0; i < n; ++i) {
    int x = nums[i];
    for (int f = 2; f * f <= x; ++f) {
      if (x % f == 0) {
        dsu.unite(i, n + f);
        while (x % f == 0) x /= f;
      }
    }
    if (x > 1) {
      dsu.unite(i, n + x);
    }
  }

  int root = dsu.find(0);
  for (int i = 1; i < n; ++i) {
    if (dsu.find(i) != root) return false;
  }
  return true;
}

}  // namespace

GreatestCommonDivisorTraversalSolution::
    GreatestCommonDivisorTraversalSolution() {
  setMetaInfo({.id = 2709,
               .title = "Greatest Common Divisor Traversal",
               .url = "https://leetcode.com/problems/greatest-common-divisor-traversal/"});
  registerStrategy(
      {"UnionFind+PrimeFactorization", "Accepted", "O(n*sqrt(maxVal))",
       "O(maxVal + n)",
       {"Array", "Math", "Union-Find", "Number Theory"}},
      canTraverseAllPairsImpl);
}

bool GreatestCommonDivisorTraversalSolution::canTraverseAllPairs(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2709
}  // namespace leetcode

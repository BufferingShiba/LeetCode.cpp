#include "leetcode/problems/largest-component-size-by-common-factor.h"

#include <vector>

namespace leetcode {
namespace problem_952 {
namespace {

// Union-Find with path compression and union by size.
class DSU {
 public:
  explicit DSU(int n) : parent(n), size(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int x) {
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];  // path halving
      x = parent[x];
    }
    return x;
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (size[a] < size[b]) std::swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }

 private:
  std::vector<int> parent;
  std::vector<int> size;
};

/**
 * Strategy: SPF sieve + Union-Find over distinct prime factors.
 *
 * Two numbers belong to the same connected component iff they share
 * some prime factor. We use each number's prime factors as intermediate
 * nodes in a DSU: reaching a prime factor connects all numbers having it.
 *
 * After processing, each genuine number nodes' root is determined; the
 * largest set of number nodes sharing a root is the answer (prime nodes
 * are ignored).
 */
int largestComponentSizeByCommonFactor(std::vector<int>& nums) {
  const int maxVal = *std::max_element(nums.begin(), nums.end());

  // Smallest prime factor sieve.
  std::vector<int> spf(maxVal + 1, 0);
  for (int i = 2; i <= maxVal; i++) {
    if (spf[i] == 0) {
      for (int j = i; j <= maxVal; j += i) {
        if (spf[j] == 0) spf[j] = i;
      }
    }
  }

  const int numCount = static_cast<int>(nums.size());
  DSU dsu(numCount + maxVal + 1);

  for (int i = 0; i < numCount; i++) {
    int x = nums[i];
    int firstPrime = -1;
    while (x > 1) {
      int p = spf[x];
      if (firstPrime == -1) {
        firstPrime = p;
        dsu.unite(i, numCount + p);
      } else {
        dsu.unite(numCount + p, numCount + firstPrime);
      }
      while (x % p == 0) x /= p;
    }
  }

  // Count, for each root, how many genuine number nodes belong to it.
  std::vector<int> count(numCount + maxVal + 1, 0);
  for (int i = 0; i < numCount; i++) {
    count[dsu.find(i)]++;
  }

  int best = 0;
  for (int i = 0; i < numCount + maxVal + 1; i++) {
    best = std::max(best, count[i]);
  }
  return best;
}

}  // namespace

LargestComponentSizeByCommonFactorSolution::
    LargestComponentSizeByCommonFactorSolution() {
  setMetaInfo({.id = 952,
               .title = "Largest Component Size by Common Factor",
               .url =
                   "https://leetcode.com/problems/largest-component-size-by-common-factor/"});

  registerStrategy(
      {.name = "SPF sieve + Union-Find",
       .expected = "Accepted",
       .time_complexity = "O(n log maxVal)",
       .space_complexity = "O(maxVal)",
       .tags = {"Union-Find", "Math", "Hash Table", "Number Theory"}},
      largestComponentSizeByCommonFactor);
}

int LargestComponentSizeByCommonFactorSolution::largestComponentSize(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_952
}  // namespace leetcode

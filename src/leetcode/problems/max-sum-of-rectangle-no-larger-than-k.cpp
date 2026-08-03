#include "leetcode/problems/max-sum-of-rectangle-no-larger-than-k.h"

#include <algorithm>
#include <climits>
#include <set>
#include <vector>

namespace leetcode {
namespace problem_363 {
namespace {

int maxSumSubmatrixImpl(std::vector<std::vector<int>>& matrix, int k) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());
  int best = INT_MIN;

  for (int top = 0; top < m; ++top) {
    std::vector<int> colSum(n, 0);
    for (int bottom = top; bottom < m; ++bottom) {
      for (int j = 0; j < n; ++j) {
        colSum[j] += matrix[bottom][j];
      }

      // 1D: find max subarray sum <= k over colSum.
      // prefix sum with ordered set lower_bound.
      std::set<int> prefixes;
      prefixes.insert(0);
      int prefix = 0;
      for (int j = 0; j < n; ++j) {
        prefix += colSum[j];
        // Need prefix[t] >= prefix - k, and maximize prefix - prefix[t].
        auto it = prefixes.lower_bound(prefix - k);
        if (it != prefixes.end()) {
          best = std::max(best, prefix - *it);
        }
        prefixes.insert(prefix);
      }
    }
  }

  return best;
}

}  // namespace

MaxSumOfRectangleNoLargerThanKSolution::MaxSumOfRectangleNoLargerThanKSolution() {
  setMetaInfo({.id = 363,
               .title = "Max Sum of Rectangle No Larger Than K",
               .url = "https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/"});
  registerStrategy(
      {.name = "PrefixSum + OrderedSet",
       .expected = "Accepted",
       .time_complexity = "O(m^2 * n * log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search", "Matrix", "Prefix Sum", "Ordered Set"}},
      maxSumSubmatrixImpl);
}

int MaxSumOfRectangleNoLargerThanKSolution::maxSumSubmatrix(
    std::vector<std::vector<int>>& matrix, int k) {
  return getSolution()(matrix, k);
}

}  // namespace problem_363
}  // namespace leetcode

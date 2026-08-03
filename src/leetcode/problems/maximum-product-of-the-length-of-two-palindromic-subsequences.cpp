#include "leetcode/problems/maximum-product-of-the-length-of-two-palindromic-subsequences.h"

#include <cmath>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2002 {

namespace {

int maxProductImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  const int total = 1 << n;

  // precompute isPal[mask] and len[mask]
  std::vector<bool> isPal(total, false);
  std::vector<int> len(total, 0);

  for (int mask = 0; mask < total; ++mask) {
    // build subsequence
    int l = 0, r = n - 1;
    bool ok = true;
    int sz = 0;

    // find leftmost and rightmost selected indices, compare inward
    int lo = -1, hi = -1;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        ++sz;
        if (lo == -1) lo = i;
        hi = i;
      }
    }

    // check palindrome by two pointers on selected indices
    int i = lo, j = hi;
    while (i < j && ok) {
      while (i < j && !(mask & (1 << i))) ++i;
      while (i < j && !(mask & (1 << j))) --j;
      if (i < j) {
        if (s[i] != s[j]) ok = false;
        ++i;
        --j;
      }
    }

    isPal[mask] = ok;
    len[mask] = sz;
  }

  int best = 0;
  const int all = total - 1;

  for (int mask1 = 1; mask1 < total; ++mask1) {
    if (!isPal[mask1]) continue;
    const int comp = all ^ mask1;
    // enumerate submasks of comp
    for (int mask2 = comp; mask2 > 0; mask2 = (mask2 - 1) & comp) {
      if (mask2 == 0) break;
      if (isPal[mask2]) {
        best = std::max(best, len[mask1] * len[mask2]);
      }
    }
    // mask2 == 0 case: empty subsequence contributes 0, skip
  }

  return best;
}

}  // namespace

MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution::
    MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution() {
  setMetaInfo({.id = 2002,
               .title = "Maximum Product of the Length of Two Palindromic "
                        "Subsequences",
               .url = "https://leetcode.com/problems/"
                      "maximum-product-of-the-length-of-two-palindromic-"
                      "subsequences/"});
  registerStrategy(
      {.name = "bitmask_enumeration",
       .expected = "Accepted",
       .time_complexity = "O(3^n + n*2^n)",
       .space_complexity = "O(2^n)",
       .tags = {"Bitmask", "String", "Backtracking"},
       .notes = "Enumerate all disjoint mask pairs; check palindrome via "
                "precomputed table."},
      maxProductImpl);
}

int MaximumProductOfTheLengthOfTwoPalindromicSubsequencesSolution::maxProduct(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2002
}  // namespace leetcode

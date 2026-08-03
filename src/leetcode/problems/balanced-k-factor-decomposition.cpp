#include "leetcode/problems/balanced-k-factor-decomposition.h"

#include <algorithm>
#include <limits>

namespace leetcode::problem_3669 {
namespace {

std::vector<int> minDifferenceImpl(int n, int k) {
  // Collect all positive divisors of n.
  std::vector<int> divisors;
  for (int d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      divisors.push_back(d);
      if (d != n / d) divisors.push_back(n / d);
    }
  }
  std::sort(divisors.begin(), divisors.end());

  long long bestDiff = std::numeric_limits<long long>::max();
  std::vector<int> best;
  std::vector<int> cur(k);

  // DFS over divisor indices, non-decreasing, allowing repetition of the same
  // divisor value. product grows monotonically so we prune once it exceeds n.
  std::function<void(int, int, long long)> dfs = [&](int start, int depth,
                                                     long long prod) {
    if (depth == k) {
      if (prod == n) {
        long long mn = *std::min_element(cur.begin(), cur.end());
        long long mx = *std::max_element(cur.begin(), cur.end());
        long long diff = mx - mn;
        if (diff < bestDiff) {
          bestDiff = diff;
          best = cur;
        }
      }
      return;
    }
    for (int i = start; i < static_cast<int>(divisors.size()); ++i) {
      long long next = prod * divisors[i];
      if (next > n) break;  // divisors are sorted ascending; further are larger
      // Remaining multiplicands must all be >= 1, product must not exceed n.
      cur[depth] = divisors[i];
      dfs(i, depth + 1, next);
    }
  };

  dfs(0, 0, 1);
  return best;
}

}  // namespace

BalancedKFactorDecompositionSolution::BalancedKFactorDecompositionSolution() {
  setMetaInfo({.id = 3669,
               .title = "Balanced K-Factor Decomposition",
               .url = "https://leetcode.com/problems/balanced-k-factor-decomposition/"});
  registerStrategy({.name = "Backtracking over divisors",
                    .expected = "Accepted",
                    .time_complexity = "O(D^k)",
                    .space_complexity = "O(D + k)",
                    .tags = {"Backtracking", "Number Theory"}},
                   minDifferenceImpl);
}

std::vector<int> BalancedKFactorDecompositionSolution::minDifference(int n,
                                                                     int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_3669

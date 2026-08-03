#include "leetcode/problems/valid-permutations-for-di-sequence.h"

#include <vector>

namespace leetcode {
namespace problem_903 {

namespace {

constexpr int kMod = 1000000007;

int numPermsDISequenceImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  // dp[j] = number of valid prefixes of length i+1 whose last element
  // has rank j among the used elements, j in [0, i].
  std::vector<int> dp(n + 1, 0);
  dp[0] = 1;  // length-1 prefix: single element, rank 0.

  for (int i = 1; i <= n; ++i) {
    std::vector<int> next(i + 1, 0);
    // prefix sums of current dp over ranks 0..i-1.
    std::vector<int> pref(i, 0);
    int running = 0;
    for (int k = 0; k < i; ++k) {
      running += dp[k];
      if (running >= kMod) running -= kMod;
      pref[k] = running;
    }

    if (s[i - 1] == 'I') {
      // Increasing: new last rank j must be > old rank, j in [1, i].
      // dp[i][j] = sum_{k=0}^{j-1} dp[i-1][k]
      for (int j = 1; j <= i; ++j) {
        next[j] = pref[j - 1];
      }
    } else {
      // Decreasing: new last rank j must be <= old rank, j in [0, i-1].
      // dp[i][j] = sum_{k=j}^{i-1} dp[i-1][k]
      int suffix = 0;
      for (int j = i - 1; j >= 0; --j) {
        suffix += dp[j];
        if (suffix >= kMod) suffix -= kMod;
        next[j] = suffix;
      }
    }
    dp = std::move(next);
  }

  int ans = 0;
  for (int v : dp) {
    ans += v;
    if (ans >= kMod) ans -= kMod;
  }
  return ans;
}

}  // namespace

ValidPermutationsForDiSequenceSolution::ValidPermutationsForDiSequenceSolution() {
  setMetaInfo({.id = 903,
               .title = "Valid Permutations for DI Sequence",
               .url = "https://leetcode.com/problems/valid-permutations-for-di-sequence/"});
  registerStrategy(
      {.name = "dp-prefix-sum",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Prefix Sum"}},
      numPermsDISequenceImpl);
}

int ValidPermutationsForDiSequenceSolution::numPermsDISequence(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_903
}  // namespace leetcode

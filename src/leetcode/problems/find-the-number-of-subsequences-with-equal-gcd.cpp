#include <cstring>
#include <vector>

#include "leetcode/problems/find-the-number-of-subsequences-with-equal-gcd.h"

namespace leetcode {
namespace problem_3336 {
namespace {

const int kMod = 1000000007;
const int kMaxG = 200;
const int kSz = kMaxG + 1;  // 201

int gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}

// Each element goes to seq1, seq2, or neither. Track (g1, g2) = GCDs using a
// flat dp array. dp[g1*kSz+g2] = number of ways to reach that state.
// Answer = sum dp[g][g] for g >= 1 (both non-empty, equal GCD).
int subsequencePairCountImpl(std::vector<int>& nums) {
  static int dp[kSz * kSz];
  static int ndp[kSz * kSz];
  std::memset(dp, 0, sizeof(dp));
  dp[0] = 1;  // empty state marker (g1=0, g2=0)

  for (int x : nums) {
    std::memset(ndp, 0, sizeof(ndp));
    for (int g1 = 0; g1 <= kMaxG; ++g1) {
      const int rowOff = g1 * kSz;
      for (int g2 = 0; g2 <= kMaxG; ++g2) {
        int cur = dp[rowOff + g2];
        if (cur == 0) continue;
        // 1) skip
        ndp[rowOff + g2] = (ndp[rowOff + g2] + cur) % kMod;
        // 2) put into seq1
        {
          int ng1 = (g1 == 0) ? x : gcd(g1, x);
          int& dst = ndp[ng1 * kSz + g2];
          dst = (dst + cur) % kMod;
        }
        // 3) put into seq2
        {
          int ng2 = (g2 == 0) ? x : gcd(g2, x);
          int& dst = ndp[rowOff + ng2];
          dst = (dst + cur) % kMod;
        }
      }
    }
    std::memcpy(dp, ndp, sizeof(dp));
  }

  long long ans = 0;
  for (int g = 1; g <= kMaxG; ++g) {
    ans += dp[g * kSz + g];
  }
  return static_cast<int>(ans % kMod);
}

}  // namespace

FindTheNumberOfSubsequencesWithEqualGcdSolution::
    FindTheNumberOfSubsequencesWithEqualGcdSolution() {
  setMetaInfo({.id = 3336,
               .title = "Find the Number of Subsequences With Equal GCD",
               .url = "https://leetcode.com/problems/find-the-number-of-"
                      "subsequences-with-equal-gcd/"});
  registerStrategy(
      {.name = "dp-gcd-pair",
       .expected = "Accepted",
       .time_complexity = "O(n * G^2)",
       .space_complexity = "O(G^2)",
       .tags = {"Dynamic Programming", "Number Theory", "Array"}},
      subsequencePairCountImpl);
}

int FindTheNumberOfSubsequencesWithEqualGcdSolution::subsequencePairCount(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3336
}  // namespace leetcode

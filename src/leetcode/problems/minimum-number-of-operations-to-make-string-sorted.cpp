#include "leetcode/problems/minimum-number-of-operations-to-make-string-sorted.h"

#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1830 {

namespace {

constexpr int kMod = 1000000007;

long long ModPow(long long base, long long exp, long long mod) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) res = res * base % mod;
    base = base * base % mod;
    exp >>= 1;
  }
  return res;
}

int makeStringSortedImpl(std::string s) {
  const int n = static_cast<int>(s.size());

  // fact[k] = k! mod p, inv_fact[k] = (k!)^-1 mod p
  std::vector<long long> fact(n + 1), inv_fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % kMod;
  inv_fact[n] = ModPow(fact[n], kMod - 2, kMod);
  for (int i = n; i >= 1; --i) inv_fact[i - 1] = inv_fact[i] * i % kMod;

  std::vector<int> cnt(26, 0);
  for (char ch : s) cnt[ch - 'a']++;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    const int cur = s[i] - 'a';
    const int rem = n - 1 - i;
    for (int c = 0; c < cur; ++c) {
      if (cnt[c] == 0) continue;
      // Place smallest available char c at position i, then permute the rest.
      long long ways = fact[rem];
      for (int ch = 0; ch < 26; ++ch) {
        const int count = cnt[ch] - (ch == c ? 1 : 0);
        ways = ways * inv_fact[count] % kMod;
      }
      ans = (ans + ways) % kMod;
    }
    cnt[cur]--;
  }
  return static_cast<int>(ans);
}

}  // namespace

MinimumNumberOfOperationsToMakeStringSortedSolution::
    MinimumNumberOfOperationsToMakeStringSortedSolution() {
  setMetaInfo({.id = 1830,
               .title = "Minimum Number of Operations to Make String Sorted",
               .url = "https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/"});
  registerStrategy(
      {.name = "LexicographicRank",
       .expected = "Accepted",
       .time_complexity = "O(26 * 26 * n)",
       .space_complexity = "O(26 + n)",
       .tags = {"Combinatorics", "Counting", "Math"}},
      makeStringSortedImpl);
}

int MinimumNumberOfOperationsToMakeStringSortedSolution::makeStringSorted(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1830

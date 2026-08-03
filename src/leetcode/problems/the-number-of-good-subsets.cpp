#include "leetcode/problems/the-number-of-good-subsets.h"

#include <cstdint>

namespace leetcode {
namespace problem_1994 {
namespace {

constexpr int64_t MOD = 1000000007;

std::vector<int64_t> buildPow2(int n) {
  std::vector<int64_t> p(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] * 2 % MOD;
  }
  return p;
}

int numberOfGoodSubsetsImpl(std::vector<int>& nums) {
  std::vector<int> cnt(31, 0);
  for (int v : nums) cnt[v]++;

  const auto pow2 = buildPow2(static_cast<int>(nums.size()));

  static const int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  static const int MAX_MASK = 1 << 10;

  // Precompute prime-bitmask for each value 2..30 (0 if not square-free).
  std::vector<int> maskOf(31, 0);
  std::vector<int> avail;
  for (int v = 2; v <= 30; ++v) {
    int x = v;
    int mask = 0;
    bool ok = true;
    for (int i = 0; i < 10; ++i) {
      int p = primes[i];
      int c = 0;
      while (x % p == 0) {
        x /= p;
        ++c;
      }
      if (c >= 2) {
        ok = false;
        break;
      }
      if (c == 1) mask |= (1 << i);
    }
    if (ok && mask != 0) {
      maskOf[v] = mask;
      avail.push_back(v);
    }
  }

  // dp[mask] = number of index-distinct ways to form prime-set mask.
  std::vector<int64_t> dp(MAX_MASK, 0);
  dp[0] = 1;
  for (int v : avail) {
    int m = maskOf[v];
    // Values with the same prime mask are interchangeable by value, but a
    // good subset can contain at most one copy of that value: two copies
    // would repeat every prime factor. Choose the index of that one copy.
    int64_t ways = cnt[v];
    for (int mask = MAX_MASK - 1; mask >= 0; --mask) {
      if (mask & m) continue;
      dp[mask | m] = (dp[mask | m] + dp[mask] * ways) % MOD;
    }
  }

  int64_t ans = 0;
  for (int mask = 1; mask < MAX_MASK; ++mask) {
    ans = (ans + dp[mask]) % MOD;
  }
  // Any good subset may additionally carry any subset of the 1's.
  ans = ans * pow2[cnt[1]] % MOD;
  return static_cast<int>(ans);
}

}  // namespace

TheNumberOfGoodSubsetsSolution::TheNumberOfGoodSubsetsSolution() {
  setMetaInfo({1994, "The Number of Good Subsets",
               "https://leetcode.com/problems/the-number-of-good-subsets/"});
  registerStrategy(
      {"bitmask-dp", "Accepted", "O(30 * 2^10)", "O(2^10)",
       {"Array", "Hash Table", "Math", "Dynamic Programming",
        "Bit Manipulation", "Counting", "Number Theory", "Bitmask"},
       "Frequency counting + DP over 10-bit prime masks; handle 1's separately."},
      numberOfGoodSubsetsImpl);
}

int TheNumberOfGoodSubsetsSolution::numberOfGoodSubsets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1994
}  // namespace leetcode

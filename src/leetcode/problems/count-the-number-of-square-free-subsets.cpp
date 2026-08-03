#include "leetcode/problems/count-the-number-of-square-free-subsets.h"

namespace leetcode {
namespace problem_2572 {

namespace {

const long long kMod = 1000000007LL;
const int kPrimes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int primeMask(int v) {
  int mask = 0;
  for (int i = 0; i < 10; ++i) {
    if (v % kPrimes[i] == 0) mask |= (1 << i);
  }
  return mask;
}

bool isSquareFree(int v) {
  for (int d = 2; d * d <= v; ++d) {
    if (v % (d * d) == 0) return false;
  }
  return true;
}

long long modPow(long long base, long long exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) res = res * base % kMod;
    base = base * base % kMod;
    exp >>= 1;
  }
  return res;
}

int squareFreeSubsetsImpl(std::vector<int>& nums) {
  std::vector<long long> cntMask(1 << 10, 0);
  long long ones = 0;
  for (int v : nums) {
    if (v == 1) {
      ++ones;
      continue;
    }
    if (!isSquareFree(v)) continue;
    ++cntMask[primeMask(v)];
  }

  std::vector<long long> dp(1 << 10, 0);
  dp[0] = 1;
  for (int mv = 0; mv < (1 << 10); ++mv) {
    int cnt = (int)cntMask[mv];
    if (cnt == 0) continue;
    std::vector<long long> ndp = dp;  // skip all occurrences of this value
    // Choosing two copies of the same value v produces v^2, which is NOT
    // square-free. So at most one copy of each distinct value can be used.
    long long ways = cnt;  // pick exactly one of the cnt copies
    for (int mask = 0; mask < (1 << 10); ++mask) {
      if ((mask & mv) == 0) {
        ndp[mask | mv] = (ndp[mask | mv] + dp[mask] * ways) % kMod;
      }
    }
    dp = std::move(ndp);
  }

  long long sum = 0;
  for (long long val : dp) sum = (sum + val) % kMod;
  long long ans = sum * modPow(2, ones) % kMod;
  ans = (ans - 1 + kMod) % kMod;  // subtract the fully-empty subset
  return (int)ans;
}

}  // namespace

CountTheNumberOfSquareFreeSubsetsSolution::CountTheNumberOfSquareFreeSubsetsSolution() {
  setMetaInfo({2572, "Count the Number of Square-Free Subsets",
               "https://leetcode.com/problems/count-the-number-of-square-free-subsets/"});
  registerStrategy({.name = "bitmask-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(2^10 * K), K<=19 distinct values",
                    .space_complexity = "O(2^10)",
                    .tags = {"Bitmask", "DP", "Number Theory"}},
                   squareFreeSubsetsImpl);
}

int CountTheNumberOfSquareFreeSubsetsSolution::squareFreeSubsets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2572
}  // namespace leetcode

#include "leetcode/problems/number-of-beautiful-partitions.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2478 {

namespace {

constexpr int MOD = 1'000'000'007;

bool isPrimeDigit(char ch) {
  return ch == '2' || ch == '3' || ch == '5' || ch == '7';
}

int beautifulPartitionsImpl(const std::string& s, int k, int minLength) {
  int n = static_cast<int>(s.size());

  // Quick rejection: each segment needs at least minLength chars
  if (static_cast<long long>(k) * minLength > n) {
    return 0;
  }

  // dp[j][i] = ways to partition first i chars into j valid segments
  // i ranges [0..n], j ranges [1..k]
  std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, 0));

  // Base: j = 1
  if (isPrimeDigit(s[0])) {
    for (int i = minLength; i <= n; ++i) {
      if (!isPrimeDigit(s[i - 1])) {
        dp[1][i] = 1;
      }
    }
  }

  // Transition: j >= 2
  for (int j = 2; j <= k; ++j) {
    // Build prefix sum: pref[t] = sum_{p=0..t, s[p] prime} dp[j-1][p]
    std::vector<long long> pref(n, 0);
    long long running = 0;
    for (int t = 0; t < n; ++t) {
      if (isPrimeDigit(s[t])) {
        running = (running + dp[j - 1][t]) % MOD;
      }
      pref[t] = running;
    }

    for (int i = 1; i <= n; ++i) {
      if (!isPrimeDigit(s[i - 1]) && i >= minLength) {
        int idx = i - minLength;  // max p such that segment length >= minLength
        if (idx >= 0 && idx < n) {
          dp[j][i] = static_cast<int>(pref[idx]);
        }
      }
    }
  }

  return dp[k][n];
}

}  // namespace

NumberOfBeautifulPartitionsSolution::NumberOfBeautifulPartitionsSolution() {
  setMetaInfo({.id = 2478,
               .title = "Number of Beautiful Partitions",
               .url = "https://leetcode.com/problems/number-of-beautiful-partitions/"});

  registerStrategy(
      {.name = "DP with Prefix Sum",
       .expected = "Accepted",
       .time_complexity = "O(n*k)",
       .space_complexity = "O(n*k)",
       .tags = {"String", "Dynamic Programming", "Prefix Sum"}},
      beautifulPartitionsImpl);
}

int NumberOfBeautifulPartitionsSolution::beautifulPartitions(
    const std::string& s, int k, int minLength) {
  return getSolution()(s, k, minLength);
}

}  // namespace problem_2478
}  // namespace leetcode

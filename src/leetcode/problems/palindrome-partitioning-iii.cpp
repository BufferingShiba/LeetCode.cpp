#include "leetcode/problems/palindrome-partitioning-iii.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_1278 {

namespace {

constexpr int kInf = 1000000000;

int palindromePartitionImpl(const std::string& s, int k) {
  const int n = static_cast<int>(s.size());

  // cost[i][j] = min changes to make s[i..j] a palindrome.
  std::vector<std::vector<int>> cost(n, std::vector<int>(n, 0));
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      const int j = i + len - 1;
      cost[i][j] = cost[i + 1][j - 1] + (s[i] != s[j] ? 1 : 0);
    }
  }

  // dp[p][i] = min changes to split s[0..i] into (p+1) palindrome substrings.
  // Only valid when p+1 <= i+1, i.e., i >= p; invalid states stay at kInf.
  std::vector<std::vector<int>> dp(k, std::vector<int>(n, kInf));

  // p == 0: a single substring covers all of s[0..i].
  for (int i = 0; i < n; ++i) {
    dp[0][i] = cost[0][i];
  }

  for (int p = 1; p < k; ++p) {
    // Need s[0..i] to hold p+1 non-empty substrings, so i >= p.
    for (int i = p; i < n; ++i) {
      // Last substring is s[j+1..i]; s[0..j] holds p substrings, so j >= p-1.
      for (int j = p - 1; j < i; ++j) {
        if (dp[p - 1][j] < kInf) {
          dp[p][i] = std::min(dp[p][i], dp[p - 1][j] + cost[j + 1][i]);
        }
      }
    }
  }

  return dp[k - 1][n - 1];
}

}  // namespace

PalindromePartitioningIiiSolution::PalindromePartitioningIiiSolution() {
  setMetaInfo({.id = 1278,
               .title = "Palindrome Partitioning III",
               .url = "https://leetcode.com/problems/palindrome-partitioning-iii/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(k*n^2)",
                    .space_complexity = "O(k*n)",
                    .tags = {"String", "Dynamic Programming"}},
                   &palindromePartitionImpl);
}

int PalindromePartitioningIiiSolution::palindromePartition(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace leetcode::problem_1278

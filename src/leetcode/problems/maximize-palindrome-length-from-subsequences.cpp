#include "leetcode/problems/maximize-palindrome-length-from-subsequences.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_1771 {

namespace {

int longestPalindromeImpl(const std::string& word1, const std::string& word2) {
  const std::string s = word1 + word2;
  const int n = static_cast<int>(s.size());
  const int n1 = static_cast<int>(word1.size());

  // dp[i][j] = length of longest palindromic subsequence in s[i..j].
  std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
  for (int i = n - 1; i >= 0; --i) {
    dp[i][i] = 1;
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        dp[i][j] = (i + 1 <= j - 1) ? dp[i + 1][j - 1] + 2 : 2;
      } else {
        dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }

  int best = 0;
  for (int i = 0; i < n1; ++i) {
    for (int j = n1; j < n; ++j) {
      if (s[i] == s[j]) {
        int inner = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
        best = std::max(best, inner + 2);
      }
    }
  }
  return best;
}

}  // namespace

MaximizePalindromeLengthFromSubsequencesSolution::
    MaximizePalindromeLengthFromSubsequencesSolution() {
  this->setMetaInfo({.id = 1771,
                     .title = "Maximize Palindrome Length From Subsequences",
                     .url =
                         "https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/"});
  this->registerStrategy(
      {.name = "interval-dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"String", "Dynamic Programming"}},
      longestPalindromeImpl);
}

int MaximizePalindromeLengthFromSubsequencesSolution::longestPalindrome(
    std::string word1, std::string word2) {
  return this->getSolution()(word1, word2);
}

}  // namespace leetcode::problem_1771

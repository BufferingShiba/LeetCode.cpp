#include "leetcode/problems/longest-common-subsequence.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_1143 {

namespace {

int longestCommonSubsequenceImpl(const std::string& text1,
                                 const std::string& text2) {
  const int m = static_cast<int>(text1.size());
  const int n = static_cast<int>(text2.size());
  std::vector<int> dp(n + 1, 0);
  for (int i = 1; i <= m; ++i) {
    int prev = 0;  // dp[i-1][j-1]
    for (int j = 1; j <= n; ++j) {
      const int temp = dp[j];  // dp[i-1][j]
      if (text1[i - 1] == text2[j - 1]) {
        dp[j] = prev + 1;
      } else {
        dp[j] = std::max(dp[j], dp[j - 1]);
      }
      prev = temp;
    }
  }
  return dp[n];
}

}  // namespace

LongestCommonSubsequenceSolution::LongestCommonSubsequenceSolution() {
  setMetaInfo({.id = 1143,
               .title = "Longest Common Subsequence",
               .url =
                   "https://leetcode.com/problems/longest-common-"
                   "subsequence/"});
  registerStrategy(
      {.name = "dp_rolling_array",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Dynamic Programming"},
       .notes =
           "Classic LCS DP with rolling array; dp[j] = LCS of text1[0..i) and "
           "text2[0..j)."},
      longestCommonSubsequenceImpl);
}

int LongestCommonSubsequenceSolution::longestCommonSubsequence(
    std::string text1, std::string text2) {
  return getSolution()(text1, text2);
}

}  // namespace leetcode::problem_1143

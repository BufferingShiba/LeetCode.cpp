#include "leetcode/problems/maximum-deletions-on-a-string.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_2430 {

namespace {

int deleteStringDpLcp(const std::string& s) {
  const int n = static_cast<int>(s.size());
  // lcp[i][j] = length of the longest common prefix of s.substr(i) and s.substr(j).
  std::vector<std::vector<int>> lcp(n + 1, std::vector<int>(n + 1, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
    }
  }

  // dp[i] = maximum deletions to clear substring starting at i.
  std::vector<int> dp(n, 1);
  for (int i = n - 1; i >= 0; --i) {
    int best = 1;
    const int maxLen = (n - i) / 2;
    for (int j = i + 1; j <= i + maxLen; ++j) {
      // s[i..j) equals s[j..2j-i) ?
      if (lcp[i][j] >= j - i) {
        best = std::max(best, dp[j] + 1);
      }
    }
    dp[i] = best;
  }
  return dp[0];
}

}  // namespace

MaximumDeletionsOnAStringSolution::MaximumDeletionsOnAStringSolution() {
  setMetaInfo({.id = 2430,
               .title = "Maximum Deletions on a String",
               .url = "https://leetcode.com/problems/maximum-deletions-on-a-string/"});
  registerStrategy(
      {.name = "dp_lcp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"String", "Dynamic Programming"},
       .notes = "DP + LCP table"},
      deleteStringDpLcp);
}

int MaximumDeletionsOnAStringSolution::deleteString(const std::string& s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2430

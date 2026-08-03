#include "leetcode/problems/regular-expression-matching.h"

#include <vector>

namespace leetcode {
namespace problem_10 {

// 二维 DP：dp[i][j] 表示 s[0..i) 与 p[0..j) 是否匹配。
// 时间复杂度 O(s.length * p.length)，空间复杂度 O(s.length * p.length)。
static bool isMatchImpl(std::string s, std::string p) {
  int m = static_cast<int>(s.size());
  int n = static_cast<int>(p.size());

  std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
  dp[0][0] = true;

  // 空串 s 对模式 p 的基线：只有当 p 形如 a*b*c*... 时才能匹配空串。
  for (int j = 2; j <= n; ++j) {
    if (p[j - 1] == '*') {
      dp[0][j] = dp[0][j - 2];
    }
  }

  auto matches = [&](char a, char b) -> bool {
    return b == '.' || a == b;
  };

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[j - 1] == '*') {
        // '*' 匹配零次，或用之前的字符匹配一次（依赖 dp[i-1][j]）。
        dp[i][j] = dp[i][j - 2] ||
                   (matches(s[i - 1], p[j - 2]) && dp[i - 1][j]);
      } else {
        dp[i][j] = matches(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
      }
    }
  }

  return dp[m][n];
}

RegularExpressionMatchingSolution::RegularExpressionMatchingSolution() {
  setMetaInfo({.id = 10,
               .title = "Regular Expression Matching",
               .url = "https://leetcode.com/problems/regular-expression-matching/"});
  registerStrategy(
      {.name = "dynamic_programming",
       .expected = "Accepted",
       .time_complexity = "O(s.length * p.length)",
       .space_complexity = "O(s.length * p.length)",
       .tags = {"String", "Dynamic Programming", "Recursion"}},
      isMatchImpl);
}

}  // namespace problem_10
}  // namespace leetcode

#include "leetcode/problems/find-maximum-removals-from-source-string.h"

#include <algorithm>

namespace leetcode::problem_3316 {

namespace {

// dp[j]: 处理 source 前缀后，匹配 pattern 前 j 个字符所能达到的最大移除数。
// 对每个 source 字符有两种选择：
//   1) 跳过（不作为 pattern 匹配字符）：若它在 targetIndices 中则可移除 +1；
//   2) 用于匹配 pattern[j-1]（需字符相等）：不移除。
int maxRemovalsImpl(std::string source, std::string pattern,
                    std::vector<int>& targetIndices) {
  const int n = static_cast<int>(source.size());
  const int m = static_cast<int>(pattern.size());

  std::vector<bool> isTarget(n, false);
  for (int idx : targetIndices) {
    isTarget[idx] = true;
  }

  const int kNEG = -1000000000;
  std::vector<int> dp(m + 1, kNEG);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
    std::vector<int> ndp(m + 1);
    // 跳过当前字符（可移除得分）
    for (int j = 0; j <= m; ++j) {
      ndp[j] = dp[j] + (isTarget[i] ? 1 : 0);
    }
    // 用当前字符匹配 pattern[j-1]
    for (int j = 1; j <= m; ++j) {
      if (source[i] == pattern[j - 1]) {
        ndp[j] = std::max(ndp[j], dp[j - 1]);
      }
    }
    dp = std::move(ndp);
  }

  return dp[m];
}

}  // namespace

int FindMaximumRemovalsFromSourceStringSolution::maxRemovals(
    std::string source, std::string pattern, std::vector<int>& targetIndices) {
  return getSolution()(std::move(source), std::move(pattern), targetIndices);
}

FindMaximumRemovalsFromSourceStringSolution::
    FindMaximumRemovalsFromSourceStringSolution() {
  setMetaInfo(
      {.id = 3316,
       .title = "Find Maximum Removals From Source String",
       .url = "https://leetcode.com/problems/"
              "find-maximum-removals-from-source-string/"});
  registerStrategy(
      {.name =
           "dynamic_programming",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(m)",
       .tags = {"Dynamic Programming", "String"}},
      maxRemovalsImpl);
}

}  // namespace leetcode::problem_3316

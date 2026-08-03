#include "leetcode/problems/number-of-ways-to-separate-numbers.h"

#include <cstdint>
#include <vector>

namespace leetcode {
namespace problem_1977 {

namespace {

const int kMod = 1000000007;

// 静态自由策略函数：DP + LCP 前缀比较 + 前缀和优化，O(n^2)
int numberOfCombinationsImpl(const std::string& num) {
  const int n = static_cast<int>(num.size());

  // lcp[i][j]：从 num[i] 和 num[j] 开始的最长公共前缀长度
  std::vector<std::vector<std::uint16_t>> lcp(
      n + 1, std::vector<std::uint16_t>(n + 1, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (num[i] == num[j]) {
        lcp[i][j] = static_cast<std::uint16_t>(lcp[i + 1][j + 1] + 1);
      }
    }
  }

  // dp[e][len]：以位置 e 为右端点、最后一段为 num[e-len..e-1] 的划分方案数
  // pref[e][k]：sum_{len<=k} dp[e][len]（扩展到所有 k，k>e 时保持总数）
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
  std::vector<std::vector<int>> pref(n + 1, std::vector<int>(n + 1, 0));

  for (int e = 1; e <= n; ++e) {
    for (int len = 1; len <= e; ++len) {
      const int r = e - len;  // 当前段左边界，也是上一段的右端点
      // 任何以 '0' 开头的段都非法（值 0 非正数，或含前导零）
      if (num[r] == '0') {
        dp[e][len] = 0;
        continue;
      }

      long long ways = 0;
      if (r == 0) {
        // 整段作为一个数字，独立成一种方案
        ways = 1;
      } else {
        // 上一段长度 pl < len：直接累加 pref[r][len-1]
        ways = (ways + pref[r][len - 1]) % kMod;
        // 上一段长度 pl == len：需保证上一段 <= 当前段，用 lcp 的 O(1) 比较
        if (len <= r) {
          const int lp = lcp[r - len][r];
          bool prevLeqCur = false;
          if (lp >= len) {
            prevLeqCur = true;  // 两段相等
          } else {
            prevLeqCur = (num[r - len + lp] <= num[r + lp]);
          }
          if (prevLeqCur) {
            ways = (ways + dp[r][len]) % kMod;
          }
        }
      }
      dp[e][len] = static_cast<int>(ways % kMod);
    }

    // 维护第 e 行的前缀和，扩展到所有 len（len > e 时沿用总数）
    long long acc = 0;
    for (int len = 1; len <= n; ++len) {
      if (len <= e) {
        acc += dp[e][len];
        if (acc >= kMod) acc -= kMod;
      }
      pref[e][len] = static_cast<int>(acc);
    }
  }

  long long ans = 0;
  for (int len = 1; len <= n; ++len) {
    ans += dp[n][len];
    if (ans >= kMod) ans -= kMod;
  }
  return static_cast<int>(ans % kMod);
}

}  // namespace

int NumberOfWaysToSeparateNumbersSolution::numberOfCombinations(
    std::string num) {
  return getSolution()(std::move(num));
}

NumberOfWaysToSeparateNumbersSolution::NumberOfWaysToSeparateNumbersSolution() {
  setMetaInfo({.id = 1977,
               .title = "Number of Ways to Separate Numbers",
               .url = "https://leetcode.com/problems/number-of-ways-to-separate-numbers/"});
  registerStrategy(
      {.name = "dp-lcp-prefix", .expected = "Accepted",
       .time_complexity = "O(n^2)", .space_complexity = "O(n^2)",
       .tags = {"String", "Dynamic Programming", "Prefix Sum"}},
      [this](std::string num) { return numberOfCombinationsImpl(num); });
}

}  // namespace problem_1977
}  // namespace leetcode

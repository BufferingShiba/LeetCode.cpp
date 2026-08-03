#include "leetcode/problems/restore-the-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1416 {

static int numberOfArraysImpl(std::string s, int k) {
  constexpr int MOD = 1000000007;
  int n = static_cast<int>(s.size());
  std::vector<int> dp(n + 1, 0);
  dp[n] = 1;  // empty suffix

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      dp[i] = 0;
      continue;
    }
    long long val = 0;
    int ways = 0;
    for (int j = i; j < n; ++j) {
      val = val * 10 + (s[j] - '0');
      if (val > k) break;
      ways = (ways + dp[j + 1]) % MOD;
    }
    dp[i] = ways;
  }

  return dp[0];
}

RestoreTheArraySolution::RestoreTheArraySolution() {
  setMetaInfo({.id = 1416, .title = "Restore The Array",
               .url = "https://leetcode.com/problems/restore-the-array/"});
  registerStrategy(
      {.name = "DP",
       .expected = "Accepted",
       .time_complexity = "O(n * log10(k))",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "String"}},
      numberOfArraysImpl);
}

int RestoreTheArraySolution::numberOfArrays(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_1416
}  // namespace leetcode

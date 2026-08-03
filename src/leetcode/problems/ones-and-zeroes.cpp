#include "leetcode/problems/ones-and-zeroes.h"

namespace leetcode::problem_474 {

namespace {

int findMaxFormImpl(std::vector<std::string>& strs, int m, int n) {
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
  for (const auto& s : strs) {
    int zeros = 0;
    for (char c : s) if (c == '0') ++zeros;
    int ones = static_cast<int>(s.size()) - zeros;
    for (int j = m; j >= zeros; --j) {
      for (int k = n; k >= ones; --k) {
        dp[j][k] = std::max(dp[j][k], dp[j - zeros][k - ones] + 1);
      }
    }
  }
  return dp[m][n];
}

}  // namespace

int OnesAndZeroesSolution::findMaxForm(std::vector<std::string>& strs, int m, int n) {
  return getSolution()(strs, m, n);
}

OnesAndZeroesSolution::OnesAndZeroesSolution() {
  setMetaInfo({.id = 474, .title = "Ones and Zeroes", .url = "https://leetcode.com/problems/ones-and-zeroes/"});
  registerStrategy(
      {.name = "2D-knapsack-dp", .expected = "Accepted", .time_complexity = "O(len * m * n)",
       .space_complexity = "O(m * n)", .tags = {"Array", "String", "Dynamic Programming"}},
      findMaxFormImpl);
}

}  // namespace leetcode::problem_474

#include "leetcode/problems/longest-arithmetic-subsequence.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1027 {

static int longestArithSeqLengthImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  // diff ∈ [-500, 500], offset 500 → index ∈ [0, 1000]
  std::vector<std::vector<int>> dp(n, std::vector<int>(1001, 0));
  int ans = 2;  // at least 2 elements exist

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int diff = nums[i] - nums[j] + 500;
      int prev = dp[j][diff];
      dp[i][diff] = std::max(dp[i][diff], prev == 0 ? 2 : prev + 1);
      ans = std::max(ans, dp[i][diff]);
    }
  }
  return ans;
}

LongestArithmeticSubsequenceSolution::LongestArithmeticSubsequenceSolution() {
  setMetaInfo({.id = 1027,
               .title = "Longest Arithmetic Subsequence",
               .url = "https://leetcode.com/problems/longest-arithmetic-subsequence/"});

  registerStrategy(
      {.name = "DP with 2D array",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n * D) where D = 1001",
       .tags = {"Array", "Hash Table", "Dynamic Programming"}},
      longestArithSeqLengthImpl);
}

int LongestArithmeticSubsequenceSolution::longestArithSeqLength(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1027
}  // namespace leetcode

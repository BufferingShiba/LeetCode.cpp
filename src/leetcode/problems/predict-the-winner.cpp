#include "leetcode/problems/predict-the-winner.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_486 {

static bool predictTheWinnerImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  // dp[j] stores dp[i][j] for the current row i
  std::vector<int> dp(n);

  for (int i = n - 1; i >= 0; --i) {
    dp[i] = nums[i];  // base case: single element subarray
    for (int j = i + 1; j < n; ++j) {
      int takeLeft = nums[i] - dp[j];       // dp[j] still holds dp[i+1][j]
      int takeRight = nums[j] - dp[j - 1];  // dp[j-1] already updated to dp[i][j-1]
      dp[j] = std::max(takeLeft, takeRight);
    }
  }

  return dp[n - 1] >= 0;
}

PredictTheWinnerSolution::PredictTheWinnerSolution() {
  setMetaInfo({.id = 486,
               .title = "Predict the Winner",
               .url = "https://leetcode.com/problems/predict-the-winner/"});

  registerStrategy(
      {.name = "Minimax DP (1D)",
       .expected = "Accepted",
       .time_complexity = "O(n²)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Math", "Dynamic Programming", "Recursion", "Game Theory"}},
      predictTheWinnerImpl);
}

bool PredictTheWinnerSolution::predictTheWinner(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_486

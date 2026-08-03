#include "leetcode/problems/climbing-stairs-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_3693 {

static int climbStairsImpl(int n, std::vector<int>& costs) {
  // dp[0] = 0
  long long dp_im3 = 0;  // dp[i-3]
  // dp[1] = costs[1] + 1
  long long dp_im2 = static_cast<long long>(costs[0]) + 1;  // dp[i-2]
  if (n == 1) {
    return static_cast<int>(dp_im2);
  }

  // dp[2] = costs[2] + min(dp[1]+1, dp[0]+4)
  long long dp_im1 =
      static_cast<long long>(costs[1]) + std::min(dp_im2 + 1, dp_im3 + 4);
  if (n == 2) {
    return static_cast<int>(dp_im1);
  }

  long long dp_i = 0;
  for (int i = 3; i <= n; ++i) {
    dp_i = static_cast<long long>(costs[i - 1]) +
           std::min({dp_im1 + 1, dp_im2 + 4, dp_im3 + 9});
    dp_im3 = dp_im2;
    dp_im2 = dp_im1;
    dp_im1 = dp_i;
  }

  return static_cast<int>(dp_i);
}

ClimbingStairsIiSolution::ClimbingStairsIiSolution() {
  setMetaInfo({.id = 3693,
               .title = "Climbing Stairs II",
               .url = "https://leetcode.com/problems/climbing-stairs-ii/"});
  registerStrategy(
      {.name = "DP Bottom-Up O(1) Space",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Dynamic Programming"}},
      climbStairsImpl);
}

int ClimbingStairsIiSolution::climbStairs(int n, std::vector<int>& costs) {
  return getSolution()(n, costs);
}

}  // namespace problem_3693
}  // namespace leetcode

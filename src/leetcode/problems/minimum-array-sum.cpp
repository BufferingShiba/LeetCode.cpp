#include "leetcode/problems/minimum-array-sum.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_3366 {

// DP: dp[a][b] = 使用 a 次 op1, b 次 op2 时的最小和
// 时间复杂度: O(n * op1 * op2), 空间复杂度: O(op1 * op2)
static int solution1(std::vector<int>& nums, int k, int op1, int op2) {
  const int INF = INT_MAX / 2;
  std::vector<std::vector<int>> dp(op1 + 1, std::vector<int>(op2 + 1, INF));
  dp[0][0] = 0;

  for (int x : nums) {
    std::vector<std::vector<int>> ndp(op1 + 1, std::vector<int>(op2 + 1, INF));
    for (int a = 0; a <= op1; ++a) {
      for (int b = 0; b <= op2; ++b) {
        if (dp[a][b] == INF) continue;
        int base = dp[a][b];

        // 不做任何操作
        ndp[a][b] = std::min(ndp[a][b], base + x);

        // 只做 op1
        if (a < op1) {
          ndp[a + 1][b] = std::min(ndp[a + 1][b], base + (x + 1) / 2);
        }

        // 只做 op2
        if (b < op2 && x >= k) {
          ndp[a][b + 1] = std::min(ndp[a][b + 1], base + x - k);
        }

        // op1 和 op2 都用
        if (a < op1 && b < op2) {
          // 先 op1 后 op2
          int v1 = (x + 1) / 2;
          if (v1 >= k) {
            ndp[a + 1][b + 1] = std::min(ndp[a + 1][b + 1], base + v1 - k);
          }
          // 先 op2 后 op1
          if (x >= k) {
            int v2 = (x - k + 1) / 2;
            ndp[a + 1][b + 1] = std::min(ndp[a + 1][b + 1], base + v2);
          }
        }
      }
    }
    dp = std::move(ndp);
  }

  int ans = INF;
  for (int a = 0; a <= op1; ++a) {
    for (int b = 0; b <= op2; ++b) {
      ans = std::min(ans, dp[a][b]);
    }
  }
  return ans;
}

MinimumArraySumSolution::MinimumArraySumSolution() {
  setMetaInfo({.id = 3366,
               .title = "Minimum Array Sum",
               .url = "https://leetcode.com/problems/minimum-array-sum/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n * op1 * op2)",
                    .space_complexity = "O(op1 * op2)",
                    .tags = {"Array", "Dynamic Programming"}},
                   solution1);
}

int MinimumArraySumSolution::minArraySum(std::vector<int>& nums, int k,
                                         int op1, int op2) {
  return getSolution()(nums, k, op1, op2);
}

}  // namespace problem_3366
}  // namespace leetcode

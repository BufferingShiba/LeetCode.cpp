#include "leetcode/problems/maximum-subarray-sum-with-one-deletion.h"

namespace leetcode {
namespace problem_1186 {
namespace {

int maximumSumImpl(std::vector<int>& arr) {
  const int n = static_cast<int>(arr.size());
  if (n == 1) {
    return arr[0];
  }
  // dp0: 以 i 结尾，未删除任何元素的最大子数组和。
  // dp1: 以 i 结尾，已删除恰好一个元素的最大子数组和。
  int dp0_prev2 = 0;  // dp0[i-2]
  int dp0_prev1 = arr[0];
  int dp1_prev1 = 0;
  int ans = arr[0];

  for (int i = 1; i < n; ++i) {
    const int v = arr[i];
    const int dp0_cur = std::max(v, dp0_prev1 + v);
    // 以 i 结尾，已删除一个元素：要么之前删过继续延伸，要么删除 i-1 接上 dp0[i-2]。
    int dp1_cur;
    if (i == 1) {
      dp1_cur = dp0_prev1;  // 删除 arr[0] 这个元素，剩 arr[1] 单独。
    } else {
      dp1_cur = std::max(dp1_prev1 + v, dp0_prev2 + v);
    }
    ans = std::max(ans, std::max(dp0_cur, dp1_cur));
    dp0_prev2 = dp0_prev1;
    dp0_prev1 = dp0_cur;
    dp1_prev1 = dp1_cur;
  }

  return ans;
}

}  // namespace

MaximumSubarraySumWithOneDeletionSolution::
    MaximumSubarraySumWithOneDeletionSolution() {
  setMetaInfo({.id = 1186,
               .title = "Maximum Subarray Sum with One Deletion",
               .url = "https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/"});
  registerStrategy(
      {"kadane-dp", "Accepted", "O(n)", "O(1)",
       {"Array", "Dynamic Programming"}},
      maximumSumImpl);
}

int MaximumSubarraySumWithOneDeletionSolution::maximumSum(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1186
}  // namespace leetcode

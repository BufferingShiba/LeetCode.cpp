#include "leetcode/problems/wiggle-subsequence.h"

#include <algorithm>

namespace leetcode {
namespace problem_376 {

namespace {

int wiggleMaxLengthImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  if (n == 0) {
    return 0;
  }

  int up = 1;    // 以"上升"结尾的最长摆动子序列长度
  int down = 1;  // 以"下降"结尾的最长摆动子序列长度

  for (int i = 1; i < n; ++i) {
    if (nums[i] > nums[i - 1]) {
      up = down + 1;
    } else if (nums[i] < nums[i - 1]) {
      down = up + 1;
    }
    // nums[i] == nums[i-1]：保持不变
  }

  return std::max(up, down);
}

}  // namespace

WiggleSubsequenceSolution::WiggleSubsequenceSolution() {
  setMetaInfo(
      {.id = 376,
       .title = "Wiggle Subsequence",
       .url = "https://leetcode.com/problems/wiggle-subsequence/"});

  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"dynamic-programming", "greedy"}},
      wiggleMaxLengthImpl);
}

int WiggleSubsequenceSolution::wiggleMaxLength(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_376
}  // namespace leetcode

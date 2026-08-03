#include "leetcode/problems/longest-alternating-subarray-after-removing-at-most-one-element.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3830 {

namespace {

int longestAlternatingImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  // dp0[i] = 以 i 结尾，相位 0（最后比较为上升 nums[i-1] < nums[i]），未删除元素的最长交替段长
  // dp1[i] = 以 i 结尾，相位 1（最后比较为下降 nums[i-1] > nums[i]），未删除元素的最长交替段长
  // del0[i] / del1[i] = 对应地，已删除一个元素
  std::vector<int> dp0(n, 1), dp1(n, 1), del0(n, 1), del1(n, 1);

  int ans = 1;
  for (int i = 1; i < n; ++i) {
    // 从 i-1 延伸（不删除新元素）
    if (nums[i - 1] < nums[i]) {  // 上升
      dp0[i] = std::max(dp0[i], dp1[i - 1] + 1);
      del0[i] = std::max(del0[i], del1[i - 1] + 1);
    } else if (nums[i - 1] > nums[i]) {  // 下降
      dp1[i] = std::max(dp1[i], dp0[i - 1] + 1);
      del1[i] = std::max(del1[i], del0[i - 1] + 1);
    }

    // 从 i-2 跨越（删除元素 nums[i-1]，仅当已删除 d=1 时可用，且之前未删除）
    if (i >= 2) {
      if (nums[i - 2] < nums[i]) {  // 删除 nums[i-1] 后，nums[i-2] < nums[i]，形成上升
        del0[i] = std::max(del0[i], dp1[i - 2] + 1);
      } else if (nums[i - 2] > nums[i]) {  // 下降
        del1[i] = std::max(del1[i], dp0[i - 2] + 1);
      }
    }

    ans = std::max({ans, dp0[i], dp1[i], del0[i], del1[i]});
  }
  return ans;
}

}  // namespace

LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution::
    LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution() {
  setMetaInfo({.id = 3830,
               .title = "Longest Alternating Subarray After Removing At Most One Element",
               .url = "https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/"});
  registerStrategy({.name = "DPOneDeletion",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming"}},
                   longestAlternatingImpl);
}

int LongestAlternatingSubarrayAfterRemovingAtMostOneElementSolution::
    longestAlternating(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3830
}  // namespace leetcode

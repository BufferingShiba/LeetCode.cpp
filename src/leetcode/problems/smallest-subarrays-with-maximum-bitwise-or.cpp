#include "leetcode/problems/smallest-subarrays-with-maximum-bitwise-or.h"

#include <array>
#include <algorithm>

namespace leetcode {
namespace problem_2411 {

namespace {

// 核心思路：
// 从 i 起的最大 OR 等于 suffixOr[i] = OR(nums[i..n-1])（因为 OR 随终点单调不减）。
// 从右往左扫描，维护每个 bit 在 [i+1..n-1] 中最近出现的位置 last[bit]。
// 则从 i 到覆盖 suffixOr[i] 的所有 set bit 的最近位置的最大值，即为最短子数组长度。
std::vector<int> smallestSubarraysByBitTracking(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> ans(n);

  // last[b] = 在已扫描后缀中 bit b 设置为 1 的最小下标（即离当前 i 最近出现的位置）
  // 用 -1 表示在已扫描部分未出现。由于是从右往左扫描，已扫描部分是 [i+1..n-1]。
  std::array<int, 31> last;
  last.fill(-1);

  int suffixOr = 0;  // suffixOr = OR(nums[i..n-1])，随 i 从右向左累积

  for (int i = n - 1; i >= 0; --i) {
    suffixOr |= nums[i];

    // 用 nums[i] 的位更新最近出现位置
    int x = nums[i];
    for (int b = 0; b < 31; ++b) {
      if ((x >> b) & 1) {
        // nums[i] 提供了 bit b，且 i 是当前最近的
        last[b] = i;
      }
    }

    // 计算最短长度：对 suffixOr 的每个 set bit，取其最近提供位置，取最大下标
    int farthest = i;
    int s = suffixOr;
    for (int b = 0; b < 31; ++b) {
      if ((s >> b) & 1) {
        // 该 bit 必然存在 (因 suffixOr 来源于后缀中的元素)，但为了安全检查
        if (last[b] != -1) {
          farthest = std::max(farthest, last[b]);
        }
      }
    }
    ans[i] = farthest - i + 1;
  }

  return ans;
}

}  // namespace

SmallestSubarraysWithMaximumBitwiseOrSolution::
    SmallestSubarraysWithMaximumBitwiseOrSolution() {
  setMetaInfo(
      {.id = 2411,
       .title = "Smallest Subarrays With Maximum Bitwise OR",
       .url = "https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/"});

  registerStrategy(
      {.name = "bit-tracking",
       .expected = "Accepted",
       .time_complexity = "O(31 * n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Bit Manipulation"}},
      smallestSubarraysByBitTracking);
}

std::vector<int> SmallestSubarraysWithMaximumBitwiseOrSolution::
    smallestSubarrays(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2411
}  // namespace leetcode

#include "leetcode/problems/subarray-with-elements-greater-than-varying-threshold.h"

#include <stack>

namespace leetcode {
namespace problem_2334 {
namespace {

// 单调栈：对每个位置 i，找出以 nums[i] 为最小值能覆盖的最长区间 [L, R]。
// L = 左边第一个 < nums[i] 的位置 + 1
// R = 右边第一个 < nums[i] 的位置 - 1
// 该区间的长度 len = R - L + 1。若 nums[i] * len > threshold，则该长度 len 是
// 一个有效答案（因为区间内所有元素 >= nums[i]，均 > threshold/len）。
// 若最长区间都不满足，则更短的（以 nums[i] 为最小值的）区间也必然不满足。
int validSubarraySizeImpl(std::vector<int>& nums, int threshold) {
  const int n = static_cast<int>(nums.size());

  // left[i] = 左边第一个严格小于 nums[i] 的下标
  std::vector<int> left(n, -1);
  std::stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && nums[st.top()] >= nums[i]) {
      st.pop();
    }
    left[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }

  while (!st.empty()) st.pop();

  // right[i] = 右边第一个严格小于 nums[i] 的下标
  std::vector<int> right(n, n);
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && nums[st.top()] >= nums[i]) {
      st.pop();
    }
    right[i] = st.empty() ? n : st.top();
    st.push(i);
  }

  for (int i = 0; i < n; ++i) {
    int length = right[i] - left[i] - 1;
    if (static_cast<long long>(nums[i]) * length > threshold) {
      return length;
    }
  }
  return -1;
}

}  // namespace

SubarrayWithElementsGreaterThanVaryingThresholdSolution::
    SubarrayWithElementsGreaterThanVaryingThresholdSolution() {
  setMetaInfo({
      .id = 2334,
      .title = "Subarray With Elements Greater Than Varying Threshold",
      .url = "https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/",
  });

  registerStrategy(
      {
          .name = "MonotonicStack",
          .expected = "Accepted",
          .time_complexity = "O(n)",
          .space_complexity = "O(n)",
          .tags = {"Array", "Stack", "Monotonic Stack"},
      },
      validSubarraySizeImpl);
}

int SubarrayWithElementsGreaterThanVaryingThresholdSolution::validSubarraySize(
    std::vector<int>& nums, int threshold) {
  return getSolution()(nums, threshold);
}

}  // namespace problem_2334
}  // namespace leetcode

#include "leetcode/problems/sliding-window-maximum.h"

#include <deque>

namespace leetcode {
namespace problem_239 {

namespace {

std::vector<int> maxSlidingWindowImpl(std::vector<int>& nums, int k) {
  std::deque<int> dq;
  std::vector<int> result;
  result.reserve(nums.size() - k + 1);

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    // 移除超出窗口左界的元素
    if (!dq.empty() && dq.front() == i - k) {
      dq.pop_front();
    }
    // 维持队列单调递减：移除队尾所有小于当前值的元素
    while (!dq.empty() && nums[dq.back()] < nums[i]) {
      dq.pop_back();
    }
    dq.push_back(i);

    // 窗口形成后记录最大值
    if (i >= k - 1) {
      result.push_back(nums[dq.front()]);
    }
  }

  return result;
}

}  // namespace

SlidingWindowMaximumSolution::SlidingWindowMaximumSolution() {
  setMetaInfo({.id = 239,
               .title = "Sliding Window Maximum",
               .url = "https://leetcode.com/problems/sliding-window-maximum/"});
  registerStrategy(
      {.name = "MonotonicDeque",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Queue", "Sliding Window", "Monotonic Queue"}},
      maxSlidingWindowImpl);
}

std::vector<int> SlidingWindowMaximumSolution::maxSlidingWindow(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_239
}  // namespace leetcode

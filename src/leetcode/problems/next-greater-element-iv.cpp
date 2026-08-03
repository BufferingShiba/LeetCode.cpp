#include "leetcode/problems/next-greater-element-iv.h"

#include <queue>
#include <stack>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2454 {

static std::vector<int> secondGreaterElementImpl(std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> ans(n, -1);

  std::stack<int> stk;  // monotonic decreasing stack of indices
  // min-heap of (value, index), sorted by value ascending
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  for (int i = 0; i < n; ++i) {
    // 1. resolve second-greater for indices waiting in the heap
    while (!pq.empty() && pq.top().first < nums[i]) {
      ans[pq.top().second] = nums[i];
      pq.pop();
    }

    // 2. resolve first-greater: pop from monotonic stack, push into heap
    while (!stk.empty() && nums[stk.top()] < nums[i]) {
      pq.emplace(nums[stk.top()], stk.top());
      stk.pop();
    }

    stk.push(i);
  }

  return ans;
}

NextGreaterElementIvSolution::NextGreaterElementIvSolution() {
  setMetaInfo({.id = 2454,
               .title = "Next Greater Element IV",
               .url = "https://leetcode.com/problems/next-greater-element-iv/"});
  registerStrategy(
      {.name = "Monotonic Stack + Min-Heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Stack", "Heap (Priority Queue)", "Monotonic Stack"}},
      secondGreaterElementImpl);
}

std::vector<int> NextGreaterElementIvSolution::secondGreaterElement(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2454
}  // namespace leetcode

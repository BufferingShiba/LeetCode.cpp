#include "leetcode/problems/smallest-range-covering-elements-from-k-lists.h"

#include <queue>
#include <tuple>
#include <vector>

namespace leetcode {
namespace problem_632 {

namespace {

std::vector<int> smallestRangeImpl(std::vector<std::vector<int>>& nums) {
  int k = static_cast<int>(nums.size());

  // min-heap: stores (value, list_index, element_index)
  using Element = std::tuple<int, int, int>;
  std::priority_queue<Element, std::vector<Element>, std::greater<Element>> min_heap;

  int cur_max = INT_MIN;
  for (int i = 0; i < k; ++i) {
    int val = nums[i][0];
    min_heap.emplace(val, i, 0);
    cur_max = std::max(cur_max, val);
  }

  int best_left = 0;
  int best_right = INT_MAX;

  while (true) {
    auto [min_val, list_idx, elem_idx] = min_heap.top();
    min_heap.pop();

    // Check if current range is better
    long long cur_range = static_cast<long long>(cur_max) - min_val;
    long long best_range = static_cast<long long>(best_right) - best_left;
    if (cur_range < best_range || (cur_range == best_range && min_val < best_left)) {
      best_left = min_val;
      best_right = cur_max;
    }

    // Advance in the list that provided the minimum
    if (elem_idx + 1 < static_cast<int>(nums[list_idx].size())) {
      int next_val = nums[list_idx][elem_idx + 1];
      min_heap.emplace(next_val, list_idx, elem_idx + 1);
      cur_max = std::max(cur_max, next_val);
    } else {
      // This list is exhausted; cannot cover all k lists anymore
      break;
    }
  }

  return {best_left, best_right};
}

}  // namespace

SmallestRangeCoveringElementsFromKListsSolution::SmallestRangeCoveringElementsFromKListsSolution() {
  setMetaInfo({.id = 632,
               .title = "Smallest Range Covering Elements from K Lists",
               .url = "https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/"});
  registerStrategy(
      {.name = "MinHeap",
       .expected = "Accepted",
       .time_complexity = "O(N log k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Hash Table", "Greedy", "Sliding Window", "Heap (Priority Queue)"}},
      smallestRangeImpl);
}

std::vector<int> SmallestRangeCoveringElementsFromKListsSolution::smallestRange(
    std::vector<std::vector<int>>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_632
}  // namespace leetcode

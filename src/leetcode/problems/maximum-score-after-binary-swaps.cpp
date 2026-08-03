#include "leetcode/problems/maximum-score-after-binary-swaps.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_3781 {

namespace {

long long maximumScoreImpl(std::vector<int>& nums, std::string s) {
  int n = static_cast<int>(nums.size());
  // suffixOnes[i] = number of '1's in s[i..n-1]
  std::vector<int> suffixOnes(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    suffixOnes[i] = suffixOnes[i + 1] + (s[i] == '1' ? 1 : 0);
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  for (int i = n - 1; i >= 0; --i) {
    minHeap.push(nums[i]);
    while (static_cast<int>(minHeap.size()) > suffixOnes[i]) {
      minHeap.pop();
    }
  }

  long long total = 0;
  while (!minHeap.empty()) {
    total += minHeap.top();
    minHeap.pop();
  }
  return total;
}

}  // namespace

MaximumScoreAfterBinarySwapsSolution::MaximumScoreAfterBinarySwapsSolution() {
  setMetaInfo({.id = 3781,
               .title = "Maximum Score After Binary Swaps",
               .url = "https://leetcode.com/problems/maximum-score-after-binary-swaps/"});
  registerStrategy(
      {.name = "Greedy with Min-Heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "String", "Greedy", "Heap (Priority Queue)"}},
      maximumScoreImpl);
}

long long MaximumScoreAfterBinarySwapsSolution::maximumScore(
    std::vector<int>& nums, std::string s) {
  return getSolution()(nums, s);
}

}  // namespace problem_3781
}  // namespace leetcode

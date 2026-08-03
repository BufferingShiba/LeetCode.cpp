#include "leetcode/problems/minimum-operations-to-exceed-threshold-value-ii.h"

#include <functional>
#include <queue>

namespace leetcode {
namespace problem_3066 {

namespace {

int minOperationsImpl(std::vector<int>& nums, int k) {
  std::priority_queue<long long, std::vector<long long>, std::greater<long long>>
      pq(nums.begin(), nums.end());
  int ops = 0;
  while (!pq.empty()) {
    long long smallest = pq.top();
    if (smallest >= k) {
      break;
    }
    pq.pop();
    if (pq.empty()) {
      break;
    }
    long long second = pq.top();
    pq.pop();
    long long merged = smallest * 2 + second;
    pq.push(merged);
    ++ops;
  }
  return ops;
}

}  // namespace

MinimumOperationsToExceedThresholdValueIiSolution::
    MinimumOperationsToExceedThresholdValueIiSolution() {
  setMetaInfo({.id = 3066,
               .title = "Minimum Operations to Exceed Threshold Value II",
               .url = "https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/"});
  registerStrategy(
      {.name = "min_heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Heap", "Priority Queue", "Simulation"}},
      minOperationsImpl);
}

int MinimumOperationsToExceedThresholdValueIiSolution::minOperations(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3066
}  // namespace leetcode

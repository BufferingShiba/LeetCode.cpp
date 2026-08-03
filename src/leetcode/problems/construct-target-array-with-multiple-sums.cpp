#include "leetcode/problems/construct-target-array-with-multiple-sums.h"

#include <queue>
#include <vector>

namespace leetcode::problem_1354 {

namespace {

bool isPossibleImpl(std::vector<int>& target) {
  const int n = static_cast<int>(target.size());
  if (n == 1) {
    return target[0] == 1;
  }

  long long total = 0;
  std::priority_queue<int> pq;
  for (int v : target) {
    total += v;
    pq.push(v);
  }

  while (!pq.empty()) {
    int largest = pq.top();
    pq.pop();
    if (largest == 1) {
      return true;  // all remaining elements are 1
    }
    long long rest = total - largest;
    if (rest == 1) {
      // All other elements are 1; the largest can be brought back to 1.
      return true;
    }
    long long prev = largest % rest;
    if (prev == 0) {
      prev = rest;
    }
    // prev must be strictly smaller than largest and >= 1.
    if (prev <= 0 || prev >= largest) {
      return false;
    }
    total = total - largest + prev;
    pq.push(static_cast<int>(prev));
  }
  return true;
}

}  // namespace

ConstructTargetArrayWithMultipleSumsSolution::
    ConstructTargetArrayWithMultipleSumsSolution() {
  setMetaInfo({.id = 1354,
               .title =
                   "Construct Target Array With Multiple Sums",
               .url =
                   "https://leetcode.com/problems/construct-target-array-with-multiple-sums/"});
  registerStrategy(
      {.name = "reverse-with-max-heap",
       .expected = "Accepted",
       .time_complexity = "O(n log n + K log n)",
       .space_complexity = "O(n)",
       .tags = {"Heap (Priority Queue)", "Greedy"}},
      isPossibleImpl);
}

bool ConstructTargetArrayWithMultipleSumsSolution::isPossible(
    std::vector<int>& target) {
  return getSolution()(target);
}

}  // namespace leetcode::problem_1354

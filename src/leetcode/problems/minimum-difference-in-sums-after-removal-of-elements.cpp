#include "leetcode/problems/minimum-difference-in-sums-after-removal-of-elements.h"

#include <algorithm>
#include <cstdint>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_2163 {

namespace {

// Strategy: two heaps.
// - leftMin[i] = minimum sum of n elements chosen from nums[0..i].
// - rightMax[i] = maximum sum of n elements chosen from nums[i..3n-1].
// Answer = min over i in [n-1, 2n-1] of leftMin[i] - rightMax[i+1].
long long minimumDifferenceImpl(std::vector<int>& nums) {
  const int m = static_cast<int>(nums.size());
  const int n = m / 3;

  std::vector<long long> leftMin(m, 0);
  {  // left prefix: keep n smallest via max-heap.
    std::priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
      if (static_cast<int>(pq.size()) < n) {
        pq.push(nums[i]);
        sum += nums[i];
      } else if (nums[i] < pq.top()) {
        sum -= pq.top();
        pq.pop();
        pq.push(nums[i]);
        sum += nums[i];
      }
      if (i >= n - 1) {
        leftMin[i] = sum;
      }
    }
  }

  std::vector<long long> rightMax(m + 1, 0);
  {  // right suffix: keep n largest via min-heap.
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    long long sum = 0;
    for (int i = m - 1; i >= 0; --i) {
      if (static_cast<int>(pq.size()) < n) {
        pq.push(nums[i]);
        sum += nums[i];
      } else if (nums[i] > pq.top()) {
        sum -= pq.top();
        pq.pop();
        pq.push(nums[i]);
        sum += nums[i];
      }
      if (i <= m - n) {
        rightMax[i] = sum;
      }
    }
  }

  long long best = static_cast<long long>(1) << 62;
  for (int i = n - 1; i <= 2 * n - 1; ++i) {
    best = std::min(best, leftMin[i] - rightMax[i + 1]);
  }
  return best;
}

}  // namespace

MinimumDifferenceInSumsAfterRemovalOfElementsSolution::
    MinimumDifferenceInSumsAfterRemovalOfElementsSolution() {
  setMetaInfo({.id = 2163,
               .title = "Minimum Difference in Sums After Removal of Elements",
               .url = "https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/"});
  registerStrategy(
      {.name = "TwoHeaps",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Dynamic Programming", "Heap (Priority Queue)"},
       .notes = "Prefix n-smallest sum + suffix n-largest sum via heaps."},
      minimumDifferenceImpl);
}

long long MinimumDifferenceInSumsAfterRemovalOfElementsSolution::minimumDifference(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2163
}  // namespace leetcode

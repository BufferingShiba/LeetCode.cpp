#include "leetcode/problems/minimum-operations-to-make-median-of-array-equal-to-k.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3107 {

static long long minOperationsToMakeMedianKImpl(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int n = static_cast<int>(nums.size());
  int m = n / 2;

  if (nums[m] == k) {
    return 0;
  }

  long long ops = 0;
  if (nums[m] < k) {
    // Need to raise elements from m to n-1 that are below k
    for (int i = m; i < n; ++i) {
      if (nums[i] < k) {
        ops += static_cast<long long>(k) - nums[i];
      }
    }
  } else {
    // nums[m] > k: need to lower elements from 0 to m that are above k
    for (int i = 0; i <= m; ++i) {
      if (nums[i] > k) {
        ops += static_cast<long long>(nums[i]) - k;
      }
    }
  }
  return ops;
}

MinimumOperationsToMakeMedianOfArrayEqualToKSolution::
    MinimumOperationsToMakeMedianOfArrayEqualToKSolution() {
  setMetaInfo({.id = 3107,
               .title = "Minimum Operations to Make Median of Array Equal to K",
               .url = "https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/"});
  registerStrategy(
      {.name = "Greedy after sorting",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      minOperationsToMakeMedianKImpl);
  setDefaultStrategy();
}

long long MinimumOperationsToMakeMedianOfArrayEqualToKSolution::minOperationsToMakeMedianK(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3107
}  // namespace leetcode

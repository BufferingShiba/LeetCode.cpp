#include "leetcode/problems/minimum-subsequence-in-non-increasing-order.h"

#include <algorithm>
#include <numeric>

namespace leetcode {
namespace problem_1403 {

static std::vector<int> minSubsequenceImpl(std::vector<int>& nums) {
  // Sort in non-increasing order
  std::sort(nums.begin(), nums.end(), std::greater<int>());

  int total = std::accumulate(nums.begin(), nums.end(), 0);
  int cur = 0;
  std::vector<int> result;

  for (int x : nums) {
    cur += x;
    result.push_back(x);
    if (cur > total - cur) {
      break;
    }
  }

  return result;
}

MinimumSubsequenceInNonIncreasingOrderSolution::MinimumSubsequenceInNonIncreasingOrderSolution() {
  setMetaInfo({.id = 1403,
               .title = "Minimum Subsequence in Non-Increasing Order",
               .url = "https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/"});
  registerStrategy({.name = "greedy_sort",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Greedy", "Sorting"}},
                   minSubsequenceImpl);
  setDefaultStrategy();
}

std::vector<int> MinimumSubsequenceInNonIncreasingOrderSolution::minSubsequence(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1403
}  // namespace leetcode

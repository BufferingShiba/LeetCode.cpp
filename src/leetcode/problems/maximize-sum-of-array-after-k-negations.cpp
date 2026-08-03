#include "leetcode/problems/maximize-sum-of-array-after-k-negations.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1005 {

static int largestSumAfterKNegationsImpl(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  int n = static_cast<int>(nums.size());
  for (int i = 0; i < n && k > 0; ++i) {
    if (nums[i] < 0) {
      nums[i] = -nums[i];
      --k;
    }
  }
  if (k % 2 == 1) {
    auto min_it = std::min_element(nums.begin(), nums.end());
    *min_it = -*min_it;
  }
  int sum = 0;
  for (int x : nums) sum += x;
  return sum;
}

MaximizeSumOfArrayAfterKNegationsSolution::MaximizeSumOfArrayAfterKNegationsSolution() {
  setMetaInfo({.id = 1005,
               .title = "Maximize Sum Of Array After K Negations",
               .url = "https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/"});
  registerStrategy({.name = "GreedySort",
                     .expected = "Accepted",
                     .time_complexity = "O(n log n)",
                     .space_complexity = "O(1)",
                     .tags = {"Array", "Greedy", "Sorting"}},
                   largestSumAfterKNegationsImpl);
}

int MaximizeSumOfArrayAfterKNegationsSolution::largestSumAfterKNegations(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1005
}  // namespace leetcode

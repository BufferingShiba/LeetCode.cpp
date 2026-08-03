#include "leetcode/problems/minimum-sum-of-mountain-triplets-i.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_2908 {
namespace {

int minimumSumImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int best = INT_MAX;
  for (int j = 1; j < n - 1; ++j) {
    for (int i = 0; i < j; ++i) {
      if (nums[i] >= nums[j]) continue;
      for (int k = j + 1; k < n; ++k) {
        if (nums[k] < nums[j]) {
          best = std::min(best, nums[i] + nums[j] + nums[k]);
        }
      }
    }
  }
  return best == INT_MAX ? -1 : best;
}

}  // namespace

MinimumSumOfMountainTripletsISolution::MinimumSumOfMountainTripletsISolution() {
  setMetaInfo({.id = 2908,
               .title = "Minimum Sum of Mountain Triplets I",
               .url = "https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/"});
  registerStrategy({.name = "brute_force",
                    .expected = "Accepted",
                    .time_complexity = "O(n^3)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   minimumSumImpl);
}

int MinimumSumOfMountainTripletsISolution::minimumSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2908
}  // namespace leetcode

#include "leetcode/problems/3sum-closest.h"

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace leetcode {
namespace problem_16 {
namespace {

int threeSumClosestImpl(std::vector<int>& nums, int target) {
  std::sort(nums.begin(), nums.end());
  int n = nums.size();
  int best = nums[0] + nums[1] + nums[2];

  for (int i = 0; i < n - 2; ++i) {
    int lo = i + 1;
    int hi = n - 1;
    while (lo < hi) {
      int sum = nums[i] + nums[lo] + nums[hi];
      if (std::abs(sum - target) < std::abs(best - target)) {
        best = sum;
      }
      if (sum < target) {
        ++lo;
      } else {
        --hi;
      }
    }
  }
  return best;
}

}  // namespace

ThreeSumClosestSolution::ThreeSumClosestSolution() {
  setMetaInfo({.id = 16,
               .title = "3Sum Closest",
               .url = "https://leetcode.com/problems/3sum-closest/"});
  registerStrategy({.name = "sort+two-pointer",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(log n) (sorting)",
                    .tags = {"Array", "Two Pointers", "Sorting"}},
                   threeSumClosestImpl);
}

int ThreeSumClosestSolution::threeSumClosest(std::vector<int>& nums, int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_16
}  // namespace leetcode

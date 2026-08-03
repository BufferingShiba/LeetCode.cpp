#include "leetcode/problems/4sum.h"

#include <algorithm>

namespace leetcode {
namespace problem_18 {
namespace {

std::vector<std::vector<int>> fourSumImpl(std::vector<int>& nums, int target) {
  std::vector<std::vector<int>> result;
  const int n = static_cast<int>(nums.size());
  if (n < 4) {
    return result;
  }

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 3; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < n - 2; ++j) {
      if (j > i + 1 && nums[j] == nums[j - 1]) {
        continue;
      }
      int left = j + 1;
      int right = n - 1;
      long long remaining = static_cast<long long>(target) - nums[i] - nums[j];
      while (left < right) {
        long long sum = static_cast<long long>(nums[left]) + nums[right];
        if (sum == remaining) {
          result.push_back({nums[i], nums[j], nums[left], nums[right]});
          ++left;
          --right;
          while (left < right && nums[left] == nums[left - 1]) ++left;
          while (left < right && nums[right] == nums[right + 1]) --right;
        } else if (sum < remaining) {
          ++left;
        } else {
          --right;
        }
      }
    }
  }
  return result;
}

}  // namespace

FourSumSolution::FourSumSolution() {
  setMetaInfo({.id = 18,
               .title = "4Sum",
               .url = "https://leetcode.com/problems/4sum/"});
  registerStrategy({.name = "SortingTwoPointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n^3)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Two Pointers", "Sorting"}},
                   fourSumImpl);
}

std::vector<std::vector<int>> FourSumSolution::fourSum(std::vector<int>& nums,
                                                       int target) {
  return getSolution()(nums, target);
}

}  // namespace problem_18
}  // namespace leetcode

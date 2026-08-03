#include "leetcode/problems/3sum.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_15 {

static std::vector<std::vector<int>> threeSumImpl(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  int n = static_cast<int>(nums.size());
  if (n < 3) return result;

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 2; ++i) {
    if (nums[i] > 0) break;  // no positive can sum to 0
    if (i > 0 && nums[i] == nums[i - 1]) continue;  // skip duplicate i

    int left = i + 1;
    int right = n - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum < 0) {
        ++left;
      } else if (sum > 0) {
        --right;
      } else {
        result.push_back({nums[i], nums[left], nums[right]});
        // skip duplicate left
        while (left < right && nums[left] == nums[left + 1]) ++left;
        // skip duplicate right
        while (left < right && nums[right] == nums[right - 1]) --right;
        ++left;
        --right;
      }
    }
  }

  return result;
}

ThreeSumSolution::ThreeSumSolution() {
  setMetaInfo({.id = 15, .title = "3Sum", .url = "https://leetcode.com/problems/3sum/"});
  registerStrategy(
      {.name = "Sorting + Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting"}},
      threeSumImpl);
  setDefaultStrategy();
}

std::vector<std::vector<int>> ThreeSumSolution::threeSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_15
}  // namespace leetcode

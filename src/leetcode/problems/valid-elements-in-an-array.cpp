#include "leetcode/problems/valid-elements-in-an-array.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3912 {

namespace {

std::vector<int> findValidElementsImpl(std::vector<int> nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> result;
  if (n == 0) {
    return result;
  }

  // 计算左侧最大值前缀（leftMax[i] 是 nums[0..i-1] 的最大值）
  std::vector<int> leftMax(n);
  leftMax[0] = nums[0];
  for (int i = 1; i < n; ++i) {
    leftMax[i] = std::max(leftMax[i - 1], nums[i - 1]);
  }

  // 从右往左扫，同时维护右侧最大值，标记合法位置
  std::vector<bool> valid(n, false);
  int rightMax = nums[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    bool greaterThanLeft = (i == 0) || nums[i] > leftMax[i];
    bool greaterThanRight = (i == n - 1) || nums[i] > rightMax;
    valid[i] = greaterThanLeft || greaterThanRight;
    if (i > 0) {
      rightMax = std::max(rightMax, nums[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (valid[i]) {
      result.push_back(nums[i]);
    }
  }
  return result;
}

}  // namespace

ValidElementsInAnArraySolution::ValidElementsInAnArraySolution() {
  setMetaInfo({.id = 3912,
               .title = "Valid Elements in an Array",
               .url = "https://leetcode.com/problems/valid-elements-in-an-array/"});
  registerStrategy({.name = "Two-pass Prefix/Suffix Max",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Prefix Sum"}},
                   findValidElementsImpl);
}

std::vector<int> ValidElementsInAnArraySolution::findValidElements(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3912
}  // namespace leetcode

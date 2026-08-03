#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/subarray-with-elements-greater-than-varying-threshold.h"

namespace leetcode {
namespace problem_2334 {
namespace {

// 判断某个返回的 size 是否满足题目要求。
// 若 k == -1，必须确认不存在任何长度 k' 满足条件。
// 若 k > 0，必须确认存在一个长度为 k 的子数组满足条件。
bool IsValidResult(const std::vector<int>& nums, int threshold, int result) {
  const int n = static_cast<int>(nums.size());
  if (result == -1) {
    for (int k = 1; k <= n; ++k) {
      bool ok = false;
      for (int l = 0; l + k <= n; ++l) {
        long long mn = nums[l];
        for (int j = 1; j < k; ++j) {
          mn = std::min(mn, (long long)nums[l + j]);
        }
        if (mn * k > threshold) {
          ok = true;
          break;
        }
      }
      if (ok) return false;  // 存在解却返回 -1
    }
    return true;
  }
  if (result < 1 || result > n) return false;
  for (int l = 0; l + result <= n; ++l) {
    long long mn = nums[l];
    for (int j = 1; j < result; ++j) {
      mn = std::min(mn, (long long)nums[l + j]);
    }
    if (mn * result > threshold) {
      return true;
    }
  }
  return false;
}

}  // namespace

class SubarrayWithElementsGreaterThanVaryingThresholdTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SubarrayWithElementsGreaterThanVaryingThresholdSolution solution;
};

TEST_P(SubarrayWithElementsGreaterThanVaryingThresholdTest, Example1) {
  std::vector<int> nums{1, 3, 4, 3, 1};
  int threshold = 6;
  int result = solution.validSubarraySize(nums, threshold);
  EXPECT_TRUE(IsValidResult(nums, threshold, result));
}

TEST_P(SubarrayWithElementsGreaterThanVaryingThresholdTest, Example2) {
  std::vector<int> nums{6, 5, 6, 5, 8};
  int threshold = 7;
  int result = solution.validSubarraySize(nums, threshold);
  EXPECT_TRUE(IsValidResult(nums, threshold, result));
}

TEST_P(SubarrayWithElementsGreaterThanVaryingThresholdTest, NoValidSubarray) {
  std::vector<int> nums{1, 1, 1};
  int threshold = 10;
  EXPECT_EQ(solution.validSubarraySize(nums, threshold), -1);
}

TEST_P(SubarrayWithElementsGreaterThanVaryingThresholdTest, SingleElement) {
  std::vector<int> nums{1};
  int threshold = 1;
  EXPECT_EQ(solution.validSubarraySize(nums, threshold), -1);
}

TEST_P(SubarrayWithElementsGreaterThanVaryingThresholdTest, SingleElementSatisfied) {
  std::vector<int> nums{8};
  int threshold = 7;
  EXPECT_EQ(solution.validSubarraySize(nums, threshold), 1);
}

INSTANTIATE_TEST_SUITE_P(
    SubarrayWithElementsGreaterThanVaryingThresholdTest,
    SubarrayWithElementsGreaterThanVaryingThresholdTest,
    ::testing::ValuesIn(
        SubarrayWithElementsGreaterThanVaryingThresholdSolution().getStrategyNames()));

}  // namespace problem_2334
}  // namespace leetcode

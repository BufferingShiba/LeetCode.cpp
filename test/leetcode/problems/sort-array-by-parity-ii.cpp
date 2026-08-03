#include <gtest/gtest.h>

#include "leetcode/problems/sort-array-by-parity-ii.h"

namespace leetcode::problem_922 {

namespace {

bool isValid(const std::vector<int>& nums) {
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if ((nums[i] & 1) != (i & 1)) return false;
  }
  return true;
}

}  // namespace

class SortArrayByParityIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortArrayByParityIiSolution solution;
};

TEST_P(SortArrayByParityIiTest, Example1) {
  std::vector<int> nums = {4, 2, 5, 7};
  auto result = solution.sortArrayByParityII(nums);
  EXPECT_TRUE(isValid(result));
  // 还要检查元素组成不变（half even, half odd）
  std::sort(nums.begin(), nums.end());
  std::vector<int> sorted_result = result;
  std::sort(sorted_result.begin(), sorted_result.end());
  EXPECT_EQ(nums, sorted_result);
}

TEST_P(SortArrayByParityIiTest, Example2) {
  std::vector<int> nums = {2, 3};
  auto result = solution.sortArrayByParityII(nums);
  EXPECT_TRUE(isValid(result));
}

TEST_P(SortArrayByParityIiTest, SelfAuthoredAlreadyCorrect) {
  std::vector<int> nums = {0, 1, 2, 3};
  auto result = solution.sortArrayByParityII(nums);
  EXPECT_TRUE(isValid(result));
}

TEST_P(SortArrayByParityIiTest, SelfAuthoredAllSwapped) {
  // 偶数位置都是奇数，奇数位置都是偶数 — 需要全部交换
  std::vector<int> nums = {1, 0, 3, 2};
  auto result = solution.sortArrayByParityII(nums);
  EXPECT_TRUE(isValid(result));
}

INSTANTIATE_TEST_SUITE_P(
    , SortArrayByParityIiTest,
    testing::ValuesIn(SortArrayByParityIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_922

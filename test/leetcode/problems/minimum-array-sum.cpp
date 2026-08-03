#include "leetcode/problems/minimum-array-sum.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3366 {

class MinimumArraySumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumArraySumSolution solution;
};

TEST_P(MinimumArraySumTest, Example1) {
  std::vector<int> nums = {2, 8, 3, 19, 3};
  int k = 3, op1 = 1, op2 = 1;
  int expected = 23;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, Example2) {
  std::vector<int> nums = {2, 4, 3};
  int k = 3, op1 = 2, op2 = 1;
  int expected = 3;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, SelfAuthoredNoOpsAvailable) {
  std::vector<int> nums = {5, 10, 15};
  int k = 3, op1 = 0, op2 = 0;
  int expected = 30;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, SelfAuthoredOnlyOp1) {
  std::vector<int> nums = {7, 8, 9};
  int k = 5, op1 = 2, op2 = 0;
  // ceil(7/2)=4, ceil(8/2)=4, ceil(9/2)=5 → 最优对8和9操作: 7+4+5=16
  int expected = 16;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, SelfAuthoredOnlyOp2) {
  std::vector<int> nums = {10, 8, 6};
  int k = 5, op1 = 0, op2 = 2;
  // 10-5=5, 8-5=3 → 5+3+6=14
  int expected = 14;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, SelfAuthoredBothOpsOnSameIndex) {
  std::vector<int> nums = {3};
  int k = 2, op1 = 1, op2 = 1;
  // 先1后2: ceil(3/2)=2, 2>=2 → 2-2=0
  // 先2后1: 3-2=1, ceil(1/2)=1
  // 最优为0
  int expected = 0;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

TEST_P(MinimumArraySumTest, SelfAuthoredKEqualsZero) {
  std::vector<int> nums = {1, 2, 3};
  int k = 0, op1 = 1, op2 = 2;
  // k=0 时 op2 无实际效果，op1 选最大的：ceil(3/2)=2, 结果 1+2+2=5
  int expected = 5;
  EXPECT_EQ(solution.minArraySum(nums, k, op1, op2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MinimumArraySumTest,
    ::testing::ValuesIn(MinimumArraySumSolution().getStrategyNames()));

}  // namespace problem_3366
}  // namespace leetcode

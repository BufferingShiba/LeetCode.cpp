#include "leetcode/problems/find-the-k-sum-of-an-array.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2386 {
namespace {

class FindTheKSumOfAnArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheKSumOfAnArraySolution solution;
};

TEST_P(FindTheKSumOfAnArrayTest, Example1) {
  std::vector<int> nums = {2, 4, -2};
  EXPECT_EQ(2, solution.kSum(nums, 5));
}

TEST_P(FindTheKSumOfAnArrayTest, Example2) {
  std::vector<int> nums = {1, -2, 3, 4, -10, 12};
  EXPECT_EQ(10, solution.kSum(nums, 16));
}

TEST_P(FindTheKSumOfAnArrayTest, SelfAuthoredKEqualsOne) {
  std::vector<int> nums = {2, 4, -2};
  EXPECT_EQ(6, solution.kSum(nums, 1));
}

TEST_P(FindTheKSumOfAnArrayTest, SelfAuthoredAllNegative) {
  std::vector<int> nums = {-1, -3, -2};
  // absolute = {1,2,3}, base = 0.
  // subset sums ascending: 0(empty),1,2,3,3,4,5,6.
  EXPECT_EQ(0, solution.kSum(nums, 1));
  EXPECT_EQ(-1, solution.kSum(nums, 2));
  EXPECT_EQ(-2, solution.kSum(nums, 3));
}

TEST_P(FindTheKSumOfAnArrayTest, SelfAuthoredSingleElementPositive) {
  std::vector<int> nums = {7};
  EXPECT_EQ(7, solution.kSum(nums, 1));
  EXPECT_EQ(0, solution.kSum(nums, 2));
}

INSTANTIATE_TEST_SUITE_P(
    FindTheKSumOfAnArrayTestSuite, FindTheKSumOfAnArrayTest,
    ::testing::ValuesIn(FindTheKSumOfAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2386
}  // namespace leetcode

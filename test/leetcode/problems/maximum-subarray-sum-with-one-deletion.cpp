#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-subarray-sum-with-one-deletion.h"

namespace leetcode {
namespace problem_1186 {
namespace {

class MaximumSubarraySumWithOneDeletionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumSubarraySumWithOneDeletionSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumSubarraySumWithOneDeletionTest, Example1) {
  std::vector<int> arr = {1, -2, 0, 3};
  EXPECT_EQ(4, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, Example2) {
  std::vector<int> arr = {1, -2, -2, 3};
  EXPECT_EQ(3, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, Example3) {
  std::vector<int> arr = {-1, -1, -1, -1};
  EXPECT_EQ(-1, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {5};
  EXPECT_EQ(5, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, SelfAuthoredTwoElementsBothNegative) {
  std::vector<int> arr = {-3, -2};
  EXPECT_EQ(-2, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, SelfAuthoredAllPositive) {
  std::vector<int> arr = {1, 2, 3, 4};
  EXPECT_EQ(10, solution.maximumSum(arr));
}

TEST_P(MaximumSubarraySumWithOneDeletionTest, SelfAuthoredDeleteMiddleMax) {
  std::vector<int> arr = {8, -1, -5, 9};
  // 删除 -5，子数组 [8,-1,9] = 16。
  EXPECT_EQ(16, solution.maximumSum(arr));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSubarraySumWithOneDeletionTestSuite,
    MaximumSubarraySumWithOneDeletionTest,
    ::testing::ValuesIn(
        MaximumSubarraySumWithOneDeletionSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1186
}  // namespace leetcode

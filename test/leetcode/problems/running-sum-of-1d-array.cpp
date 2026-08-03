#include "leetcode/problems/running-sum-of-1d-array.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_1480 {

class RunningSumOf1dArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RunningSumOf1dArraySolution solution;
};

TEST_P(RunningSumOf1dArrayTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(std::vector<int>({1, 3, 6, 10}), solution.runningSum(nums));
}

TEST_P(RunningSumOf1dArrayTest, Example2) {
  std::vector<int> nums{1, 1, 1, 1, 1};
  EXPECT_EQ(std::vector<int>({1, 2, 3, 4, 5}), solution.runningSum(nums));
}

TEST_P(RunningSumOf1dArrayTest, Example3) {
  std::vector<int> nums{3, 1, 2, 10, 1};
  EXPECT_EQ(std::vector<int>({3, 4, 6, 16, 17}), solution.runningSum(nums));
}

TEST_P(RunningSumOf1dArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{42};
  EXPECT_EQ(std::vector<int>({42}), solution.runningSum(nums));
}

INSTANTIATE_TEST_SUITE_P(
    RunningSumOf1dArrayTestSuite, RunningSumOf1dArrayTest,
    ::testing::ValuesIn(RunningSumOf1dArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_1480

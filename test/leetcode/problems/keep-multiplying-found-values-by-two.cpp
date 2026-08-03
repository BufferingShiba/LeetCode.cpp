#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/keep-multiplying-found-values-by-two.h"

using leetcode::problem_2154::KeepMultiplyingFoundValuesByTwoSolution;

class KeepMultiplyingFoundValuesByTwoTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KeepMultiplyingFoundValuesByTwoSolution solution_;
};

TEST_P(KeepMultiplyingFoundValuesByTwoTest, Example1) {
  std::vector<int> nums{5, 3, 6, 1, 12};
  EXPECT_EQ(24, solution_.findFinalValue(nums, 3));
}

TEST_P(KeepMultiplyingFoundValuesByTwoTest, Example2) {
  std::vector<int> nums{2, 7, 9};
  EXPECT_EQ(4, solution_.findFinalValue(nums, 4));
}

TEST_P(KeepMultiplyingFoundValuesByTwoTest, SingleElementMatch) {
  std::vector<int> nums{2};
  EXPECT_EQ(4, solution_.findFinalValue(nums, 2));
}

TEST_P(KeepMultiplyingFoundValuesByTwoTest, NoMatch) {
  std::vector<int> nums{1, 2, 3};
  EXPECT_EQ(5, solution_.findFinalValue(nums, 5));
}

INSTANTIATE_TEST_SUITE_P(
    KeepMultiplyingFoundValuesByTwoTestSuite,
    KeepMultiplyingFoundValuesByTwoTest,
    ::testing::ValuesIn(
        KeepMultiplyingFoundValuesByTwoSolution().getStrategyNames()));

#include <gtest/gtest.h>

#include "leetcode/problems/largest-positive-integer-that-exists-with-its-negative.h"

using namespace leetcode::problem_2441;

class LargestPositiveIntegerThatExistsWithItsNegativeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LargestPositiveIntegerThatExistsWithItsNegativeSolution solution;
};

TEST_P(LargestPositiveIntegerThatExistsWithItsNegativeTest, Example1) {
  std::vector<int> nums = {-1, 2, -3, 3};
  EXPECT_EQ(solution.findMaxK(nums), 3);
}

TEST_P(LargestPositiveIntegerThatExistsWithItsNegativeTest, Example2) {
  std::vector<int> nums = {-1, 10, 6, 7, -7, 1};
  EXPECT_EQ(solution.findMaxK(nums), 7);
}

TEST_P(LargestPositiveIntegerThatExistsWithItsNegativeTest, Example3) {
  std::vector<int> nums = {-10, 8, 6, 7, -2, -3};
  EXPECT_EQ(solution.findMaxK(nums), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, LargestPositiveIntegerThatExistsWithItsNegativeTest,
    ::testing::ValuesIn(
        LargestPositiveIntegerThatExistsWithItsNegativeSolution()
            .getStrategyNames()));

#include <gtest/gtest.h>

#include "leetcode/problems/minimum-elements-to-add-to-form-a-given-sum.h"

namespace leetcode::problem_1785 {

class MinimumElementsToAddToFormAGivenSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumElementsToAddToFormAGivenSumSolution solution;
};

TEST_P(MinimumElementsToAddToFormAGivenSumTest, Example1) {
  std::vector<int> nums = {1, -1, 1};
  EXPECT_EQ(2, solution.minElements(nums, 3, -4));
}

TEST_P(MinimumElementsToAddToFormAGivenSumTest, Example2) {
  std::vector<int> nums = {1, -10, 9, 1};
  EXPECT_EQ(1, solution.minElements(nums, 100, 0));
}

TEST_P(MinimumElementsToAddToFormAGivenSumTest, AlreadyAtGoal) {
  std::vector<int> nums = {3, -3};
  EXPECT_EQ(0, solution.minElements(nums, 3, 0));
}

TEST_P(MinimumElementsToAddToFormAGivenSumTest, NegativeGoal) {
  std::vector<int> nums = {2, 3};
  EXPECT_EQ(1, solution.minElements(nums, 10, -5));
}

TEST_P(MinimumElementsToAddToFormAGivenSumTest, LargeGap) {
  std::vector<int> nums = {1};
  EXPECT_EQ(4, solution.minElements(nums, 2, 9));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumElementsToAddToFormAGivenSumTestSuite,
    MinimumElementsToAddToFormAGivenSumTest,
    ::testing::ValuesIn(MinimumElementsToAddToFormAGivenSumSolution()
                             .getStrategyNames()));

}  // namespace leetcode::problem_1785

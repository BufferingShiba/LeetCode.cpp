#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/sum-of-squares-of-special-elements.h"

namespace leetcode::problem_2778 {

class SumOfSquaresOfSpecialElementsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SumOfSquaresOfSpecialElementsSolution solution;
};

TEST_P(SumOfSquaresOfSpecialElementsTest, Example1) {
  std::vector<int> nums{1, 2, 3, 4};
  EXPECT_EQ(21, solution.sumOfSquares(nums));
}

TEST_P(SumOfSquaresOfSpecialElementsTest, Example2) {
  std::vector<int> nums{2, 7, 1, 19, 18, 3};
  EXPECT_EQ(63, solution.sumOfSquares(nums));
}

TEST_P(SumOfSquaresOfSpecialElementsTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  EXPECT_EQ(25, solution.sumOfSquares(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SumOfSquaresOfSpecialElementsTestParameters,
    SumOfSquaresOfSpecialElementsTest,
    ::testing::ValuesIn(SumOfSquaresOfSpecialElementsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2778

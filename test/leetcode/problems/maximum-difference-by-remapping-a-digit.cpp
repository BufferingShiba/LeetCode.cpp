#include <gtest/gtest.h>

#include "leetcode/problems/maximum-difference-by-remapping-a-digit.h"

namespace leetcode::problem_2566 {

class MaximumDifferenceByRemappingADigitTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumDifferenceByRemappingADigitSolution solution;
};

TEST_P(MaximumDifferenceByRemappingADigitTest, OfficialExamples) {
  // Example 1
  EXPECT_EQ(solution.minMaxDifference(11891), 99009);
  // Example 2
  EXPECT_EQ(solution.minMaxDifference(90), 99);
}

TEST_P(MaximumDifferenceByRemappingADigitTest, SelfAuthored) {
  // Single digit: max=9, min=0, diff=9
  EXPECT_EQ(solution.minMaxDifference(5), 9);
  // All same non-9 digit: max=999, min=0, diff=999
  EXPECT_EQ(solution.minMaxDifference(555), 999);
  // Two-digit with 0: max=90 (1->9), min=0 (1->0), diff=90
  EXPECT_EQ(solution.minMaxDifference(10), 90);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumDifferenceByRemappingADigitTest,
    testing::ValuesIn(
        MaximumDifferenceByRemappingADigitSolution().getStrategyNames()));

}  // namespace leetcode::problem_2566

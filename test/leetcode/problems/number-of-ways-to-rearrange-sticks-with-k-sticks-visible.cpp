#include <gtest/gtest.h>

#include "leetcode/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible.h"

namespace leetcode::problem_1866 {

class NumberOfWaysToRearrangeSticksWithKSticksVisibleTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution solution;
};

TEST_P(NumberOfWaysToRearrangeSticksWithKSticksVisibleTest, Example1) {
  EXPECT_EQ(solution.rearrangeSticks(3, 2), 3);
}

TEST_P(NumberOfWaysToRearrangeSticksWithKSticksVisibleTest, Example2) {
  EXPECT_EQ(solution.rearrangeSticks(5, 5), 1);
}

TEST_P(NumberOfWaysToRearrangeSticksWithKSticksVisibleTest, Example3) {
  EXPECT_EQ(solution.rearrangeSticks(20, 11), 647427950);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfWaysToRearrangeSticksWithKSticksVisibleTest,
    testing::ValuesIn(
        NumberOfWaysToRearrangeSticksWithKSticksVisibleSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1866

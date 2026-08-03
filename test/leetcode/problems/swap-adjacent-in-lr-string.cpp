#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/swap-adjacent-in-lr-string.h"

namespace leetcode::problem_777 {

namespace {

class SwapAdjacentInLrStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  SwapAdjacentInLrStringSolution solution;
};

TEST_P(SwapAdjacentInLrStringTest, Example1) {
  EXPECT_TRUE(solution.canTransform("RXXLRXRXL", "XRLXXRRLX"));
}

TEST_P(SwapAdjacentInLrStringTest, Example2) {
  EXPECT_FALSE(solution.canTransform("X", "L"));
}

TEST_P(SwapAdjacentInLrStringTest, SelfAuthoredStartEqualsResult) {
  EXPECT_TRUE(solution.canTransform("RXXLRXRXL", "RXXLRXRXL"));
}

TEST_P(SwapAdjacentInLrStringTest, SelfAuthoredLRCrossingImpossible) {
  // 'L' and 'R' cannot cross each other.
  EXPECT_FALSE(solution.canTransform("LX", "XL"));
}

TEST_P(SwapAdjacentInLrStringTest, SelfAuthoredLeftOnlyMovesLeft) {
  EXPECT_FALSE(solution.canTransform("LX", "XL"));
  EXPECT_TRUE(solution.canTransform("XL", "LX"));
}

TEST_P(SwapAdjacentInLrStringTest, SelfAuthoredRightOnlyMovesRight) {
  EXPECT_TRUE(solution.canTransform("RX", "XR"));
  EXPECT_FALSE(solution.canTransform("XR", "RX"));
}

TEST_P(SwapAdjacentInLrStringTest, SelfAuthoredSingleLBlocked) {
  EXPECT_FALSE(solution.canTransform("L", "R"));
}

INSTANTIATE_TEST_SUITE_P(
    SwapAdjacentInLrStringTestSuite, SwapAdjacentInLrStringTest,
    ::testing::ValuesIn(SwapAdjacentInLrStringSolution().getStrategyNames()));

}  // namespace

}  // namespace leetcode::problem_777

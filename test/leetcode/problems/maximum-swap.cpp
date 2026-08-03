#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/maximum-swap.h"

namespace leetcode::problem_670::test {

class MaximumSwapTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  MaximumSwapSolution solution;
};

TEST_P(MaximumSwapTest, Example1) {
  EXPECT_EQ(7236, solution.maximumSwap(2736));
}

TEST_P(MaximumSwapTest, Example2) {
  EXPECT_EQ(9973, solution.maximumSwap(9973));
}

TEST_P(MaximumSwapTest, SingleDigit) {
  EXPECT_EQ(9, solution.maximumSwap(9));
}

TEST_P(MaximumSwapTest, AlreadyDescending) {
  EXPECT_EQ(98321, solution.maximumSwap(98321));
}

TEST_P(MaximumSwapTest, Zero) {
  EXPECT_EQ(0, solution.maximumSwap(0));
}

TEST_P(MaximumSwapTest, SwapWithinLargerGroup) {
  EXPECT_EQ(9913, solution.maximumSwap(1993));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumSwapStrategies,
    MaximumSwapTest,
    ::testing::ValuesIn(MaximumSwapSolution().getStrategyNames()));

}  // namespace leetcode::problem_670::test

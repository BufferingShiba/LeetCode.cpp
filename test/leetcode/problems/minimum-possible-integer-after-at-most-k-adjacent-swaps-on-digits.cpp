#include <gtest/gtest.h>

#include "leetcode/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits.h"

using namespace leetcode::problem_1505;

class MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsTest, Example1) {
  EXPECT_EQ(solution.minInteger("4321", 4), "1342");
}

TEST_P(MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsTest, Example2) {
  EXPECT_EQ(solution.minInteger("100", 1), "010");
}

TEST_P(MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsTest, Example3) {
  EXPECT_EQ(solution.minInteger("36789", 1000), "36789");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsTest,
    ::testing::ValuesIn(
        MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigitsSolution()
            .getStrategyNames()));

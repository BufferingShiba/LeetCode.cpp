#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/arranging-coins.h"

namespace leetcode::problem_441 {

class ArrangingCoinsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ArrangingCoinsSolution solution_;
};

TEST_P(ArrangingCoinsTest, Example1) {
  EXPECT_EQ(solution_.arrangeCoins(5), 2);
}

TEST_P(ArrangingCoinsTest, Example2) {
  EXPECT_EQ(solution_.arrangeCoins(8), 3);
}

TEST_P(ArrangingCoinsTest, SelfAuthoredSingleCoin) {
  EXPECT_EQ(solution_.arrangeCoins(1), 1);
}

TEST_P(ArrangingCoinsTest, SelfAuthoredTwoCoins) {
  EXPECT_EQ(solution_.arrangeCoins(2), 1);
}

TEST_P(ArrangingCoinsTest, SelfAuthoredMaxValue) {
  // n = 2^31 - 1, full rows k satisfies k*(k+1)/2 <= n
  // k = 65535 gives 65535*65536/2 = 2147450880; k = 65536 gives 2147516416 > n
  EXPECT_EQ(solution_.arrangeCoins(2147483647), 65535);
}

INSTANTIATE_TEST_SUITE_P(
    ArrangingCoinsTestSuite, ArrangingCoinsTest,
    ::testing::ValuesIn(ArrangingCoinsSolution().getStrategyNames()));

}  // namespace leetcode::problem_441

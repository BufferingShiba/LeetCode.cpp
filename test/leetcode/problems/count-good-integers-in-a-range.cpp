#include "leetcode/problems/count-good-integers-in-a-range.h"

#include <gtest/gtest.h>

using namespace leetcode::problem_3966;

class CountGoodIntegersInARangeTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountGoodIntegersInARangeSolution solution;
};

TEST_P(CountGoodIntegersInARangeTest, Example1) {
  EXPECT_EQ(3, solution.goodIntegers(10, 15, 1));
}

TEST_P(CountGoodIntegersInARangeTest, Example2) {
  EXPECT_EQ(2, solution.goodIntegers(201, 204, 2));
}

TEST_P(CountGoodIntegersInARangeTest, SingleLargerRangeK0) {
  // k = 0 means adjacent digits must be equal.
  // 1..100: single digits 1-9 (9), two-digit repeats 11..99 (9). Total 18.
  EXPECT_EQ(18, solution.goodIntegers(1, 100, 0));
}

TEST_P(CountGoodIntegersInARangeTest, SmallRangeK9) {
  // k=9 makes every integer good.
  EXPECT_EQ(5, solution.goodIntegers(10, 14, 9));
}

TEST_P(CountGoodIntegersInARangeTest, StartsAtBoundary) {
  EXPECT_EQ(1, solution.goodIntegers(10, 10, 1));
}

INSTANTIATE_TEST_SUITE_P(
    CountGoodIntegersInARangeStrategies,
    CountGoodIntegersInARangeTest,
    ::testing::ValuesIn(CountGoodIntegersInARangeSolution().getStrategyNames()));

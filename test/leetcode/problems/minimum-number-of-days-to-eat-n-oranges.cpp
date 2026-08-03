#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-days-to-eat-n-oranges.h"

namespace leetcode {
namespace problem_1553 {
namespace {

class MinimumNumberOfDaysToEatNOrangesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumNumberOfDaysToEatNOrangesSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumNumberOfDaysToEatNOrangesTest, Example1) {
  EXPECT_EQ(solution.minDays(10), 4);
}

TEST_P(MinimumNumberOfDaysToEatNOrangesTest, Example2) {
  EXPECT_EQ(solution.minDays(6), 3);
}

TEST_P(MinimumNumberOfDaysToEatNOrangesTest, SelfAuthoredSmallValues) {
  EXPECT_EQ(solution.minDays(1), 1);
  EXPECT_EQ(solution.minDays(2), 2);
  EXPECT_EQ(solution.minDays(3), 2);
  EXPECT_EQ(solution.minDays(4), 3);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfDaysToEatNOrangesStrategies,
    MinimumNumberOfDaysToEatNOrangesTest,
    ::testing::ValuesIn(
        MinimumNumberOfDaysToEatNOrangesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1553
}  // namespace leetcode

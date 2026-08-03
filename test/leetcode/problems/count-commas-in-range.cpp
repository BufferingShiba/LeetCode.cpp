#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/count-commas-in-range.h"

namespace leetcode::problem_3870 {

class CountCommasInRangeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountCommasInRangeSolution solution;
};

TEST_P(CountCommasInRangeTest, Example1) {
  EXPECT_EQ(3, solution.countCommas(1002));
}

TEST_P(CountCommasInRangeTest, Example2) {
  EXPECT_EQ(0, solution.countCommas(998));
}

TEST_P(CountCommasInRangeTest, SingleDigit) {
  EXPECT_EQ(0, solution.countCommas(5));
}

TEST_P(CountCommasInRangeTest, ExactlyThousand) {
  EXPECT_EQ(1, solution.countCommas(1000));
}

TEST_P(CountCommasInRangeTest, UpperBound) {
  EXPECT_EQ(100000 - 999, solution.countCommas(100000));
}

INSTANTIATE_TEST_SUITE_P(
    CountCommasInRangeTestSuite, CountCommasInRangeTest,
    ::testing::ValuesIn(CountCommasInRangeSolution().getStrategyNames()));

}  // namespace leetcode::problem_3870

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-compatible-numbers-in-range-i.h"

namespace leetcode::problem_3954 {

class SumOfCompatibleNumbersInRangeITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfCompatibleNumbersInRangeISolution solution_;
};

TEST_P(SumOfCompatibleNumbersInRangeITest, Example1) {
  EXPECT_EQ(solution_.sumOfGoodIntegers(2, 3), 10);
}

TEST_P(SumOfCompatibleNumbersInRangeITest, Example2) {
  EXPECT_EQ(solution_.sumOfGoodIntegers(5, 1), 0);
}

TEST_P(SumOfCompatibleNumbersInRangeITest, SelfAuthoredSingleValueRange) {
  // n = 1, k = 1: candidates x in [1, 2].
  // x=1: (1&1)=1 !=0; x=2: (1&2)=0 -> sum=2.
  EXPECT_EQ(solution_.sumOfGoodIntegers(1, 1), 2);
}

INSTANTIATE_TEST_SUITE_P(
    SumOfCompatibleNumbersInRangeITestSuite,
    SumOfCompatibleNumbersInRangeITest,
    ::testing::ValuesIn(SumOfCompatibleNumbersInRangeISolution().getStrategyNames()));

}  // namespace leetcode::problem_3954

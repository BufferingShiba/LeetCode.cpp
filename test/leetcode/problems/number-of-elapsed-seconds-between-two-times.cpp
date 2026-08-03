#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-elapsed-seconds-between-two-times.h"

namespace leetcode::problem_3986 {

class NumberOfElapsedSecondsBetweenTwoTimesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfElapsedSecondsBetweenTwoTimesSolution solution;
};

TEST_P(NumberOfElapsedSecondsBetweenTwoTimesTest, Example1) {
  EXPECT_EQ(solution.secondsBetweenTimes("01:00:00", "01:00:25"), 25);
}

TEST_P(NumberOfElapsedSecondsBetweenTwoTimesTest, Example2) {
  EXPECT_EQ(solution.secondsBetweenTimes("12:34:56", "13:00:00"), 1504);
}

TEST_P(NumberOfElapsedSecondsBetweenTwoTimesTest, SelfAuthoredSameTime) {
  EXPECT_EQ(solution.secondsBetweenTimes("08:30:15", "08:30:15"), 0);
}

TEST_P(NumberOfElapsedSecondsBetweenTwoTimesTest, SelfAuthoredSameStartOfHour) {
  EXPECT_EQ(solution.secondsBetweenTimes("00:00:00", "23:59:59"), 86399);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfElapsedSecondsBetweenTwoTimesTestSuite,
    NumberOfElapsedSecondsBetweenTwoTimesTest,
    ::testing::ValuesIn(
        NumberOfElapsedSecondsBetweenTwoTimesSolution().getStrategyNames()));

}  // namespace leetcode::problem_3986

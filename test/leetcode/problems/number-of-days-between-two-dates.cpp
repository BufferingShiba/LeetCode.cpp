#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-days-between-two-dates.h"

namespace leetcode {
namespace problem_1360 {
namespace {

class NumberOfDaysBetweenTwoDatesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfDaysBetweenTwoDatesSolution solution_;
};

TEST_P(NumberOfDaysBetweenTwoDatesTest, Example1) {
  EXPECT_EQ(1, solution_.daysBetweenDates("2019-06-29", "2019-06-30"));
}

TEST_P(NumberOfDaysBetweenTwoDatesTest, Example2) {
  EXPECT_EQ(15, solution_.daysBetweenDates("2020-01-15", "2019-12-31"));
}

TEST_P(NumberOfDaysBetweenTwoDatesTest, SelfAuthoredSameDate) {
  EXPECT_EQ(0, solution_.daysBetweenDates("1971-01-01", "1971-01-01"));
}

TEST_P(NumberOfDaysBetweenTwoDatesTest, SelfAuthoredLeapYear) {
  // 2020 is a leap year; Feb 1 to Mar 1 spans 29 days.
  EXPECT_EQ(29, solution_.daysBetweenDates("2020-02-01", "2020-03-01"));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfDaysBetweenTwoDatesTestSuite, NumberOfDaysBetweenTwoDatesTest,
    ::testing::ValuesIn(NumberOfDaysBetweenTwoDatesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1360
}  // namespace leetcode

#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/day-of-the-week.h"

namespace leetcode::problem_1185 {

class DayOfTheWeekTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  DayOfTheWeekSolution solution_;
};

TEST_P(DayOfTheWeekTest, Example1) {
  EXPECT_EQ("Saturday", solution_.dayOfTheWeek(31, 8, 2019));
}

TEST_P(DayOfTheWeekTest, Example2) {
  EXPECT_EQ("Sunday", solution_.dayOfTheWeek(18, 7, 1999));
}

TEST_P(DayOfTheWeekTest, Example3) {
  EXPECT_EQ("Sunday", solution_.dayOfTheWeek(15, 8, 1993));
}

TEST_P(DayOfTheWeekTest, SelfAuthoredReferenceDate) {
  // 1971-01-01 is a Friday (given in problem).
  EXPECT_EQ("Friday", solution_.dayOfTheWeek(1, 1, 1971));
}

TEST_P(DayOfTheWeekTest, SelfAuthoredLeapYearFeb29) {
  // 2000-02-29: verified known day.
  EXPECT_EQ("Tuesday", solution_.dayOfTheWeek(29, 2, 2000));
}

INSTANTIATE_TEST_SUITE_P(
    DayOfTheWeekTestCases, DayOfTheWeekTest,
    ::testing::ValuesIn(DayOfTheWeekSolution().getStrategyNames()));

}  // namespace leetcode::problem_1185

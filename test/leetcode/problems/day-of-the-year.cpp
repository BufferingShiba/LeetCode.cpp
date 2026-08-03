#include "leetcode/problems/day-of-the-year.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using leetcode::problem_1154::DayOfTheYearSolution;

class DayOfTheYearTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  DayOfTheYearSolution solution;
};

TEST_P(DayOfTheYearTest, Examples) {
  EXPECT_EQ(solution.dayOfYear("2019-01-09"), 9);
  EXPECT_EQ(solution.dayOfYear("2019-02-10"), 41);
}

TEST_P(DayOfTheYearTest, EdgeCases) {
  // 边界：年初与年末
  EXPECT_EQ(solution.dayOfYear("1900-01-01"), 1);
  EXPECT_EQ(solution.dayOfYear("2019-12-31"), 365);
  // 闰年二月末
  EXPECT_EQ(solution.dayOfYear("2016-02-29"), 60);
  // 闰年三月一号
  EXPECT_EQ(solution.dayOfYear("2016-03-01"), 61);
}

INSTANTIATE_TEST_SUITE_P(DayOfTheYear, DayOfTheYearTest,
                         ::testing::ValuesIn(DayOfTheYearSolution().getStrategyNames()));

#include <gtest/gtest.h>

#include "leetcode/problems/count-days-spent-together.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2409 {
namespace {

class CountDaysSpentTogetherTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountDaysSpentTogetherSolution solution;
};

TEST_P(CountDaysSpentTogetherTest, Example1) {
  EXPECT_EQ(3, solution.countDaysTogether("08-15", "08-18", "08-16", "08-19"));
}

TEST_P(CountDaysSpentTogetherTest, Example2) {
  EXPECT_EQ(0, solution.countDaysTogether("10-01", "10-31", "11-01", "12-31"));
}

TEST_P(CountDaysSpentTogetherTest, SameRange) {
  EXPECT_EQ(16, solution.countDaysTogether("01-10", "01-25", "01-10", "01-25"));
}

TEST_P(CountDaysSpentTogetherTest, TouchingPartialOverlap) {
  EXPECT_EQ(3, solution.countDaysTogether("08-18", "08-20", "08-18", "08-22"));
}

INSTANTIATE_TEST_SUITE_P(
    CountDaysSpentTogetherTestSuite, CountDaysSpentTogetherTest,
    ::testing::ValuesIn(CountDaysSpentTogetherSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2409
}  // namespace leetcode

#include <gtest/gtest.h>

#include "leetcode/problems/count-days-without-meetings.h"

namespace leetcode {
namespace problem_3169 {

class CountDaysWithoutMeetingsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountDaysWithoutMeetingsSolution solution;
};

TEST_P(CountDaysWithoutMeetingsTest, Example1) {
  int days = 10;
  std::vector<std::vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};
  EXPECT_EQ(solution.countDays(days, meetings), 2);
}

TEST_P(CountDaysWithoutMeetingsTest, Example2) {
  int days = 5;
  std::vector<std::vector<int>> meetings = {{2, 4}, {1, 3}};
  EXPECT_EQ(solution.countDays(days, meetings), 1);
}

TEST_P(CountDaysWithoutMeetingsTest, Example3) {
  int days = 6;
  std::vector<std::vector<int>> meetings = {{1, 6}};
  EXPECT_EQ(solution.countDays(days, meetings), 0);
}

TEST_P(CountDaysWithoutMeetingsTest, SelfAuthoredNoMeetings) {
  int days = 100;
  std::vector<std::vector<int>> meetings = {};
  EXPECT_EQ(solution.countDays(days, meetings), 100);
}

TEST_P(CountDaysWithoutMeetingsTest, SelfAuthoredAllDaysCovered) {
  int days = 7;
  std::vector<std::vector<int>> meetings = {{1, 7}};
  EXPECT_EQ(solution.countDays(days, meetings), 0);
}

TEST_P(CountDaysWithoutMeetingsTest, SelfAuthoredSingleDayGaps) {
  int days = 5;
  std::vector<std::vector<int>> meetings = {{1, 1}, {3, 3}, {5, 5}};
  EXPECT_EQ(solution.countDays(days, meetings), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountDaysWithoutMeetingsTest,
    ::testing::ValuesIn(
        CountDaysWithoutMeetingsSolution().getStrategyNames()));

}  // namespace problem_3169
}  // namespace leetcode

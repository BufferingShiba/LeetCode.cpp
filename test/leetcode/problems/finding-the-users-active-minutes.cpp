#include <gtest/gtest.h>

#include "leetcode/problems/finding-the-users-active-minutes.h"

using namespace leetcode::problem_1817;

class FindingTheUsersActiveMinutesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  FindingTheUsersActiveMinutesSolution solution_;
};

TEST_P(FindingTheUsersActiveMinutesTest, Example1) {
  std::vector<std::vector<int>> logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
  int k = 5;
  std::vector<int> expected = {0, 2, 0, 0, 0};
  EXPECT_EQ(solution_.findingUsersActiveMinutes(logs, k), expected);
}

TEST_P(FindingTheUsersActiveMinutesTest, Example2) {
  std::vector<std::vector<int>> logs = {{1, 1}, {2, 2}, {2, 3}};
  int k = 4;
  std::vector<int> expected = {1, 1, 0, 0};
  EXPECT_EQ(solution_.findingUsersActiveMinutes(logs, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindingTheUsersActiveMinutesTest,
    testing::ValuesIn(
        FindingTheUsersActiveMinutesSolution().getStrategyNames()));

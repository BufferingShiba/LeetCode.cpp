#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/the-employee-that-worked-on-the-longest-task.h"

namespace leetcode::problem_2432 {

class TheEmployeeThatWorkedOnTheLongestTaskTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TheEmployeeThatWorkedOnTheLongestTaskSolution solution_;
};

TEST_P(TheEmployeeThatWorkedOnTheLongestTaskTest, Example1) {
  int n = 10;
  std::vector<std::vector<int>> logs = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
  EXPECT_EQ(solution_.hardestWorker(n, logs), 1);
}

TEST_P(TheEmployeeThatWorkedOnTheLongestTaskTest, Example2) {
  int n = 26;
  std::vector<std::vector<int>> logs = {{1, 1}, {3, 7}, {2, 12}, {7, 17}};
  EXPECT_EQ(solution_.hardestWorker(n, logs), 3);
}

TEST_P(TheEmployeeThatWorkedOnTheLongestTaskTest, Example3) {
  int n = 2;
  std::vector<std::vector<int>> logs = {{0, 10}, {1, 20}};
  EXPECT_EQ(solution_.hardestWorker(n, logs), 0);
}

TEST_P(TheEmployeeThatWorkedOnTheLongestTaskTest, SingleTask) {
  int n = 3;
  std::vector<std::vector<int>> logs = {{2, 7}};
  EXPECT_EQ(solution_.hardestWorker(n, logs), 2);
}

INSTANTIATE_TEST_SUITE_P(
    TheEmployeeThatWorkedOnTheLongestTaskTestSuite,
    TheEmployeeThatWorkedOnTheLongestTaskTest,
    ::testing::ValuesIn(
        TheEmployeeThatWorkedOnTheLongestTaskSolution().getStrategyNames()));

}  // namespace leetcode::problem_2432

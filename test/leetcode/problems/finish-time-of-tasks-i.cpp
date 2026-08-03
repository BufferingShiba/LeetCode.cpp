#include "leetcode/problems/finish-time-of-tasks-i.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_3965 {

class FinishTimeOfTasksITest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FinishTimeOfTasksISolution solution;
};

TEST_P(FinishTimeOfTasksITest, Example1) {
  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {1, 2}};
  vector<int> baseTime = {9, 5, 3};
  EXPECT_EQ(17, solution.finishTime(n, edges, baseTime));
}

TEST_P(FinishTimeOfTasksITest, Example2) {
  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {0, 2}};
  vector<int> baseTime = {4, 7, 6};
  EXPECT_EQ(12, solution.finishTime(n, edges, baseTime));
}

TEST_P(FinishTimeOfTasksITest, Example3) {
  int n = 4;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}};
  vector<int> baseTime = {5, 8, 2, 1};
  EXPECT_EQ(18, solution.finishTime(n, edges, baseTime));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, FinishTimeOfTasksITest,
    ::testing::ValuesIn(FinishTimeOfTasksISolution().getStrategyNames()));

}  // namespace problem_3965
}  // namespace leetcode

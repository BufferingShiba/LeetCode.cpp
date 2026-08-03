#include <gtest/gtest.h>

#include "leetcode/problems/minimum-number-of-work-sessions-to-finish-the-tasks.h"

namespace leetcode::problem_1986 {

class MinimumNumberOfWorkSessionsToFinishTheTasksTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfWorkSessionsToFinishTheTasksSolution solution_;
};

TEST_P(MinimumNumberOfWorkSessionsToFinishTheTasksTest, Example1) {
  std::vector<int> tasks = {1, 2, 3};
  int sessionTime = 3;
  EXPECT_EQ(solution_.minSessions(tasks, sessionTime), 2);
}

TEST_P(MinimumNumberOfWorkSessionsToFinishTheTasksTest, Example2) {
  std::vector<int> tasks = {3, 1, 3, 1, 1};
  int sessionTime = 8;
  EXPECT_EQ(solution_.minSessions(tasks, sessionTime), 2);
}

TEST_P(MinimumNumberOfWorkSessionsToFinishTheTasksTest, Example3) {
  std::vector<int> tasks = {1, 2, 3, 4, 5};
  int sessionTime = 15;
  EXPECT_EQ(solution_.minSessions(tasks, sessionTime), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfWorkSessionsToFinishTheTasksTest,
    testing::ValuesIn(
        MinimumNumberOfWorkSessionsToFinishTheTasksSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1986

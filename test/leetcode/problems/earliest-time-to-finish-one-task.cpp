#include <gtest/gtest.h>

#include "leetcode/problems/earliest-time-to-finish-one-task.h"

namespace leetcode {
namespace problem_3683 {

class EarliestTimeToFinishOneTaskTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  EarliestTimeToFinishOneTaskSolution solution_;
};

TEST_P(EarliestTimeToFinishOneTaskTest, OfficialExamples) {
  std::vector<std::vector<int>> tasks1 = {{1, 6}, {2, 3}};
  EXPECT_EQ(solution_.earliestTime(tasks1), 5);

  std::vector<std::vector<int>> tasks2 = {{100, 100}, {100, 100}, {100, 100}};
  EXPECT_EQ(solution_.earliestTime(tasks2), 200);
}

TEST_P(EarliestTimeToFinishOneTaskTest, SingleTask) {
  std::vector<std::vector<int>> tasks = {{7, 9}};
  EXPECT_EQ(solution_.earliestTime(tasks), 16);
}

TEST_P(EarliestTimeToFinishOneTaskTest, SelfAuthoredFirstIsEarliest) {
  std::vector<std::vector<int>> tasks = {{1, 1}, {10, 10}, {5, 5}};
  EXPECT_EQ(solution_.earliestTime(tasks), 2);
}

TEST_P(EarliestTimeToFinishOneTaskTest, SelfAuthoredLastIsEarliest) {
  std::vector<std::vector<int>> tasks = {{10, 10}, {5, 5}, {1, 1}};
  EXPECT_EQ(solution_.earliestTime(tasks), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    EarliestTimeToFinishOneTaskTest,
    ::testing::ValuesIn(
        EarliestTimeToFinishOneTaskSolution().getStrategyNames()));

}  // namespace problem_3683
}  // namespace leetcode

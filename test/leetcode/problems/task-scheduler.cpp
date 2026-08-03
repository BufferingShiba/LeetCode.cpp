#include <gtest/gtest.h>

#include "leetcode/problems/task-scheduler.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_621 {
namespace {

class TaskSchedulerTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  TaskSchedulerSolution solution_;
};

TEST_P(TaskSchedulerTest, Example1) {
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  EXPECT_EQ(8, solution_.leastInterval(tasks, 2));
}

TEST_P(TaskSchedulerTest, Example2) {
  std::vector<char> tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
  EXPECT_EQ(6, solution_.leastInterval(tasks, 1));
}

TEST_P(TaskSchedulerTest, Example3) {
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  EXPECT_EQ(10, solution_.leastInterval(tasks, 3));
}

TEST_P(TaskSchedulerTest, SelfAuthoredZeroCooling) {
  std::vector<char> tasks = {'A', 'A', 'A', 'B', 'B'};
  EXPECT_EQ(5, solution_.leastInterval(tasks, 0));
}

TEST_P(TaskSchedulerTest, SelfAuthoredSingleTask) {
  std::vector<char> tasks = {'A'};
  EXPECT_EQ(1, solution_.leastInterval(tasks, 2));
}

TEST_P(TaskSchedulerTest, SelfAuthoredAllSameTask) {
  std::vector<char> tasks = {'A', 'A', 'A', 'A'};
  EXPECT_EQ(13, solution_.leastInterval(tasks, 3));
}

INSTANTIATE_TEST_SUITE_P(
    TaskSchedulerStrategies,
    TaskSchedulerTest,
    ::testing::ValuesIn(TaskSchedulerSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_621
}  // namespace leetcode

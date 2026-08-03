#include <gtest/gtest.h>

#include "leetcode/problems/maximum-number-of-tasks-you-can-assign.h"

namespace leetcode {
namespace problem_2071 {

class MaximumNumberOfTasksYouCanAssignTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfTasksYouCanAssignSolution solution_;
};

TEST_P(MaximumNumberOfTasksYouCanAssignTest, Example1) {
  std::vector<int> tasks = {3, 2, 1};
  std::vector<int> workers = {0, 3, 3};
  int pills = 1;
  int strength = 1;
  EXPECT_EQ(solution_.maxTaskAssign(tasks, workers, pills, strength), 3);
}

TEST_P(MaximumNumberOfTasksYouCanAssignTest, Example2) {
  std::vector<int> tasks = {5, 4};
  std::vector<int> workers = {0, 0, 0};
  int pills = 1;
  int strength = 5;
  EXPECT_EQ(solution_.maxTaskAssign(tasks, workers, pills, strength), 1);
}

TEST_P(MaximumNumberOfTasksYouCanAssignTest, Example3) {
  std::vector<int> tasks = {10, 15, 30};
  std::vector<int> workers = {0, 10, 10, 10, 10};
  int pills = 3;
  int strength = 10;
  EXPECT_EQ(solution_.maxTaskAssign(tasks, workers, pills, strength), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, MaximumNumberOfTasksYouCanAssignTest,
    ::testing::ValuesIn(
        MaximumNumberOfTasksYouCanAssignSolution().getStrategyNames()));

}  // namespace problem_2071
}  // namespace leetcode

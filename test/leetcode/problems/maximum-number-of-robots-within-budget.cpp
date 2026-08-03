#include <gtest/gtest.h>

#include "leetcode/problems/maximum-number-of-robots-within-budget.h"

namespace leetcode::problem_2398 {

class MaximumNumberOfRobotsWithinBudgetTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfRobotsWithinBudgetSolution solution;
};

TEST_P(MaximumNumberOfRobotsWithinBudgetTest, Example1) {
  std::vector<int> chargeTimes = {3, 6, 1, 3, 4};
  std::vector<int> runningCosts = {2, 1, 3, 4, 5};
  long long budget = 25;
  EXPECT_EQ(solution.maximumRobots(chargeTimes, runningCosts, budget), 3);
}

TEST_P(MaximumNumberOfRobotsWithinBudgetTest, Example2) {
  std::vector<int> chargeTimes = {11, 12, 19};
  std::vector<int> runningCosts = {10, 8, 7};
  long long budget = 19;
  EXPECT_EQ(solution.maximumRobots(chargeTimes, runningCosts, budget), 0);
}

TEST_P(MaximumNumberOfRobotsWithinBudgetTest, SelfAuthoredSingleRobotWithinBudget) {
  std::vector<int> chargeTimes = {5};
  std::vector<int> runningCosts = {3};
  long long budget = 10;
  // cost = max(5) + 1*sum(3) = 5+3 = 8 <= 10
  EXPECT_EQ(solution.maximumRobots(chargeTimes, runningCosts, budget), 1);
}

TEST_P(MaximumNumberOfRobotsWithinBudgetTest, SelfAuthoredSingleRobotExceedsBudget) {
  std::vector<int> chargeTimes = {5};
  std::vector<int> runningCosts = {6};
  long long budget = 10;
  // cost = 5 + 1*6 = 11 > 10
  EXPECT_EQ(solution.maximumRobots(chargeTimes, runningCosts, budget), 0);
}

TEST_P(MaximumNumberOfRobotsWithinBudgetTest, SelfAuthoredAllRobotsFit) {
  std::vector<int> chargeTimes = {1, 2, 3};
  std::vector<int> runningCosts = {1, 1, 1};
  long long budget = 100;
  // k=3: max=3 + 3*3=12 <= 100
  EXPECT_EQ(solution.maximumRobots(chargeTimes, runningCosts, budget), 3);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumNumberOfRobotsWithinBudgetTest,
    testing::ValuesIn(
        MaximumNumberOfRobotsWithinBudgetSolution().getStrategyNames()));

}  // namespace leetcode::problem_2398

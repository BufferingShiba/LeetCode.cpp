#include <gtest/gtest.h>

#include "leetcode/problems/ipo.h"

using namespace leetcode::problem_502;

class IpoTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  IpoSolution solution;
};

TEST_P(IpoTest, Example1) {
  int k = 2, w = 0;
  std::vector<int> profits = {1, 2, 3};
  std::vector<int> capital = {0, 1, 1};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 4);
}

TEST_P(IpoTest, Example2) {
  int k = 3, w = 0;
  std::vector<int> profits = {1, 2, 3};
  std::vector<int> capital = {0, 1, 2};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 6);
}

TEST_P(IpoTest, SelfAuthoredSingleProject) {
  int k = 1, w = 0;
  std::vector<int> profits = {5};
  std::vector<int> capital = {0};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 5);
}

TEST_P(IpoTest, SelfAuthoredInsufficientCapital) {
  int k = 2, w = 0;
  std::vector<int> profits = {1, 2, 3};
  std::vector<int> capital = {10, 20, 30};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 0);
}

TEST_P(IpoTest, SelfAuthoredAllProjectsAffordable) {
  int k = 2, w = 100;
  std::vector<int> profits = {10, 5, 8};
  std::vector<int> capital = {1, 2, 3};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 100 + 10 + 8);
}

TEST_P(IpoTest, SelfAuthoredLargeK) {
  int k = 10, w = 1;
  std::vector<int> profits = {1, 1, 1, 1, 1};
  std::vector<int> capital = {0, 0, 0, 0, 0};
  EXPECT_EQ(solution.findMaximizedCapital(k, w, profits, capital), 6);
}

INSTANTIATE_TEST_SUITE_P(
    IpoStrategies,
    IpoTest,
    ::testing::ValuesIn(IpoSolution().getStrategyNames()));

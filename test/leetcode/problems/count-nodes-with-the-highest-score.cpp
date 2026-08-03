#include <gtest/gtest.h>
#include "leetcode/problems/count-nodes-with-the-highest-score.h"

using namespace leetcode::problem_2049;

class CountNodesWithTheHighestScoreTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  CountNodesWithTheHighestScoreSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CountNodesWithTheHighestScoreTest, Example1) {
  std::vector<int> parents = {-1, 2, 0, 2, 0};
  EXPECT_EQ(solution.countHighestScoreNodes(parents), 3);
}

TEST_P(CountNodesWithTheHighestScoreTest, Example2) {
  std::vector<int> parents = {-1, 2, 0};
  EXPECT_EQ(solution.countHighestScoreNodes(parents), 2);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, CountNodesWithTheHighestScoreTest,
    ::testing::ValuesIn(
        CountNodesWithTheHighestScoreSolution().getStrategyNames()));

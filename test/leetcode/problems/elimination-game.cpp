#include <gtest/gtest.h>
#include "leetcode/problems/elimination-game.h"

using namespace leetcode::problem_390;

class EliminationGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  EliminationGameSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(EliminationGameTest, Example1) {
  EXPECT_EQ(solution.lastRemaining(9), 6);
}

TEST_P(EliminationGameTest, Example2) {
  EXPECT_EQ(solution.lastRemaining(1), 1);
}

TEST_P(EliminationGameTest, SelfAuthored) {
  EXPECT_EQ(solution.lastRemaining(2), 2);
  EXPECT_EQ(solution.lastRemaining(3), 2);
  EXPECT_EQ(solution.lastRemaining(4), 2);
  EXPECT_EQ(solution.lastRemaining(5), 2);
  EXPECT_EQ(solution.lastRemaining(6), 4);
  EXPECT_EQ(solution.lastRemaining(7), 4);
  EXPECT_EQ(solution.lastRemaining(8), 6);
  EXPECT_EQ(solution.lastRemaining(10), 8);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    EliminationGameTest,
    ::testing::ValuesIn(EliminationGameSolution().getStrategyNames()));

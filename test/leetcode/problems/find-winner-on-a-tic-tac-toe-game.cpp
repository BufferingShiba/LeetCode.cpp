#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-winner-on-a-tic-tac-toe-game.h"

namespace leetcode::problem_1275 {

class FindWinnerOnATicTacToeGameTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindWinnerOnATicTacToeGameSolution solution;
};

TEST_P(FindWinnerOnATicTacToeGameTest, Example1) {
  std::vector<std::vector<int>> moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
  EXPECT_EQ("A", solution.tictactoe(moves));
}

TEST_P(FindWinnerOnATicTacToeGameTest, Example2) {
  std::vector<std::vector<int>> moves = {
      {0, 0}, {1, 1}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
  EXPECT_EQ("B", solution.tictactoe(moves));
}

TEST_P(FindWinnerOnATicTacToeGameTest, Example3) {
  std::vector<std::vector<int>> moves = {
      {0, 0}, {1, 1}, {2, 0}, {1, 0}, {1, 2}, {2, 1}, {0, 1}, {0, 2}, {2, 2}};
  EXPECT_EQ("Draw", solution.tictactoe(moves));
}

TEST_P(FindWinnerOnATicTacToeGameTest, SelfAuthoredPendingIncomplete) {
  std::vector<std::vector<int>> moves = {{0, 0}, {1, 1}};
  EXPECT_EQ("Pending", solution.tictactoe(moves));
}

INSTANTIATE_TEST_SUITE_P(
    FindWinnerOnATicTacToeGameTestSuite, FindWinnerOnATicTacToeGameTest,
    ::testing::ValuesIn(FindWinnerOnATicTacToeGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_1275

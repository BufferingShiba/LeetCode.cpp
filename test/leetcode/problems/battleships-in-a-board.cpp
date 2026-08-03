#include <gtest/gtest.h>

#include "leetcode/problems/battleships-in-a-board.h"

using namespace leetcode::problem_419;

class BattleshipsInABoardTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  BattleshipsInABoardSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(BattleshipsInABoardTest, Example1) {
  std::vector<std::vector<char>> board = {
      {'X', '.', '.', 'X'},
      {'.', '.', '.', 'X'},
      {'.', '.', '.', 'X'}};
  EXPECT_EQ(solution.countBattleships(board), 2);
}

TEST_P(BattleshipsInABoardTest, Example2) {
  std::vector<std::vector<char>> board = {{'.'}};
  EXPECT_EQ(solution.countBattleships(board), 0);
}

TEST_P(BattleshipsInABoardTest, SelfAuthoredSingleShipHorizontal) {
  std::vector<std::vector<char>> board = {{'X', 'X', 'X'}};
  EXPECT_EQ(solution.countBattleships(board), 1);
}

TEST_P(BattleshipsInABoardTest, SelfAuthoredSingleShipVertical) {
  std::vector<std::vector<char>> board = {{'X'}, {'X'}, {'X'}, {'X'}};
  EXPECT_EQ(solution.countBattleships(board), 1);
}

TEST_P(BattleshipsInABoardTest, SelfAuthoredMultipleShipsSeparated) {
  std::vector<std::vector<char>> board = {
      {'X', '.', 'X'},
      {'.', '.', '.'},
      {'X', '.', 'X'}};
  EXPECT_EQ(solution.countBattleships(board), 4);
}

INSTANTIATE_TEST_SUITE_P(
    All,
    BattleshipsInABoardTest,
    ::testing::ValuesIn(BattleshipsInABoardSolution().getStrategyNames()));

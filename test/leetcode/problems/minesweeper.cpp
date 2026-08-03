#include <gtest/gtest.h>
#include "leetcode/problems/minesweeper.h"

namespace leetcode {
namespace problem_529 {
namespace {

class MinesweeperTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  MinesweeperSolution solution_;
};

TEST_P(MinesweeperTest, Example1) {
  std::vector<std::vector<char>> board = {
      {'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'M', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E'}};
  std::vector<int> click = {3, 0};
  auto result = solution_.updateBoard(board, click);
  std::vector<std::vector<char>> expected = {
      {'B', '1', 'E', '1', 'B'},
      {'B', '1', 'M', '1', 'B'},
      {'B', '1', '1', '1', 'B'},
      {'B', 'B', 'B', 'B', 'B'}};
  EXPECT_EQ(result, expected);
}

TEST_P(MinesweeperTest, Example2) {
  std::vector<std::vector<char>> board = {
      {'B', '1', 'E', '1', 'B'},
      {'B', '1', 'M', '1', 'B'},
      {'B', '1', '1', '1', 'B'},
      {'B', 'B', 'B', 'B', 'B'}};
  std::vector<int> click = {1, 2};
  auto result = solution_.updateBoard(board, click);
  std::vector<std::vector<char>> expected = {
      {'B', '1', 'E', '1', 'B'},
      {'B', '1', 'X', '1', 'B'},
      {'B', '1', '1', '1', 'B'},
      {'B', 'B', 'B', 'B', 'B'}};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinesweeperTest,
    ::testing::ValuesIn(MinesweeperSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_529
}  // namespace leetcode

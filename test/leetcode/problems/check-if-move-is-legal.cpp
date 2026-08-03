#include <gtest/gtest.h>

#include <functional>
#include <string>
#include <vector>

#include "leetcode/problems/check-if-move-is-legal.h"

namespace leetcode {
namespace problem_1958 {

class CheckIfMoveIsLegalTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfMoveIsLegalSolution solution;
};

std::vector<std::vector<char>> buildBoard(
    const std::vector<std::vector<char>>& raw) {
  return raw;
}

TEST_P(CheckIfMoveIsLegalTest, Example1) {
  auto board = buildBoard({
      {'.', '.', '.', 'B', '.', '.', '.', '.'},
      {'.', '.', '.', 'W', '.', '.', '.', '.'},
      {'.', '.', '.', 'W', '.', '.', '.', '.'},
      {'.', '.', '.', 'W', '.', '.', '.', '.'},
      {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
      {'.', '.', '.', 'B', '.', '.', '.', '.'},
      {'.', '.', '.', 'B', '.', '.', '.', '.'},
      {'.', '.', '.', 'W', '.', '.', '.', '.'},
  });
  EXPECT_TRUE(solution.checkMove(board, 4, 3, 'B'));
}

TEST_P(CheckIfMoveIsLegalTest, Example2) {
  auto board = buildBoard({
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', 'B', '.', '.', 'W', '.', '.', '.'},
      {'.', '.', 'W', '.', '.', '.', '.', '.'},
      {'.', '.', '.', 'W', 'B', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'B', 'W', '.', '.'},
      {'.', '.', '.', '.', '.', '.', 'W', '.'},
      {'.', '.', '.', '.', '.', '.', '.', 'B'},
  });
  EXPECT_FALSE(solution.checkMove(board, 4, 4, 'W'));
}

TEST_P(CheckIfMoveIsLegalTest, SelfAuthoredGoodLine) {
  auto board = buildBoard({
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', 'W', 'B', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
  });
  // Place 'B' at (4,4): moving right sees W then B -> good line of length 3.
  EXPECT_TRUE(solution.checkMove(board, 4, 4, 'B'));
}

TEST_P(CheckIfMoveIsLegalTest, SelfAuthoredTooShortLine) {
  auto board = buildBoard({
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'B', 'W', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.'},
  });
  // Place 'W' at (4,4): moving right (4,5)='W' same color adjacent -> not good.
  EXPECT_FALSE(solution.checkMove(board, 4, 4, 'W'));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfMoveIsLegalTestSuite, CheckIfMoveIsLegalTest,
    ::testing::ValuesIn(CheckIfMoveIsLegalSolution().getStrategyNames()));

}  // namespace problem_1958
}  // namespace leetcode

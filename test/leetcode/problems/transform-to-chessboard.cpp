#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/transform-to-chessboard.h"

namespace leetcode {
namespace problem_782 {
namespace {

class TransformToChessboardTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TransformToChessboardSolution solution_;
};

TEST_P(TransformToChessboardTest, Example1) {
  std::vector<std::vector<int>> board = {{0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}};
  EXPECT_EQ(2, solution_.movesToChessboard(board));
}

TEST_P(TransformToChessboardTest, Example2) {
  std::vector<std::vector<int>> board = {{0, 1}, {1, 0}};
  EXPECT_EQ(0, solution_.movesToChessboard(board));
}

TEST_P(TransformToChessboardTest, Example3) {
  std::vector<std::vector<int>> board = {{1, 0}, {1, 0}};
  EXPECT_EQ(-1, solution_.movesToChessboard(board));
}

TEST_P(TransformToChessboardTest, AlreadyAlternatingOdd) {
  std::vector<std::vector<int>> board = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
  EXPECT_EQ(0, solution_.movesToChessboard(board));
}

TEST_P(TransformToChessboardTest, IdentityMatrixImpossible) {
  std::vector<std::vector<int>> board = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(-1, solution_.movesToChessboard(board));
}

TEST_P(TransformToChessboardTest, OddTwoSwap) {
  std::vector<std::vector<int>> board = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(2, solution_.movesToChessboard(board));
}

INSTANTIATE_TEST_SUITE_P(
    TransformToChessboardTestSuite, TransformToChessboardTest,
    ::testing::ValuesIn(TransformToChessboardSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_782
}  // namespace leetcode

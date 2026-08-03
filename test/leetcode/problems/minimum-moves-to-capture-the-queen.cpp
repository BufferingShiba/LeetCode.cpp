#include <gtest/gtest.h>

#include "leetcode/problems/minimum-moves-to-capture-the-queen.h"

using namespace leetcode::problem_3001;

class MinimumMovesToCaptureTheQueenTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MinimumMovesToCaptureTheQueenSolution solution;
};

TEST_P(MinimumMovesToCaptureTheQueenTest, Example1) {
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(1, 1, 8, 8, 2, 3), 2);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, Example2) {
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(5, 3, 3, 4, 5, 2), 1);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredRookDirectSameRow) {
  // Rook (1,1), Bishop (8,8), Queen (1,5): rook can capture in one move
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(1, 1, 8, 8, 1, 5), 1);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredRookDirectSameCol) {
  // Rook (3,1), Bishop (8,8), Queen (7,1): rook can capture in one move
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(3, 1, 8, 8, 7, 1), 1);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredBishopDirect) {
  // Bishop (3,3), Rook (1,8), Queen (6,6): bishop can capture in one move
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(1, 8, 3, 3, 6, 6), 1);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredRookBlockedByBishop) {
  // Rook (1,1), Bishop (1,3), Queen (1,5): rook blocked, bishop cannot, need 2
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(1, 1, 1, 3, 1, 5), 2);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredBishopBlockedByRook) {
  // Bishop (1,1), Rook (2,2), Queen (3,3): bishop blocked by rook, need 2
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(2, 2, 1, 1, 3, 3), 2);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredRookNotBlockedBishopOffRow) {
  // Rook (4,4), Bishop (1,3), Queen (4,8): rook same row, bishop not blocking
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(4, 4, 1, 3, 4, 8), 1);
}

TEST_P(MinimumMovesToCaptureTheQueenTest, SelfAuthoredNeedTwoMoves) {
  // No direct attack possible
  EXPECT_EQ(solution.minMovesToCaptureTheQueen(1, 1, 3, 3, 5, 8), 2);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, MinimumMovesToCaptureTheQueenTest,
                         testing::ValuesIn(
                             MinimumMovesToCaptureTheQueenSolution().getStrategyNames()));

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-two-chessboard-squares-have-the-same-color.h"

namespace leetcode {
namespace problem_3274 {

class CheckIfTwoChessboardSquaresHaveTheSameColorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CheckIfTwoChessboardSquaresHaveTheSameColorSolution solution_;
};

TEST_P(CheckIfTwoChessboardSquaresHaveTheSameColorTest, Example1) {
  EXPECT_TRUE(solution_.checkTwoChessboards("a1", "c3"));
}

TEST_P(CheckIfTwoChessboardSquaresHaveTheSameColorTest, Example2) {
  EXPECT_FALSE(solution_.checkTwoChessboards("a1", "h3"));
}

TEST_P(CheckIfTwoChessboardSquaresHaveTheSameColorTest, SelfAuthoredSameSquare) {
  EXPECT_TRUE(solution_.checkTwoChessboards("h8", "h8"));
}

TEST_P(CheckIfTwoChessboardSquaresHaveTheSameColorTest, SelfAuthoredAdjacentDifference) {
  EXPECT_FALSE(solution_.checkTwoChessboards("a1", "a2"));
}

TEST_P(CheckIfTwoChessboardSquaresHaveTheSameColorTest, SelfAuthoredSameRowOddEvenCol) {
  EXPECT_FALSE(solution_.checkTwoChessboards("c1", "d1"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfTwoChessboardSquaresHaveTheSameColorTestSuite,
    CheckIfTwoChessboardSquaresHaveTheSameColorTest,
    ::testing::ValuesIn(CheckIfTwoChessboardSquaresHaveTheSameColorSolution()
                            .getStrategyNames()));

}  // namespace problem_3274
}  // namespace leetcode

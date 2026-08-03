#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/determine-color-of-a-chessboard-square.h"

namespace leetcode {
namespace problem_1812 {

class DetermineColorOfAChessboardSquareTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  DetermineColorOfAChessboardSquareSolution solution;
};

TEST_P(DetermineColorOfAChessboardSquareTest, Example1) {
  EXPECT_FALSE(solution.squareIsWhite("a1"));
}

TEST_P(DetermineColorOfAChessboardSquareTest, Example2) {
  EXPECT_TRUE(solution.squareIsWhite("h3"));
}

TEST_P(DetermineColorOfAChessboardSquareTest, Example3) {
  EXPECT_FALSE(solution.squareIsWhite("c7"));
}

INSTANTIATE_TEST_SUITE_P(
    DetermineColorOfAChessboardSquareTestCases,
    DetermineColorOfAChessboardSquareTest,
    ::testing::ValuesIn(
        DetermineColorOfAChessboardSquareSolution().getStrategyNames()));

}  // namespace problem_1812
}  // namespace leetcode

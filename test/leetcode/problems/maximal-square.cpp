#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximal-square.h"

namespace leetcode {
namespace problem_221 {

class MaximalSquareTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximalSquareSolution solution_;
};

TEST_P(MaximalSquareTest, Example1) {
  std::vector<std::vector<char>> matrix = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  EXPECT_EQ(4, solution_.maximalSquare(matrix));
}

TEST_P(MaximalSquareTest, Example2) {
  std::vector<std::vector<char>> matrix = {{'0', '1'}, {'1', '0'}};
  EXPECT_EQ(1, solution_.maximalSquare(matrix));
}

TEST_P(MaximalSquareTest, Example3) {
  std::vector<std::vector<char>> matrix = {{'0'}};
  EXPECT_EQ(0, solution_.maximalSquare(matrix));
}

TEST_P(MaximalSquareTest, SelfAuthoredSingleOne) {
  std::vector<std::vector<char>> matrix = {{'1'}};
  EXPECT_EQ(1, solution_.maximalSquare(matrix));
}

TEST_P(MaximalSquareTest, SelfAuthoredAllOnes) {
  std::vector<std::vector<char>> matrix = {{'1', '1'}, {'1', '1'}};
  EXPECT_EQ(4, solution_.maximalSquare(matrix));
}

TEST_P(MaximalSquareTest, SelfAuthoredSingleRow) {
  std::vector<std::vector<char>> matrix = {{'1', '1', '0', '1', '1', '1'}};
  EXPECT_EQ(1, solution_.maximalSquare(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    MaximalSquareTestSuite, MaximalSquareTest,
    ::testing::ValuesIn(MaximalSquareSolution().getStrategyNames()));

}  // namespace problem_221
}  // namespace leetcode

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/make-a-square-with-the-same-color.h"

namespace leetcode {
namespace problem_3127 {
namespace {

class MakeASquareWithTheSameColorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MakeASquareWithTheSameColorSolution solution;
};

TEST_P(MakeASquareWithTheSameColorTest, Example1) {
  std::vector<std::vector<char>> grid = {
      {'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}};
  EXPECT_TRUE(solution.canMakeSquare(grid));
}

TEST_P(MakeASquareWithTheSameColorTest, Example2) {
  std::vector<std::vector<char>> grid = {
      {'B', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'B'}};
  EXPECT_FALSE(solution.canMakeSquare(grid));
}

TEST_P(MakeASquareWithTheSameColorTest, Example3) {
  std::vector<std::vector<char>> grid = {
      {'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'W'}};
  EXPECT_TRUE(solution.canMakeSquare(grid));
}

INSTANTIATE_TEST_SUITE_P(
    MakeASquareWithTheSameColorTestParam,
    MakeASquareWithTheSameColorTest,
    ::testing::ValuesIn(MakeASquareWithTheSameColorSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3127
}  // namespace leetcode

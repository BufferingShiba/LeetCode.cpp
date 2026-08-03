#include "leetcode/problems/maximum-number-of-moves-in-a-grid.h"

#include <gtest/gtest.h>
#include <string>

namespace leetcode {
namespace problem_2684 {

class MaximumNumberOfMovesInAGridTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumNumberOfMovesInAGridSolution solution_;
};

TEST_P(MaximumNumberOfMovesInAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {2, 4, 3, 5},
      {5, 4, 9, 3},
      {3, 4, 2, 11},
      {10, 9, 13, 15}};
  EXPECT_EQ(solution_.maxMoves(grid), 3);
}

TEST_P(MaximumNumberOfMovesInAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {3, 2, 4},
      {2, 1, 9},
      {1, 1, 7}};
  EXPECT_EQ(solution_.maxMoves(grid), 0);
}

TEST_P(MaximumNumberOfMovesInAGridTest, SelfAuthoredStrictlyIncreasingRow) {
  std::vector<std::vector<int>> grid = {
      {1, 2, 3, 4, 5},
      {9, 9, 9, 9, 9}};
  EXPECT_EQ(solution_.maxMoves(grid), 4);
}

TEST_P(MaximumNumberOfMovesInAGridTest, SelfAuthoredZigzagPath) {
  std::vector<std::vector<int>> grid = {
      {1, 100, 5, 100, 9},
      {2, 3, 4, 5, 6},
      {100, 100, 100, 100, 100}};
  EXPECT_EQ(solution_.maxMoves(grid), 4);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumNumberOfMovesInAGridStrategies,
    MaximumNumberOfMovesInAGridTest,
    ::testing::ValuesIn(
        MaximumNumberOfMovesInAGridSolution().getStrategyNames()));

}  // namespace problem_2684
}  // namespace leetcode

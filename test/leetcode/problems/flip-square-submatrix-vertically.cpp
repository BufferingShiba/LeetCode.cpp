#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/flip-square-submatrix-vertically.h"

namespace leetcode {
namespace problem_3643 {
namespace {

class FlipSquareSubmatrixVerticallyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FlipSquareSubmatrixVerticallySolution solution;
};

TEST_P(FlipSquareSubmatrixVerticallyTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16}};
  std::vector<std::vector<int>> expected = {
      {1, 2, 3, 4},
      {13, 14, 15, 8},
      {9, 10, 11, 12},
      {5, 6, 7, 16}};
  EXPECT_EQ(expected, solution.reverseSubmatrix(grid, 1, 0, 3));
}

TEST_P(FlipSquareSubmatrixVerticallyTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {3, 4, 2, 3},
      {2, 3, 4, 2}};
  std::vector<std::vector<int>> expected = {
      {3, 4, 4, 2},
      {2, 3, 2, 3}};
  EXPECT_EQ(expected, solution.reverseSubmatrix(grid, 0, 2, 2));
}

TEST_P(FlipSquareSubmatrixVerticallyTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> grid = {{42}};
  std::vector<std::vector<int>> expected = {{42}};
  EXPECT_EQ(expected, solution.reverseSubmatrix(grid, 0, 0, 1));
}

INSTANTIATE_TEST_SUITE_P(
    FlipSquareSubmatrixVerticallyTestSuite,
    FlipSquareSubmatrixVerticallyTest,
    ::testing::ValuesIn(FlipSquareSubmatrixVerticallySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3643
}  // namespace leetcode

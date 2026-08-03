#include "leetcode/problems/length-of-longest-v-shaped-diagonal-segment.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

using leetcode::problem_3459::LengthOfLongestVShapedDiagonalSegmentSolution;

namespace {

std::vector<std::vector<int>> MakeGrid(int n, int m,
                                       const std::vector<int>& vals) {
  std::vector<std::vector<int>> g(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) g[i][j] = vals[i * m + j];
  return g;
}

}  // namespace

class LengthOfLongestVShapedDiagonalSegmentTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  LengthOfLongestVShapedDiagonalSegmentSolution solution;
};

TEST_P(LengthOfLongestVShapedDiagonalSegmentTest, Example1) {
  auto grid = MakeGrid(5, 5, {
    2,2,1,2,2,
    2,0,2,2,0,
    2,0,1,1,0,
    1,0,2,2,2,
    2,0,0,2,2});
  EXPECT_EQ(solution.lenOfVDiagonal(grid), 5);
}

TEST_P(LengthOfLongestVShapedDiagonalSegmentTest, Example2) {
  auto grid = MakeGrid(5, 5, {
    2,2,2,2,2,
    2,0,2,2,0,
    2,0,1,1,0,
    1,0,2,2,2,
    2,0,0,2,2});
  EXPECT_EQ(solution.lenOfVDiagonal(grid), 4);
}

TEST_P(LengthOfLongestVShapedDiagonalSegmentTest, Example3) {
  auto grid = MakeGrid(5, 5, {
    1,2,2,2,2,
    2,2,2,2,0,
    2,0,0,0,0,
    0,0,2,2,2,
    2,0,0,2,0});
  EXPECT_EQ(solution.lenOfVDiagonal(grid), 5);
}

TEST_P(LengthOfLongestVShapedDiagonalSegmentTest, Example4) {
  auto grid = MakeGrid(1, 1, {1});
  EXPECT_EQ(solution.lenOfVDiagonal(grid), 1);
}

TEST_P(LengthOfLongestVShapedDiagonalSegmentTest, SelfAuthoredCornerSingle) {
  auto grid = MakeGrid(1, 1, {0});
  EXPECT_EQ(solution.lenOfVDiagonal(grid), 0);
}

INSTANTIATE_TEST_SUITE_P(
    LengthOfLongestVShapedDiagonalSegmentTests,
    LengthOfLongestVShapedDiagonalSegmentTest,
    ::testing::ValuesIn(
        LengthOfLongestVShapedDiagonalSegmentSolution().getStrategyNames()));

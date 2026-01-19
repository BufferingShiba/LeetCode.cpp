#include "leetcode/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_1292 {

class MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest
    : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdSolution solution;
};

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, Example1) {
  vector<vector<int>> mat = {
    {1,1,3,2,4,3,2},
    {1,1,3,2,4,3,2},
    {1,1,3,2,4,3,2}
  };
  int threshold = 4;
  int expected = 2;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, Example2) {
  vector<vector<int>> mat = {
    {2,2,2,2,2},
    {2,2,2,2,2},
    {2,2,2,2,2},
    {2,2,2,2,2},
    {2,2,2,2,2}
  };
  int threshold = 1;
  int expected = 0;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, SingleElementValid) {
  vector<vector<int>> mat = {{5}};
  int threshold = 5;
  int expected = 1;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, SingleElementInvalid) {
  vector<vector<int>> mat = {{5}};
  int threshold = 4;
  int expected = 0;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, AllZeros) {
  vector<vector<int>> mat = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
  };
  int threshold = 0;
  int expected = 3;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, LargeThreshold) {
  vector<vector<int>> mat = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  int threshold = 100;
  int expected = 3;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, SmallThreshold) {
  vector<vector<int>> mat = {
    {10,20,30},
    {40,50,60},
    {70,80,90}
  };
  int threshold = 25;
  int expected = 1;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, RectangularMatrix) {
  vector<vector<int>> mat = {
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
  };
  int threshold = 4;
  int expected = 2;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, EdgeCaseMaxSize) {
  // 创建 300x300 的矩阵，所有元素为 1
  vector<vector<int>> mat(300, vector<int>(300, 1));
  int threshold = 90000;  // 300x300 的正方形和为 90000
  int expected = 300;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

TEST_P(MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest, EdgeCaseThresholdZero) {
  vector<vector<int>> mat = {
    {0,1,0},
    {1,0,1},
    {0,1,0}
  };
  int threshold = 0;
  int expected = 1;
  EXPECT_EQ(expected, solution.maxSideLength(mat, threshold));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode,
    MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdTest,
    ::testing::ValuesIn(
        MaximumSideLengthOfASquareWithSumLessThanOrEqualToThresholdSolution()
            .getStrategyNames()));

}  // namespace problem_1292
}  // namespace leetcode
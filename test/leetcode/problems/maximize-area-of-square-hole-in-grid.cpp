#include "leetcode/problems/maximize-area-of-square-hole-in-grid.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2943 {

class MaximizeAreaOfSquareHoleInGridTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximizeAreaOfSquareHoleInGridSolution solution;
};

TEST_P(MaximizeAreaOfSquareHoleInGridTest, Example1) {
  int n = 2, m = 1;
  vector<int> hBars = {2, 3};
  vector<int> vBars = {2};
  int expected = 4;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, Example2) {
  int n = 1, m = 1;
  vector<int> hBars = {2};
  vector<int> vBars = {2};
  int expected = 4;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, Example3) {
  int n = 2, m = 3;
  vector<int> hBars = {2, 3};
  vector<int> vBars = {2, 4};
  int expected = 4;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, EmptyBars) {
  int n = 5, m = 5;
  vector<int> hBars = {};
  vector<int> vBars = {};
  int expected = 1;  // 最小边长为1，面积为1
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, SingleBar) {
  int n = 3, m = 3;
  vector<int> hBars = {2};
  vector<int> vBars = {3};
  // 水平最长连续长度 = 1，垂直最长连续长度 = 1
  // 边长 = min(1+1, 1+1) = 2，面积 = 4
  int expected = 4;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, ConsecutiveBars) {
  int n = 10, m = 10;
  vector<int> hBars = {2, 3, 4, 5, 6};  // 连续长度 5
  vector<int> vBars = {3, 4, 5};        // 连续长度 3
  // 水平间隔 = 5+1 = 6，垂直间隔 = 3+1 = 4
  // 边长 = min(6, 4) = 4，面积 = 16
  int expected = 16;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, NonConsecutiveBars) {
  int n = 10, m = 10;
  vector<int> hBars = {2, 4, 6, 8};  // 每个单独，最长连续长度 1
  vector<int> vBars = {3, 7};        // 每个单独，最长连续长度 1
  // 边长 = min(1+1, 1+1) = 2，面积 = 4
  int expected = 4;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

TEST_P(MaximizeAreaOfSquareHoleInGridTest, MixedConsecutive) {
  int n = 10, m = 10;
  vector<int> hBars = {2, 3, 5, 6, 7};  // 最长连续：5,6,7 长度 3
  vector<int> vBars = {4, 5, 8, 9};     // 最长连续：8,9 长度 2
  // 水平间隔 = 3+1 = 4，垂直间隔 = 2+1 = 3
  // 边长 = min(4, 3) = 3，面积 = 9
  int expected = 9;
  int result = solution.maximizeSquareHoleArea(n, m, hBars, vBars);
  EXPECT_EQ(expected, result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, MaximizeAreaOfSquareHoleInGridTest,
    ::testing::ValuesIn(MaximizeAreaOfSquareHoleInGridSolution().getStrategyNames()));

}  // namespace problem_2943
}  // namespace leetcode
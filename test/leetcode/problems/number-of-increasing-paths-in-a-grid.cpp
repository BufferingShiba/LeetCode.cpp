#include <gtest/gtest.h>
#include "leetcode/problems/number-of-increasing-paths-in-a-grid.h"

using namespace leetcode::problem_2328;

class NumberOfIncreasingPathsInAGridTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  NumberOfIncreasingPathsInAGridSolution solution_;
};

TEST_P(NumberOfIncreasingPathsInAGridTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 1}, {3, 4}};
  EXPECT_EQ(solution_.countPaths(grid), 8);
}

TEST_P(NumberOfIncreasingPathsInAGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{1}, {2}};
  EXPECT_EQ(solution_.countPaths(grid), 3);
}

TEST_P(NumberOfIncreasingPathsInAGridTest, SingleCell) {
  std::vector<std::vector<int>> grid = {{5}};
  EXPECT_EQ(solution_.countPaths(grid), 1);
}

TEST_P(NumberOfIncreasingPathsInAGridTest, AllEqual) {
  std::vector<std::vector<int>> grid = {{2, 2}, {2, 2}};
  // 没有严格递增邻居，每个格子只能形成长度为1的路径，共4条
  EXPECT_EQ(solution_.countPaths(grid), 4);
}

TEST_P(NumberOfIncreasingPathsInAGridTest, StrictlyDecreasing) {
  std::vector<std::vector<int>> grid = {{5, 4}, {3, 2}};
  // dp: [0][0]=1, [0][1]=2, [1][0]=2, [1][1]=5 → 总和 10
  EXPECT_EQ(solution_.countPaths(grid), 10);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    NumberOfIncreasingPathsInAGridTest,
    testing::ValuesIn(NumberOfIncreasingPathsInAGridSolution().getStrategyNames()));

#include <gtest/gtest.h>

#include "leetcode/problems/spiral-matrix-ii.h"

using namespace leetcode::problem_59;

class SpiralMatrixIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  SpiralMatrixIiSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SpiralMatrixIiTest, Example1) {
  int n = 3;
  auto result = solution.generateMatrix(n);
  std::vector<std::vector<int>> expected = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
  EXPECT_EQ(result, expected);
}

TEST_P(SpiralMatrixIiTest, Example2) {
  int n = 1;
  auto result = solution.generateMatrix(n);
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(result, expected);
}

TEST_P(SpiralMatrixIiTest, SelfAuthoredN2) {
  int n = 2;
  auto result = solution.generateMatrix(n);
  std::vector<std::vector<int>> expected = {{1, 2}, {4, 3}};
  EXPECT_EQ(result, expected);
}

TEST_P(SpiralMatrixIiTest, SelfAuthoredN4) {
  int n = 4;
  auto result = solution.generateMatrix(n);
  std::vector<std::vector<int>> expected = {
      {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, SpiralMatrixIiTest,
                         ::testing::ValuesIn(SpiralMatrixIiSolution()
                                                 .getStrategyNames()));

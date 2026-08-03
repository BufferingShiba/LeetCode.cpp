#include <gtest/gtest.h>
#include "leetcode/problems/row-with-maximum-ones.h"

#include <string>
#include <vector>

using leetcode::problem_2643::RowWithMaximumOnesSolution;

class RowWithMaximumOnesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RowWithMaximumOnesSolution solution;
};

TEST_P(RowWithMaximumOnesTest, Example1) {
  std::vector<std::vector<int>> mat = {{0, 1}, {1, 0}};
  EXPECT_EQ(solution.rowAndMaximumOnes(mat), (std::vector<int>{0, 1}));
}

TEST_P(RowWithMaximumOnesTest, Example2) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 1, 1}};
  EXPECT_EQ(solution.rowAndMaximumOnes(mat), (std::vector<int>{1, 2}));
}

TEST_P(RowWithMaximumOnesTest, Example3) {
  std::vector<std::vector<int>> mat = {{0, 0}, {1, 1}, {0, 0}};
  EXPECT_EQ(solution.rowAndMaximumOnes(mat), (std::vector<int>{1, 2}));
}

TEST_P(RowWithMaximumOnesTest, SelfAuthoredSingleRowSingleColumn) {
  std::vector<std::vector<int>> mat = {{1}};
  EXPECT_EQ(solution.rowAndMaximumOnes(mat), (std::vector<int>{0, 1}));
}

TEST_P(RowWithMaximumOnesTest, SelfAuthoredAllZeros) {
  std::vector<std::vector<int>> mat = {{0, 0}, {0, 0}};
  EXPECT_EQ(solution.rowAndMaximumOnes(mat), (std::vector<int>{0, 0}));
}

INSTANTIATE_TEST_SUITE_P(
    RowWithMaximumOnesTestSuite, RowWithMaximumOnesTest,
    ::testing::ValuesIn(RowWithMaximumOnesSolution().getStrategyNames()));

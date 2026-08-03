#include <gtest/gtest.h>

#include "leetcode/problems/pascals-triangle.h"

#include <string>
#include <vector>

using leetcode::problem_118::PascalsTriangleSolution;

class PascalsTriangleTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PascalsTriangleSolution solution;
};

TEST_P(PascalsTriangleTest, Example1) {
  std::vector<std::vector<int>> expected = {
      {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
  EXPECT_EQ(expected, solution.generate(5));
}

TEST_P(PascalsTriangleTest, Example2) {
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(expected, solution.generate(1));
}

TEST_P(PascalsTriangleTest, SelfAuthoredRowsTwo) {
  std::vector<std::vector<int>> expected = {{1}, {1, 1}};
  EXPECT_EQ(expected, solution.generate(2));
}

TEST_P(PascalsTriangleTest, SelfAuthoredRowsThree) {
  std::vector<std::vector<int>> expected = {
      {1}, {1, 1}, {1, 2, 1}};
  EXPECT_EQ(expected, solution.generate(3));
}

TEST_P(PascalsTriangleTest, SelfAuthoredMaxRows) {
  const std::vector<std::vector<int>> result = solution.generate(30);
  EXPECT_EQ(30, static_cast<int>(result.size()));
  EXPECT_EQ(30, static_cast<int>(result[29].size()));
  EXPECT_EQ(1, result[29][0]);
  EXPECT_EQ(1, result[29][29]);
  // Row n = 30, element at index 15 (C(29, 15)) must equal sum of its
  // two direct parents in the previous row.
  EXPECT_EQ(result[28][14] + result[28][15], result[29][15]);
}

INSTANTIATE_TEST_SUITE_P(
    PascalsTriangle, PascalsTriangleTest,
    ::testing::ValuesIn(PascalsTriangleSolution().getStrategyNames()));

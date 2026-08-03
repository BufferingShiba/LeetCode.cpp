#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/largest-local-values-in-a-matrix.h"

namespace leetcode::problem_2373 {

class LargestLocalValuesInAMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LargestLocalValuesInAMatrixSolution solution;
};

TEST_P(LargestLocalValuesInAMatrixTest, Example1) {
  std::vector<std::vector<int>> grid = {
      {9, 9, 8, 1},
      {5, 6, 2, 6},
      {8, 2, 6, 4},
      {6, 2, 2, 2}};
  std::vector<std::vector<int>> expected = {{9, 9}, {8, 6}};
  EXPECT_EQ(solution.largestLocal(grid), expected);
}

TEST_P(LargestLocalValuesInAMatrixTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 2, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1}};
  std::vector<std::vector<int>> expected = {
      {2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
  EXPECT_EQ(solution.largestLocal(grid), expected);
}

TEST_P(LargestLocalValuesInAMatrixTest, SelfAuthoredMinimumSize) {
  std::vector<std::vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> expected = {{9}};
  EXPECT_EQ(solution.largestLocal(grid), expected);
}

INSTANTIATE_TEST_SUITE_P(
    LargestLocalValuesInAMatrixTestSuite, LargestLocalValuesInAMatrixTest,
    ::testing::ValuesIn(LargestLocalValuesInAMatrixSolution().getStrategyNames()));

}  // namespace leetcode::problem_2373

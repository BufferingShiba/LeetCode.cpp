#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/toeplitz-matrix.h"

namespace leetcode::problem_766 {

class ToeplitzMatrixTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ToeplitzMatrixSolution solution;
};

TEST_P(ToeplitzMatrixTest, Example1) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  EXPECT_TRUE(solution.isToeplitzMatrix(matrix));
}

TEST_P(ToeplitzMatrixTest, Example2) {
  std::vector<std::vector<int>> matrix = {{1, 2}, {2, 2}};
  EXPECT_FALSE(solution.isToeplitzMatrix(matrix));
}

TEST_P(ToeplitzMatrixTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> matrix = {{5}};
  EXPECT_TRUE(solution.isToeplitzMatrix(matrix));
}

TEST_P(ToeplitzMatrixTest, SelfAuthoredSingleRow) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}};
  EXPECT_TRUE(solution.isToeplitzMatrix(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    ToeplitzMatrixTestSuite, ToeplitzMatrixTest,
    ::testing::ValuesIn(ToeplitzMatrixSolution().getStrategyNames()));

}  // namespace leetcode::problem_766

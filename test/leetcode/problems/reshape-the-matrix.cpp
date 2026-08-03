#include <gtest/gtest.h>

#include "leetcode/problems/reshape-the-matrix.h"

namespace leetcode::problem_566 {

class ReshapeTheMatrixTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ReshapeTheMatrixSolution solution;
};

TEST_P(ReshapeTheMatrixTest, Example1) {
  std::vector<std::vector<int>> mat = {{1, 2}, {3, 4}};
  int r = 1, c = 4;
  std::vector<std::vector<int>> expected = {{1, 2, 3, 4}};
  EXPECT_EQ(solution.matrixReshape(mat, r, c), expected);
}

TEST_P(ReshapeTheMatrixTest, Example2) {
  std::vector<std::vector<int>> mat = {{1, 2}, {3, 4}};
  int r = 2, c = 4;
  std::vector<std::vector<int>> expected = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution.matrixReshape(mat, r, c), expected);
}

TEST_P(ReshapeTheMatrixTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> mat = {{7}};
  int r = 1, c = 1;
  std::vector<std::vector<int>> expected = {{7}};
  EXPECT_EQ(solution.matrixReshape(mat, r, c), expected);
}

TEST_P(ReshapeTheMatrixTest, SelfAuthoredColumnToRow) {
  std::vector<std::vector<int>> mat = {{1}, {2}, {3}, {4}};
  int r = 1, c = 4;
  std::vector<std::vector<int>> expected = {{1, 2, 3, 4}};
  EXPECT_EQ(solution.matrixReshape(mat, r, c), expected);
}

INSTANTIATE_TEST_SUITE_P(All, ReshapeTheMatrixTest,
                         ::testing::ValuesIn(ReshapeTheMatrixSolution().getStrategyNames()));

}  // namespace leetcode::problem_566

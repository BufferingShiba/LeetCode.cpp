#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/sum-of-matrix-after-queries.h"

namespace leetcode::problem_2718 {

class SumOfMatrixAfterQueriesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SumOfMatrixAfterQueriesSolution solution_;
};

TEST_P(SumOfMatrixAfterQueriesTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> queries = {
      {0, 0, 1}, {1, 2, 2}, {0, 2, 3}, {1, 0, 4}};
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 23);
}

TEST_P(SumOfMatrixAfterQueriesTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> queries = {
      {0, 0, 4}, {0, 1, 2}, {1, 0, 1}, {0, 2, 3}, {1, 2, 1}};
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 17);
}

TEST_P(SumOfMatrixAfterQueriesTest, SelfAuthoredSingleRow) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0, 5}};
  // Row 0 set to 5: matrix = [[5,5],[0,0]], sum = 10
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 10);
}

TEST_P(SumOfMatrixAfterQueriesTest, SelfAuthoredSingleCol) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{1, 1, 3}};
  // Col 1 set to 3: matrix = [[0,3],[0,3]], sum = 6
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 6);
}

TEST_P(SumOfMatrixAfterQueriesTest, SelfAuthoredOverwriteRow) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0, 1}, {0, 0, 5}};
  // After first: [[1,1],[0,0]]; after second: [[5,5],[0,0]], sum = 10
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 10);
}

TEST_P(SumOfMatrixAfterQueriesTest, SelfAuthoredRowThenColOverlap) {
  int n = 2;
  std::vector<std::vector<int>> queries = {{0, 0, 3}, {1, 1, 7}};
  // Row 0 → 3: [[3,3],[0,0]]; Col 1 → 7: [[3,7],[0,7]]; sum = 3+7+0+7 = 17
  EXPECT_EQ(solution_.matrixSumQueries(n, queries), 17);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SumOfMatrixAfterQueriesTest,
    testing::ValuesIn(
        SumOfMatrixAfterQueriesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2718

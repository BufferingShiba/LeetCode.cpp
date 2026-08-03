#include <gtest/gtest.h>

#include "leetcode/problems/reconstruct-a-2-row-binary-matrix.h"

namespace leetcode::problem_1253 {

class ReconstructA2RowBinaryMatrixTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ReconstructA2RowBinaryMatrixSolution solution_;
};

TEST_P(ReconstructA2RowBinaryMatrixTest, Example1) {
  int upper = 2, lower = 1;
  std::vector<int> colsum = {1, 1, 1};
  auto result = solution_.reconstructMatrix(upper, lower, colsum);

  // Must not be empty
  ASSERT_FALSE(result.empty());
  ASSERT_EQ(result.size(), 2u);
  ASSERT_EQ(result[0].size(), colsum.size());
  ASSERT_EQ(result[1].size(), colsum.size());

  // Verify row sums
  int sum0 = 0, sum1 = 0;
  for (size_t i = 0; i < colsum.size(); ++i) {
    sum0 += result[0][i];
    sum1 += result[1][i];
    EXPECT_EQ(result[0][i] + result[1][i], colsum[i]);
  }
  EXPECT_EQ(sum0, upper);
  EXPECT_EQ(sum1, lower);
}

TEST_P(ReconstructA2RowBinaryMatrixTest, Example2) {
  int upper = 2, lower = 3;
  std::vector<int> colsum = {2, 2, 1, 1};
  auto result = solution_.reconstructMatrix(upper, lower, colsum);
  EXPECT_TRUE(result.empty());
}

TEST_P(ReconstructA2RowBinaryMatrixTest, Example3) {
  int upper = 5, lower = 5;
  std::vector<int> colsum = {2, 1, 2, 0, 1, 0, 1, 2, 0, 1};
  auto result = solution_.reconstructMatrix(upper, lower, colsum);

  ASSERT_FALSE(result.empty());
  ASSERT_EQ(result.size(), 2u);
  ASSERT_EQ(result[0].size(), colsum.size());
  ASSERT_EQ(result[1].size(), colsum.size());

  int sum0 = 0, sum1 = 0;
  for (size_t i = 0; i < colsum.size(); ++i) {
    sum0 += result[0][i];
    sum1 += result[1][i];
    EXPECT_EQ(result[0][i] + result[1][i], colsum[i]);
  }
  EXPECT_EQ(sum0, upper);
  EXPECT_EQ(sum1, lower);
}

INSTANTIATE_TEST_SUITE_P(Strategies, ReconstructA2RowBinaryMatrixTest,
                         testing::ValuesIn(ReconstructA2RowBinaryMatrixSolution()
                                               .getStrategyNames()));

}  // namespace leetcode::problem_1253

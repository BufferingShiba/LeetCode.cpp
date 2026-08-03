#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-valid-matrix-given-row-and-column-sums.h"

namespace leetcode {
namespace problem_1605 {

namespace {

bool isValid(const std::vector<std::vector<int>>& matrix,
             const std::vector<int>& rowSum,
             const std::vector<int>& colSum) {
  const int m = static_cast<int>(matrix.size());
  const int n = static_cast<int>(matrix[0].size());
  for (int i = 0; i < m; ++i) {
    long long sum = 0;
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] < 0) return false;
      sum += matrix[i][j];
    }
    if (sum != rowSum[i]) return false;
  }
  for (int j = 0; j < n; ++j) {
    long long sum = 0;
    for (int i = 0; i < m; ++i) sum += matrix[i][j];
    if (sum != colSum[j]) return false;
  }
  return true;
}

}  // namespace

class FindValidMatrixGivenRowAndColumnSumsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindValidMatrixGivenRowAndColumnSumsSolution solution;
};

TEST_P(FindValidMatrixGivenRowAndColumnSumsTest, Example1) {
  std::vector<int> rowSum{3, 8};
  std::vector<int> colSum{4, 7};
  auto result = solution.restoreMatrix(rowSum, colSum);
  EXPECT_TRUE(isValid(result, std::vector<int>{3, 8},
                      std::vector<int>{4, 7}));
}

TEST_P(FindValidMatrixGivenRowAndColumnSumsTest, Example2) {
  std::vector<int> rowSum{5, 7, 10};
  std::vector<int> colSum{8, 6, 8};
  auto result = solution.restoreMatrix(rowSum, colSum);
  EXPECT_TRUE(isValid(result, std::vector<int>{5, 7, 10},
                      std::vector<int>{8, 6, 8}));
}

TEST_P(FindValidMatrixGivenRowAndColumnSumsTest, SelfAuthoredSingleElement) {
  std::vector<int> rowSum{5};
  std::vector<int> colSum{5};
  auto result = solution.restoreMatrix(rowSum, colSum);
  EXPECT_TRUE(isValid(result, std::vector<int>{5}, std::vector<int>{5}));
}

TEST_P(FindValidMatrixGivenRowAndColumnSumsTest, SelfAuthoredZeroElements) {
  std::vector<int> rowSum{0, 4};
  std::vector<int> colSum{2, 2, 0};
  auto result = solution.restoreMatrix(rowSum, colSum);
  EXPECT_TRUE(isValid(result, std::vector<int>{0, 4},
                      std::vector<int>{2, 2, 0}));
}

INSTANTIATE_TEST_SUITE_P(
    FindValidMatrixGivenRowAndColumnSums, FindValidMatrixGivenRowAndColumnSumsTest,
    testing::ValuesIn(
        FindValidMatrixGivenRowAndColumnSumsSolution().getStrategyNames()));

}  // namespace problem_1605
}  // namespace leetcode

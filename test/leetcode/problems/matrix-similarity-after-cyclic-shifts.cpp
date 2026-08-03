#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/matrix-similarity-after-cyclic-shifts.h"

namespace leetcode::problem_2946 {

class MatrixSimilarityAfterCyclicShiftsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MatrixSimilarityAfterCyclicShiftsSolution solution_;
};

TEST_P(MatrixSimilarityAfterCyclicShiftsTest, Example1) {
  std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_FALSE(solution_.areSimilar(mat, 4));
}

TEST_P(MatrixSimilarityAfterCyclicShiftsTest, Example2) {
  std::vector<std::vector<int>> mat = {{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}};
  EXPECT_TRUE(solution_.areSimilar(mat, 2));
}

TEST_P(MatrixSimilarityAfterCyclicShiftsTest, Example3) {
  std::vector<std::vector<int>> mat = {{2, 2}, {2, 2}};
  EXPECT_TRUE(solution_.areSimilar(mat, 3));
}

TEST_P(MatrixSimilarityAfterCyclicShiftsTest, SelfAuthoredAllEqualShiftsToSame) {
  std::vector<std::vector<int>> mat = {{5}};
  EXPECT_TRUE(solution_.areSimilar(mat, 7));
}

INSTANTIATE_TEST_SUITE_P(
    MatrixSimilarityAfterCyclicShiftsTestSuite,
    MatrixSimilarityAfterCyclicShiftsTest,
    ::testing::ValuesIn(
        MatrixSimilarityAfterCyclicShiftsSolution().getStrategyNames()));

}  // namespace leetcode::problem_2946

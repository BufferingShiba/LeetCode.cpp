#include "leetcode/problems/the-k-weakest-rows-in-a-matrix.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1337 {

class TheKWeakestRowsInAMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  TheKWeakestRowsInAMatrixSolution solution_;
};

TEST_P(TheKWeakestRowsInAMatrixTest, Example1) {
  std::vector<std::vector<int>> mat = {
      {1, 1, 0, 0, 0},
      {1, 1, 1, 1, 0},
      {1, 0, 0, 0, 0},
      {1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1}};
  std::vector<int> expected = {2, 0, 3};
  EXPECT_EQ(solution_.kWeakestRows(mat, 3), expected);
}

TEST_P(TheKWeakestRowsInAMatrixTest, Example2) {
  std::vector<std::vector<int>> mat = {
      {1, 0, 0, 0},
      {1, 1, 1, 1},
      {1, 0, 0, 0},
      {1, 0, 0, 0}};
  std::vector<int> expected = {0, 2};
  EXPECT_EQ(solution_.kWeakestRows(mat, 2), expected);
}

TEST_P(TheKWeakestRowsInAMatrixTest, SelfAuthoredKEqualsM) {
  std::vector<std::vector<int>> mat = {
      {1, 1},
      {1, 0},
      {0, 0}};
  std::vector<int> expected = {2, 1, 0};
  EXPECT_EQ(solution_.kWeakestRows(mat, 3), expected);
}

INSTANTIATE_TEST_SUITE_P(
    TheKWeakestRowsInAMatrixTests, TheKWeakestRowsInAMatrixTest,
    ::testing::ValuesIn(
        TheKWeakestRowsInAMatrixSolution().getStrategyNames()));

}  // namespace problem_1337
}  // namespace leetcode

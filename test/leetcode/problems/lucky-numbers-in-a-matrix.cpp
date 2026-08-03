#include "leetcode/problems/lucky-numbers-in-a-matrix.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1380 {

class LuckyNumbersInAMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  LuckyNumbersInAMatrixSolution solution_;
};

TEST_P(LuckyNumbersInAMatrixTest, Example1) {
  std::vector<std::vector<int>> matrix = {
      {3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
  std::vector<int> expected = {15};
  EXPECT_EQ(expected, solution_.luckyNumbers(matrix));
}

TEST_P(LuckyNumbersInAMatrixTest, Example2) {
  std::vector<std::vector<int>> matrix = {
      {1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
  std::vector<int> expected = {12};
  EXPECT_EQ(expected, solution_.luckyNumbers(matrix));
}

TEST_P(LuckyNumbersInAMatrixTest, Example3) {
  std::vector<std::vector<int>> matrix = {{7, 8}, {1, 2}};
  std::vector<int> expected = {7};
  EXPECT_EQ(expected, solution_.luckyNumbers(matrix));
}

TEST_P(LuckyNumbersInAMatrixTest, SelfAuthoredSingleElement) {
  std::vector<std::vector<int>> matrix = {{42}};
  std::vector<int> expected = {42};
  EXPECT_EQ(expected, solution_.luckyNumbers(matrix));
}

TEST_P(LuckyNumbersInAMatrixTest, SelfAuthoredRowMinNotColMax) {
  std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
  std::vector<int> expected = {3};
  EXPECT_EQ(expected, solution_.luckyNumbers(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    LuckyNumbersInAMatrixTestCases, LuckyNumbersInAMatrixTest,
    ::testing::ValuesIn(LuckyNumbersInAMatrixSolution().getStrategyNames()));

}  // namespace problem_1380
}  // namespace leetcode

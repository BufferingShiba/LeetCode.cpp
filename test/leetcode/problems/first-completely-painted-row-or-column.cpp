#include "leetcode/problems/first-completely-painted-row-or-column.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2661 {

namespace {

std::vector<std::vector<int>> buildMat(std::vector<std::vector<int>> mat) {
  return mat;
}

}  // namespace

class FirstCompletelyPaintedRowOrColumnTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FirstCompletelyPaintedRowOrColumnSolution solution;
};

TEST_P(FirstCompletelyPaintedRowOrColumnTest, Example1) {
  std::vector<int> arr = {1, 3, 4, 2};
  std::vector<std::vector<int>> mat = {{1, 4}, {2, 3}};
  EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 2);
}

TEST_P(FirstCompletelyPaintedRowOrColumnTest, Example2) {
  std::vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
  std::vector<std::vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
  EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 3);
}

TEST_P(FirstCompletelyPaintedRowOrColumnTest, SingleCell) {
  std::vector<int> arr = {1};
  std::vector<std::vector<int>> mat = {{1}};
  EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 0);
}

TEST_P(FirstCompletelyPaintedRowOrColumnTest, SingleRow) {
  // 1 x 3 matrix. First painted cell fills the only column (m == 1).
  std::vector<int> arr = {2, 1, 3};
  std::vector<std::vector<int>> mat = {{2, 1, 3}};
  EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 0);
}

TEST_P(FirstCompletelyPaintedRowOrColumnTest, SingleColumn) {
  // 3 x 1 matrix. First painted cell fills the only row (n == 1).
  std::vector<int> arr = {2, 1, 3};
  std::vector<std::vector<int>> mat = {{2}, {1}, {3}};
  EXPECT_EQ(solution.firstCompleteIndex(arr, mat), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FirstCompletelyPaintedRowOrColumnTests,
    FirstCompletelyPaintedRowOrColumnTest,
    ::testing::ValuesIn(
        FirstCompletelyPaintedRowOrColumnSolution().getStrategyNames()));

}  // namespace problem_2661
}  // namespace leetcode

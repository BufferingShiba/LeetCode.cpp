#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/modify-the-matrix.h"

namespace leetcode {
namespace problem_3033 {

class ModifyTheMatrixTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ModifyTheMatrixSolution solution_;
};

TEST_P(ModifyTheMatrixTest, Example1) {
  std::vector<std::vector<int>> matrix = {{1, 2, -1}, {4, -1, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> expected = {{1, 2, 9}, {4, 8, 6}, {7, 8, 9}};
  EXPECT_EQ(expected, solution_.modifiedMatrix(matrix));
}

TEST_P(ModifyTheMatrixTest, Example2) {
  std::vector<std::vector<int>> matrix = {{3, -1}, {5, 2}};
  std::vector<std::vector<int>> expected = {{3, 2}, {5, 2}};
  EXPECT_EQ(expected, solution_.modifiedMatrix(matrix));
}

TEST_P(ModifyTheMatrixTest, SelfAuthoredSingleColumnMultipleRows) {
  std::vector<std::vector<int>> matrix = {{-1}, {10}, {4}};
  std::vector<std::vector<int>> expected = {{10}, {10}, {4}};
  EXPECT_EQ(expected, solution_.modifiedMatrix(matrix));
}

INSTANTIATE_TEST_SUITE_P(
    ModifyTheMatrixTestSuite, ModifyTheMatrixTest,
    ::testing::ValuesIn(ModifyTheMatrixSolution().getStrategyNames()));

}  // namespace problem_3033
}  // namespace leetcode

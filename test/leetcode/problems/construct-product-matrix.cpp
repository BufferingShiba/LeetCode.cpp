#include "leetcode/problems/construct-product-matrix.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2906 {

class ConstructProductMatrixTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructProductMatrixSolution solution_;
};

TEST_P(ConstructProductMatrixTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  std::vector<std::vector<int>> expected = {{24, 12}, {8, 6}};
  EXPECT_EQ(solution_.constructProductMatrix(grid), expected);
}

TEST_P(ConstructProductMatrixTest, Example2) {
  std::vector<std::vector<int>> grid = {{12345}, {2}, {1}};
  std::vector<std::vector<int>> expected = {{2}, {0}, {0}};
  EXPECT_EQ(solution_.constructProductMatrix(grid), expected);
}

TEST_P(ConstructProductMatrixTest, SelfAuthoredSingleElement) {
  // 单个元素：除自身外没有元素，乘积为空乘积 = 1
  std::vector<std::vector<int>> grid = {{7}};
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(solution_.constructProductMatrix(grid), expected);
}

TEST_P(ConstructProductMatrixTest, SelfAuthoredAllOnes) {
  std::vector<std::vector<int>> grid = {{1, 1}, {1, 1}};
  std::vector<std::vector<int>> expected = {{1, 1}, {1, 1}};
  EXPECT_EQ(solution_.constructProductMatrix(grid), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ConstructProductMatrixTests, ConstructProductMatrixTest,
    ::testing::ValuesIn(ConstructProductMatrixSolution().getStrategyNames()));

}  // namespace problem_2906
}  // namespace leetcode

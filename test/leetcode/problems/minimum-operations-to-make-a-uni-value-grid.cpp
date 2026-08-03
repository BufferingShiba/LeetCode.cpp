#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/minimum-operations-to-make-a-uni-value-grid.h"

namespace leetcode::problem_2033 {

class MinimumOperationsToMakeAUniValueGridTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMakeAUniValueGridSolution solution_;
};

TEST_P(MinimumOperationsToMakeAUniValueGridTest, Example1) {
  std::vector<std::vector<int>> grid = {{2, 4}, {6, 8}};
  int x = 2;
  EXPECT_EQ(solution_.minOperations(grid, x), 4);
}

TEST_P(MinimumOperationsToMakeAUniValueGridTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 5}, {2, 3}};
  int x = 1;
  EXPECT_EQ(solution_.minOperations(grid, x), 5);
}

TEST_P(MinimumOperationsToMakeAUniValueGridTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  int x = 2;
  EXPECT_EQ(solution_.minOperations(grid, x), -1);
}

INSTANTIATE_TEST_SUITE_P(
    ,
    MinimumOperationsToMakeAUniValueGridTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeAUniValueGridSolution().getStrategyNames()));

}  // namespace leetcode::problem_2033

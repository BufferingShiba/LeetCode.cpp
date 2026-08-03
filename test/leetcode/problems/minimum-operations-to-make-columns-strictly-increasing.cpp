#include <gtest/gtest.h>

#include "leetcode/problems/minimum-operations-to-make-columns-strictly-increasing.h"

namespace leetcode::problem_3402 {

class MinimumOperationsToMakeColumnsStrictlyIncreasingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumOperationsToMakeColumnsStrictlyIncreasingSolution solution_;
};

TEST_P(MinimumOperationsToMakeColumnsStrictlyIncreasingTest,
       Example1) {
  std::vector<std::vector<int>> grid = {{3, 2}, {1, 3}, {3, 4}, {0, 1}};
  EXPECT_EQ(15, solution_.minimumOperations(grid));
}

TEST_P(MinimumOperationsToMakeColumnsStrictlyIncreasingTest,
       Example2) {
  std::vector<std::vector<int>> grid = {{3, 2, 1}, {2, 1, 0}, {1, 2, 3}};
  EXPECT_EQ(12, solution_.minimumOperations(grid));
}

TEST_P(MinimumOperationsToMakeColumnsStrictlyIncreasingTest, SelfAuthoredSingleRow) {
  std::vector<std::vector<int>> grid = {{5, 0, 42}};
  EXPECT_EQ(0, solution_.minimumOperations(grid));
}

TEST_P(MinimumOperationsToMakeColumnsStrictlyIncreasingTest,
       SelfAuthoredAlreadyStrictlyIncreasingColumns) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  EXPECT_EQ(0, solution_.minimumOperations(grid));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumOperationsToMakeColumnsStrictlyIncreasingTestSuite,
    MinimumOperationsToMakeColumnsStrictlyIncreasingTest,
    ::testing::ValuesIn(
        MinimumOperationsToMakeColumnsStrictlyIncreasingSolution().getStrategyNames()));

}  // namespace leetcode::problem_3402

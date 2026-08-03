#include <gtest/gtest.h>

#include "leetcode/problems/maximum-score-after-applying-operations-on-a-tree.h"

namespace leetcode::problem_2925 {

class MaximumScoreAfterApplyingOperationsOnATreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumScoreAfterApplyingOperationsOnATreeSolution solution_;
};

TEST_P(MaximumScoreAfterApplyingOperationsOnATreeTest, Example1) {
  std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {4, 5}};
  std::vector<int> values = {5, 2, 5, 2, 1, 1};
  EXPECT_EQ(solution_.maximumScoreAfterOperations(edges, values), 11);
}

TEST_P(MaximumScoreAfterApplyingOperationsOnATreeTest, Example2) {
  std::vector<std::vector<int>> edges = {
      {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  std::vector<int> values = {20, 10, 9, 7, 4, 3, 5};
  EXPECT_EQ(solution_.maximumScoreAfterOperations(edges, values), 40);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumScoreAfterApplyingOperationsOnATreeTest,
    testing::ValuesIn(
        MaximumScoreAfterApplyingOperationsOnATreeSolution().getStrategyNames()));

}  // namespace leetcode::problem_2925

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/path-sum.h"
#include "leetcode/utils/tree.h"

using leetcode::constructTree;
using leetcode::problem_112::PathSumSolution;

class PathSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PathSumSolution solution_;
};

TEST_P(PathSumTest, Example1) {
  auto* root =
      constructTree(std::vector<std::optional<int>>{5, 4, 8, 11, std::nullopt, 13,
                                                     4, 7, 2, std::nullopt, std::nullopt,
                                                     std::nullopt, 1});
  EXPECT_TRUE(solution_.hasPathSum(root, 22));
}

TEST_P(PathSumTest, Example2) {
  auto* root = constructTree(std::vector<std::optional<int>>{1, 2, 3});
  EXPECT_FALSE(solution_.hasPathSum(root, 5));
}

TEST_P(PathSumTest, Example3_EmptyTree) {
  EXPECT_FALSE(solution_.hasPathSum(nullptr, 0));
}

INSTANTIATE_TEST_SUITE_P(PathSumTestCases, PathSumTest,
                         ::testing::ValuesIn(PathSumSolution().getStrategyNames()));

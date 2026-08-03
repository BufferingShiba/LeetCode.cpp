#include <gtest/gtest.h>
#include "leetcode/problems/minimum-depth-of-binary-tree.h"

using namespace leetcode::problem_111;
using namespace leetcode;

class MinimumDepthOfBinaryTreeTest
    : public testing::TestWithParam<std::string> {
 protected:
  MinimumDepthOfBinaryTreeSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumDepthOfBinaryTreeTest, Example1) {
  auto* root = constructTree(std::vector<std::optional<int>>{
      3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  EXPECT_EQ(solution.minDepth(root), 2);
  delete root;
}

TEST_P(MinimumDepthOfBinaryTreeTest, Example2) {
  auto* root = constructTree(std::vector<std::optional<int>>{
      2, std::nullopt, 3, std::nullopt, 4, std::nullopt, 5, std::nullopt,
      6});
  EXPECT_EQ(solution.minDepth(root), 5);
  delete root;
}

TEST_P(MinimumDepthOfBinaryTreeTest, SelfAuthoredEmptyTree) {
  EXPECT_EQ(solution.minDepth(nullptr), 0);
}

TEST_P(MinimumDepthOfBinaryTreeTest, SelfAuthoredSingleNode) {
  auto* root = constructTree(std::vector<std::optional<int>>{1});
  EXPECT_EQ(solution.minDepth(root), 1);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies, MinimumDepthOfBinaryTreeTest,
    testing::ValuesIn(MinimumDepthOfBinaryTreeSolution().getStrategyNames()));

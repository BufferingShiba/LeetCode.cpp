#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-depth-of-binary-tree.h"

namespace leetcode {
namespace problem_104 {
namespace {

TreeNode* buildTree(std::vector<std::optional<int>> vals) {
  return constructTree(vals);
}

}  // namespace

class MaximumDepthOfBinaryTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumDepthOfBinaryTreeSolution solution;
};

TEST_P(MaximumDepthOfBinaryTreeTest, Example1) {
  TreeNode* root = buildTree(
      std::vector<std::optional<int>>{3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  EXPECT_EQ(3, solution.maxDepth(root));
}

TEST_P(MaximumDepthOfBinaryTreeTest, Example2) {
  TreeNode* root = buildTree(
      std::vector<std::optional<int>>{1, std::nullopt, 2});
  EXPECT_EQ(2, solution.maxDepth(root));
}

TEST_P(MaximumDepthOfBinaryTreeTest, SelfAuthoredEmptyTree) {
  EXPECT_EQ(0, solution.maxDepth(nullptr));
}

TEST_P(MaximumDepthOfBinaryTreeTest, SelfAuthoredSingleNode) {
  TreeNode* root = buildTree(std::vector<std::optional<int>>{5});
  EXPECT_EQ(1, solution.maxDepth(root));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumDepthOfBinaryTreeTestSuite, MaximumDepthOfBinaryTreeTest,
    ::testing::ValuesIn(MaximumDepthOfBinaryTreeSolution().getStrategyNames()));

}  // namespace problem_104
}  // namespace leetcode

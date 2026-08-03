#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/binary-tree-inorder-traversal.h"

namespace leetcode {
namespace problem_94 {

class BinaryTreeInorderTraversalTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryTreeInorderTraversalSolution solution;
};

TEST_P(BinaryTreeInorderTraversalTest, Example1) {
  TreeNode* root = constructTree(std::vector<std::optional<int>>{1, std::nullopt, 2, 3});
  std::vector<int> expected = {1, 3, 2};
  EXPECT_EQ(solution.inorderTraversal(root), expected);
}

TEST_P(BinaryTreeInorderTraversalTest, Example2) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, 3, 4, 5, std::nullopt, 8, std::nullopt,
                                      std::nullopt, 6, 7, 9});
  std::vector<int> expected = {4, 2, 6, 5, 7, 1, 3, 9, 8};
  EXPECT_EQ(solution.inorderTraversal(root), expected);
}

TEST_P(BinaryTreeInorderTraversalTest, EmptyTree) {
  std::vector<int> expected = {};
  EXPECT_EQ(solution.inorderTraversal(nullptr), expected);
}

TEST_P(BinaryTreeInorderTraversalTest, SingleNode) {
  TreeNode* root = constructTree(std::vector<int>{1});
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.inorderTraversal(root), expected);
}

TEST_P(BinaryTreeInorderTraversalTest, SelfAuthoredLeftSkewed) {
  TreeNode* root = constructTree(
      std::vector<std::optional<int>>{1, 2, std::nullopt, 3});
  std::vector<int> expected = {3, 2, 1};
  EXPECT_EQ(solution.inorderTraversal(root), expected);
}

INSTANTIATE_TEST_SUITE_P(
    BinaryTreeInorderTraversalTestSuite, BinaryTreeInorderTraversalTest,
    ::testing::ValuesIn(BinaryTreeInorderTraversalSolution().getStrategyNames()));

}  // namespace problem_94
}  // namespace leetcode

#include <gtest/gtest.h>

#include "leetcode/problems/recover-binary-search-tree.h"

#include <vector>

namespace leetcode {
namespace problem_99 {

class RecoverBinarySearchTreeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RecoverBinarySearchTreeSolution solution;
};

TEST_P(RecoverBinarySearchTreeTest, Example1) {
  TreeNode* root = constructTree(std::vector<int>{1, 3, -1, -1, 2});
  solution.recoverTree(root);
  EXPECT_TRUE(isBST(root));
  EXPECT_EQ(inorderTraversal(root), std::vector<int>({1, 2, 3}));
}

TEST_P(RecoverBinarySearchTreeTest, Example2) {
  TreeNode* root = constructTree(std::vector<int>{3, 1, 4, -1, -1, 2});
  solution.recoverTree(root);
  EXPECT_TRUE(isBST(root));
  EXPECT_EQ(inorderTraversal(root), std::vector<int>({1, 2, 3, 4}));
}

TEST_P(RecoverBinarySearchTreeTest, AdjacentSwap_RightSkewed) {
  // Valid BST root=1,right=2,right=3 (inorder 1,2,3). Swap 1 and 2 to get
  // [2,-1,1,-1,3]: inorder = 2,1,3 (single inversion).
  TreeNode* root = constructTree(std::vector<int>{2, -1, 1, -1, 3});
  solution.recoverTree(root);
  EXPECT_TRUE(isBST(root));
  EXPECT_EQ(inorderTraversal(root), std::vector<int>({1, 2, 3}));
}

TEST_P(RecoverBinarySearchTreeTest, NonAdjacentSwap_Chain) {
  // Right-skewed chain: valid BST 1-2-3, with inorder 1,2,3.
  // Swap 1 and 3 -> [3,-1,2,-1,1]: inorder = 3,2,1 (two inversions).
  TreeNode* root = constructTree(std::vector<int>{3, -1, 2, -1, 1});
  solution.recoverTree(root);
  EXPECT_TRUE(isBST(root));
  EXPECT_EQ(inorderTraversal(root), std::vector<int>({1, 2, 3}));
}

TEST_P(RecoverBinarySearchTreeTest, SwapRootAndLeaf) {
  // Valid BST root=2,left=1,right=3 (inorder 1,2,3). Swap 2 and 3 to get
  // [3,1,2]: inorder = 1,3,2 (single inversion).
  TreeNode* root = constructTree(std::vector<int>{3, 1, 2});
  solution.recoverTree(root);
  EXPECT_TRUE(isBST(root));
  EXPECT_EQ(inorderTraversal(root), std::vector<int>({1, 2, 3}));
}

INSTANTIATE_TEST_SUITE_P(
    RecoverBinarySearchTreeTestSuite, RecoverBinarySearchTreeTest,
    ::testing::ValuesIn(RecoverBinarySearchTreeSolution().getStrategyNames()));

}  // namespace problem_99
}  // namespace leetcode

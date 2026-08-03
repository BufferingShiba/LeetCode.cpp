#include "leetcode/problems/all-possible-full-binary-trees.h"

#include <gtest/gtest.h>

namespace leetcode::problem_894 {

namespace {

//! A node is a leaf iff it has no children. In a full binary tree every node
//! has exactly 0 or 2 children.
bool isFull(TreeNode* root) {
  if (root == nullptr) return true;
  bool hasLeft = root->left != nullptr;
  bool hasRight = root->right != nullptr;
  if (hasLeft != hasRight) return false;
  return isFull(root->left) && isFull(root->right);
}

//! Count nodes in the tree.
int countNodes(TreeNode* root) {
  if (root == nullptr) return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

}  // namespace

class AllPossibleFullBinaryTreesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AllPossibleFullBinaryTreesSolution solution;
};

TEST_P(AllPossibleFullBinaryTreesTest, SingleNode) {
  auto trees = solution.allPossibleFBT(1);
  ASSERT_EQ(trees.size(), 1u);
  EXPECT_EQ(countNodes(trees[0]), 1);
  EXPECT_TRUE(isFull(trees[0]));
  for (TreeNode* t : trees) delete t;
}

TEST_P(AllPossibleFullBinaryTreesTest, ThreeNodes) {
  auto trees = solution.allPossibleFBT(3);
  ASSERT_EQ(trees.size(), 1u);
  EXPECT_EQ(countNodes(trees[0]), 3);
  EXPECT_TRUE(isFull(trees[0]));
  for (TreeNode* t : trees) delete t;
}

TEST_P(AllPossibleFullBinaryTreesTest, SelfAuthoredEvenNodeCountIsEmpty) {
  auto trees2 = solution.allPossibleFBT(2);
  EXPECT_TRUE(trees2.empty());
  auto trees4 = solution.allPossibleFBT(4);
  EXPECT_TRUE(trees4.empty());
}

TEST_P(AllPossibleFullBinaryTreesTest, SelfAuthoredSevenNodes) {
  auto trees = solution.allPossibleFBT(7);
  // The known number of full binary trees with 7 nodes is 5.
  ASSERT_EQ(trees.size(), 5u);
  for (TreeNode* t : trees) {
    EXPECT_EQ(countNodes(t), 7);
    EXPECT_TRUE(isFull(t));
  }
  for (TreeNode* t : trees) delete t;
}

TEST_P(AllPossibleFullBinaryTreesTest, SelfAuthoredNineNodesCount) {
  auto trees = solution.allPossibleFBT(9);
  // Catalan numbers: C(4) = 14 full binary trees with 9 nodes.
  ASSERT_EQ(trees.size(), 14u);
  for (TreeNode* t : trees) {
    EXPECT_EQ(countNodes(t), 9);
    EXPECT_TRUE(isFull(t));
  }
  for (TreeNode* t : trees) delete t;
}

INSTANTIATE_TEST_SUITE_P(
    AllPossibleFullBinaryTreesStrategies, AllPossibleFullBinaryTreesTest,
    ::testing::ValuesIn(AllPossibleFullBinaryTreesSolution().getStrategyNames()));

}  // namespace leetcode::problem_894

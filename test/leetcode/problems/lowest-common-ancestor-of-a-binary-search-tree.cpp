#include <gtest/gtest.h>

#include "leetcode/problems/lowest-common-ancestor-of-a-binary-search-tree.h"

namespace leetcode::problem_235 {

// Helper: find a node by value in a BST (all values are unique).
static TreeNode* findNode(TreeNode* root, int val) {
  while (root != nullptr) {
    if (val == root->val) return root;
    if (val < root->val)
      root = root->left;
    else
      root = root->right;
  }
  return nullptr;
}

class LowestCommonAncestorOfABinarySearchTreeTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LowestCommonAncestorOfABinarySearchTreeSolution solution;
};

TEST_P(LowestCommonAncestorOfABinarySearchTreeTest, Example1) {
  // tree: [6,2,8,0,4,7,9,null,null,3,5]
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = findNode(root, 2);
  TreeNode* q = findNode(root, 8);
  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 6);
  delete root;
}

TEST_P(LowestCommonAncestorOfABinarySearchTreeTest, Example2) {
  // tree: [6,2,8,0,4,7,9,null,null,3,5]
  TreeNode* root = constructTree(std::vector<std::optional<int>>{
      6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = findNode(root, 2);
  TreeNode* q = findNode(root, 4);
  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 2);
  delete root;
}

TEST_P(LowestCommonAncestorOfABinarySearchTreeTest, Example3) {
  // tree: [2,1]
  TreeNode* root = constructTree(std::vector<std::optional<int>>{2, 1});
  TreeNode* p = findNode(root, 2);
  TreeNode* q = findNode(root, 1);
  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 2);
  delete root;
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         LowestCommonAncestorOfABinarySearchTreeTest,
                         testing::ValuesIn(LowestCommonAncestorOfABinarySearchTreeSolution()
                                               .getStrategyNames()));

}  // namespace leetcode::problem_235

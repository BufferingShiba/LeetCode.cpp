#include <vector>

#include "leetcode/problems/binary-tree-preorder-traversal.h"

namespace leetcode::problem_144 {

namespace {

std::vector<int> preorderTraversalImpl(TreeNode* root) {
  std::vector<int> result;
  std::vector<TreeNode*> stack;
  if (root == nullptr) {
    return result;
  }
  stack.push_back(root);
  while (!stack.empty()) {
    TreeNode* node = stack.back();
    stack.pop_back();
    result.push_back(node->val);
    // Push right first so left is processed first (LIFO).
    if (node->right != nullptr) {
      stack.push_back(node->right);
    }
    if (node->left != nullptr) {
      stack.push_back(node->left);
    }
  }
  return result;
}

}  // namespace

BinaryTreePreorderTraversalSolution::BinaryTreePreorderTraversalSolution() {
  setMetaInfo({.id = 144,
               .title = "Binary Tree Preorder Traversal",
               .url = "https://leetcode.com/problems/binary-tree-preorder-traversal/"});

  registerStrategy({.name = "Iterative Stack",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Stack", "Tree", "Depth-First Search", "Binary Tree"}},
                   preorderTraversalImpl);
}

std::vector<int> BinaryTreePreorderTraversalSolution::preorderTraversal(
    TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_144

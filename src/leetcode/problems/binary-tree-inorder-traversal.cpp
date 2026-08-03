#include "leetcode/problems/binary-tree-inorder-traversal.h"

#include <vector>

namespace leetcode {
namespace problem_94 {

namespace {

std::vector<int> inorderTraversalImpl(TreeNode* root) {
  std::vector<int> result;
  std::vector<TreeNode*> stack;
  while (root || !stack.empty()) {
    while (root) {
      stack.push_back(root);
      root = root->left;
    }
    root = stack.back();
    stack.pop_back();
    result.push_back(root->val);
    root = root->right;
  }
  return result;
}

}  // namespace

BinaryTreeInorderTraversalSolution::BinaryTreeInorderTraversalSolution() {
  setMetaInfo({.id = 94,
               .title = "Binary Tree Inorder Traversal",
               .url = "https://leetcode.com/problems/binary-tree-inorder-traversal/"});

  registerStrategy(
      {.name = "Iterative Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Stack", "Tree", "Depth-First Search", "Binary Tree"}},
      inorderTraversalImpl);
}

std::vector<int> BinaryTreeInorderTraversalSolution::inorderTraversal(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_94
}  // namespace leetcode

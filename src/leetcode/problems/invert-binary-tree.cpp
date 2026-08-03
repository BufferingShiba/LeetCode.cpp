#include "leetcode/problems/invert-binary-tree.h"

namespace leetcode {
namespace problem_226 {

namespace {

// Recursive post-order DFS: invert left/right subtrees, then swap.
TreeNode* invertTreeImpl(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }
  TreeNode* left = invertTreeImpl(root->left);
  TreeNode* right = invertTreeImpl(root->right);
  root->left = right;
  root->right = left;
  return root;
}

}  // namespace

InvertBinaryTreeSolution::InvertBinaryTreeSolution() {
  setMetaInfo({.id = 226,
               .title = "Invert Binary Tree",
               .url = "https://leetcode.com/problems/invert-binary-tree/"});

  registerStrategy(
      {.name = "recursive-dfs",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search"}},
      &invertTreeImpl);
}

TreeNode* InvertBinaryTreeSolution::invertTree(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_226
}  // namespace leetcode

#include "leetcode/problems/flatten-binary-tree-to-linked-list.h"

namespace leetcode::problem_114 {

//! Morris-style in-place flatten: O(n) time, O(1) extra space.
//! For each node, if it has a left child, find the predecessor (rightmost
//! node of the left subtree), attach the current right subtree to its right,
//! then move the left subtree to the right and null out the left child.
void flattenImpl(TreeNode* root) {
  TreeNode* cur = root;
  while (cur != nullptr) {
    if (cur->left != nullptr) {
      // Find the predecessor of cur in its left subtree.
      TreeNode* predecessor = cur->left;
      while (predecessor->right != nullptr) {
        predecessor = predecessor->right;
      }
      // Relink: predecessor.right -> cur.right.
      predecessor->right = cur->right;
      // Move left subtree to right, clear left.
      cur->right = cur->left;
      cur->left = nullptr;
    }
    cur = cur->right;
  }
}

FlattenBinaryTreeToLinkedListSolution::FlattenBinaryTreeToLinkedListSolution() {
  setMetaInfo(
      {.id = 114,
       .title = "Flatten Binary Tree to Linked List",
       .url =
           "https://leetcode.com/problems/flatten-binary-tree-to-linked-list/"});
  registerStrategy(
      {.name = "MorrisFlatten",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Tree", "Linked List", "Stack", "Depth-First Search", "Binary Tree"}},
      flattenImpl);
}

void FlattenBinaryTreeToLinkedListSolution::flatten(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_114

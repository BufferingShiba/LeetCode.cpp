#include "leetcode/problems/insert-into-a-binary-search-tree.h"

namespace leetcode {
namespace problem_701 {

static TreeNode* insertIntoBSTImpl(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }
  if (val < root->val) {
    root->left = insertIntoBSTImpl(root->left, val);
  } else {
    root->right = insertIntoBSTImpl(root->right, val);
  }
  return root;
}

InsertIntoABinarySearchTreeSolution::InsertIntoABinarySearchTreeSolution() {
  setMetaInfo({.id = 701,
               .title = "Insert into a Binary Search Tree",
               .url = "https://leetcode.com/problems/insert-into-a-binary-search-tree/"});
  registerStrategy(
      {.name = "Recursive",
       .expected = "Accepted",
       .time_complexity = "O(H)",
       .space_complexity = "O(H)",
       .tags = {"Tree", "Binary Search Tree", "Binary Tree"}},
      insertIntoBSTImpl);
}

TreeNode* InsertIntoABinarySearchTreeSolution::insertIntoBST(TreeNode* root, int val) {
  return getSolution()(root, val);
}

}  // namespace problem_701
}  // namespace leetcode

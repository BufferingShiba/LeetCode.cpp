#include "leetcode/problems/search-in-a-binary-search-tree.h"

namespace leetcode::problem_700 {
namespace {

TreeNode* searchBSTIterative(TreeNode* root, int val) {
  while (root != nullptr) {
    if (root->val == val) {
      return root;
    }
    root = (val < root->val) ? root->left : root->right;
  }
  return nullptr;
}

}  // namespace

SearchInABinarySearchTreeSolution::SearchInABinarySearchTreeSolution() {
  setMetaInfo({.id = 700,
               .title = "Search in a Binary Search Tree",
               .url =
                   "https://leetcode.com/problems/search-in-a-binary-search-tree/"});

  registerStrategy(
      {.name = "IterativeBSTSearch",
       .expected = "Accepted",
       .time_complexity = "O(h)",
       .space_complexity = "O(1)",
       .tags = {"Tree", "Binary Tree", "Binary Search Tree"}},
      searchBSTIterative);
}

TreeNode* SearchInABinarySearchTreeSolution::searchBST(TreeNode* root,
                                                       int val) {
  return getSolution()(root, val);
}

}  // namespace leetcode::problem_700

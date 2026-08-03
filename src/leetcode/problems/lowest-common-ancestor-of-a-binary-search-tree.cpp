#include "leetcode/problems/lowest-common-ancestor-of-a-binary-search-tree.h"

namespace leetcode::problem_235 {

static TreeNode* lowestCommonAncestorImpl(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* curr = root;
  while (curr != nullptr) {
    if (p->val < curr->val && q->val < curr->val) {
      curr = curr->left;
    } else if (p->val > curr->val && q->val > curr->val) {
      curr = curr->right;
    } else {
      return curr;
    }
  }
  return nullptr;  // unreachable per constraints
}

LowestCommonAncestorOfABinarySearchTreeSolution::LowestCommonAncestorOfABinarySearchTreeSolution() {
  setMetaInfo({.id = 235,
               .title = "Lowest Common Ancestor of a Binary Search Tree",
               .url = "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/"});
  registerStrategy({.name = "BST Iterative",
                    .expected = "Accepted",
                    .time_complexity = "O(h)",
                    .space_complexity = "O(1)",
                    .tags = {"Tree", "Depth-First Search", "Binary Search Tree", "Binary Tree"}},
                   lowestCommonAncestorImpl);
}

TreeNode* LowestCommonAncestorOfABinarySearchTreeSolution::lowestCommonAncestor(TreeNode* root,
                                                                                 TreeNode* p,
                                                                                 TreeNode* q) {
  return getSolution()(root, p, q);
}

}  // namespace leetcode::problem_235

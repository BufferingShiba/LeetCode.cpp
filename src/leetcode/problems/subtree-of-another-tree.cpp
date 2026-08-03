#include "leetcode/problems/subtree-of-another-tree.h"

namespace leetcode::problem_572 {

namespace {

bool isSubtreeImpl(TreeNode* root, TreeNode* subRoot) {
  if (!root) return false;
  if (leetcode::isSameTree(root, subRoot)) return true;
  return isSubtreeImpl(root->left, subRoot) ||
         isSubtreeImpl(root->right, subRoot);
}

}  // namespace

SubtreeOfAnotherTreeSolution::SubtreeOfAnotherTreeSolution() {
  setMetaInfo({.id = 572,
               .title = "Subtree of Another Tree",
               .url = "https://leetcode.com/problems/subtree-of-another-tree/"});
  registerStrategy(
      {.name = "DFS",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "DFS"}},
      isSubtreeImpl);
}

bool SubtreeOfAnotherTreeSolution::isSubtree(TreeNode* root,
                                              TreeNode* subRoot) {
  return getSolution()(root, subRoot);
}

}  // namespace leetcode::problem_572

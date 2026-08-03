#include "leetcode/problems/univalued-binary-tree.h"

namespace leetcode {
namespace problem_965 {

namespace {

bool isUnivalTreeImpl(TreeNode* root) {
  if (root == nullptr) return true;
  if (root->left != nullptr && root->left->val != root->val) return false;
  if (root->right != nullptr && root->right->val != root->val) return false;
  return isUnivalTreeImpl(root->left) && isUnivalTreeImpl(root->right);
}

}  // namespace

UnivaluedBinaryTreeSolution::UnivaluedBinaryTreeSolution() {
  setMetaInfo({965, "Univalued Binary Tree",
               "https://leetcode.com/problems/univalued-binary-tree/"});

  registerStrategy(
      {.name = "DFS Recursion",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"},
       .notes =
           "Recursively compare each node's value with its parent. "
           "If any child differs, return false."},
      isUnivalTreeImpl);
}

bool UnivaluedBinaryTreeSolution::isUnivalTree(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_965
}  // namespace leetcode

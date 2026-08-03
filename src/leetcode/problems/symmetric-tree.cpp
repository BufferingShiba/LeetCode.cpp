#include "leetcode/problems/symmetric-tree.h"

namespace leetcode {
namespace problem_101 {
namespace {

bool isSymmetricMirror(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr) {
    return true;
  }
  if (left == nullptr || right == nullptr) {
    return false;
  }
  return left->val == right->val &&
         isSymmetricMirror(left->left, right->right) &&
         isSymmetricMirror(left->right, right->left);
}

bool isSymmetricRootImpl(TreeNode* root) {
  if (root == nullptr) {
    return true;
  }
  return isSymmetricMirror(root->left, root->right);
}

}  // namespace

SymmetricTreeSolution::SymmetricTreeSolution() {
  setMetaInfo({.id = 101,
               .title = "Symmetric Tree",
               .url = "https://leetcode.com/problems/symmetric-tree/"});
  registerStrategy({.name = "Recursive DFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(h)",
                    .tags = {"tree", "depth-first-search", "recursion"}},
                   isSymmetricRootImpl);
}

bool SymmetricTreeSolution::isSymmetric(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_101
}  // namespace leetcode

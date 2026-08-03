#include "leetcode/problems/maximum-binary-tree-ii.h"

namespace leetcode {
namespace problem_998 {

static TreeNode* solution1(TreeNode* root, int val) {
  if (root == nullptr) {
    return new TreeNode(val);
  }
  if (val > root->val) {
    TreeNode* node = new TreeNode(val);
    node->left = root;
    return node;
  }
  root->right = solution1(root->right, val);
  return root;
}

MaximumBinaryTreeIiSolution::MaximumBinaryTreeIiSolution() {
  setMetaInfo({
      .id = 998,
      .title = "Maximum Binary Tree II",
      .url = "https://leetcode.com/problems/maximum-binary-tree-ii/"
  });
  registerStrategy({.name = "Recursion along right spine",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Tree"}},
                   solution1);
}

TreeNode* MaximumBinaryTreeIiSolution::insertIntoMaxTree(TreeNode* root, int val) {
  return getSolution()(root, val);
}

}  // namespace problem_998
}  // namespace leetcode

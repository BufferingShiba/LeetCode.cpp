#include "leetcode/problems/minimum-absolute-difference-in-bst.h"

namespace leetcode {
namespace problem_530 {

namespace {

int inOrderDifference(TreeNode* root, int& prev, bool& hasPrev) {
  if (root == nullptr) {
    return INT_MAX;
  }
  int minDiff = INT_MAX;
  // Left subtree
  minDiff = std::min(minDiff, inOrderDifference(root->left, prev, hasPrev));
  // Current node
  if (hasPrev) {
    minDiff = std::min(minDiff, std::abs(root->val - prev));
  }
  prev = root->val;
  hasPrev = true;
  // Right subtree
  minDiff = std::min(minDiff, inOrderDifference(root->right, prev, hasPrev));
  return minDiff;
}

int minimumAbsoluteDifference(TreeNode* root) {
  int prev = 0;
  bool hasPrev = false;
  return inOrderDifference(root, prev, hasPrev);
}

}  // namespace

MinimumAbsoluteDifferenceInBstSolution::MinimumAbsoluteDifferenceInBstSolution() {
  setMetaInfo({.id = 530,
               .title = "Minimum Absolute Difference in BST",
               .url = "https://leetcode.com/problems/minimum-absolute-difference-in-bst/"});

  registerStrategy(
      {.name = "inorder",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(H)",
       .tags = {"Tree", "Binary Search Tree", "Depth-First Search"}},
      minimumAbsoluteDifference);
}

int MinimumAbsoluteDifferenceInBstSolution::getMinimumDifference(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_530
}  // namespace leetcode

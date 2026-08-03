#include "leetcode/problems/sum-of-left-leaves.h"

namespace leetcode::problem_404 {

namespace {

int sumOfLeftLeavesImpl(TreeNode* root, bool is_left) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return is_left ? root->val : 0;
  }
  return sumOfLeftLeavesImpl(root->left, true) +
         sumOfLeftLeavesImpl(root->right, false);
}

int sumOfLeftLeavesSolution(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }
  return sumOfLeftLeavesImpl(root->left, true) +
         sumOfLeftLeavesImpl(root->right, false);
}

}  // namespace

SumOfLeftLeavesSolution::SumOfLeftLeavesSolution() {
  setMetaInfo({.id = 404,
               .title = "Sum of Left Leaves",
               .url = "https://leetcode.com/problems/sum-of-left-leaves/"});
  registerStrategy(
      {.name = "DFS Recursion",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      [](TreeNode* root) { return sumOfLeftLeavesSolution(root); });
}

int SumOfLeftLeavesSolution::sumOfLeftLeaves(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_404

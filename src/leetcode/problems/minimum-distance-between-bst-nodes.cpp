#include "leetcode/problems/minimum-distance-between-bst-nodes.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_783 {
namespace {

int minDiffImpl(TreeNode* root) {
  int minDiff = INT_MAX;
  int prev = -1;
  bool hasPrev = false;

  std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    if (hasPrev) {
      minDiff = std::min(minDiff, node->val - prev);
    }
    prev = node->val;
    hasPrev = true;
    inorder(node->right);
  };

  inorder(root);
  return minDiff;
}

}  // namespace

MinimumDistanceBetweenBstNodesSolution::MinimumDistanceBetweenBstNodesSolution() {
  setMetaInfo({.id = 783,
               .title = "Minimum Distance Between BST Nodes",
               .url = "https://leetcode.com/problems/minimum-distance-between-bst-nodes/"});

  registerStrategy(
      {.name = "inorder-adjacent",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "DFS", "Binary Search Tree", "Inorder"}},
      minDiffImpl);
}

int MinimumDistanceBetweenBstNodesSolution::minDiffInBST(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_783
}  // namespace leetcode

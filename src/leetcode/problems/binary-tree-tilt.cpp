#include "leetcode/problems/binary-tree-tilt.h"

#include <cmath>

namespace leetcode {
namespace problem_563 {

static int subtreeSum(TreeNode* node, int& totalTilt) {
  if (node == nullptr) return 0;
  int leftSum = subtreeSum(node->left, totalTilt);
  int rightSum = subtreeSum(node->right, totalTilt);
  totalTilt += std::abs(leftSum - rightSum);
  return leftSum + rightSum + node->val;
}

static int findTiltImpl(TreeNode* root) {
  int totalTilt = 0;
  subtreeSum(root, totalTilt);
  return totalTilt;
}

BinaryTreeTiltSolution::BinaryTreeTiltSolution() {
  setMetaInfo({.id = 563,
               .title = "Binary Tree Tilt",
               .url = "https://leetcode.com/problems/binary-tree-tilt/"});
  registerStrategy(
      {.name = "DFS Post-order",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      findTiltImpl);
}

int BinaryTreeTiltSolution::findTilt(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_563
}  // namespace leetcode

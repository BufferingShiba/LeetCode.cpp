#include "leetcode/problems/binary-tree-maximum-path-sum.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_124 {
namespace {

void dfs(TreeNode* node, int& ans, int* gain) {
  if (node == nullptr) {
    *gain = 0;
    return;
  }
  int left_gain = 0;
  int right_gain = 0;
  dfs(node->left, ans, &left_gain);
  dfs(node->right, ans, &right_gain);
  left_gain = std::max(left_gain, 0);
  right_gain = std::max(right_gain, 0);
  ans = std::max(ans, node->val + left_gain + right_gain);
  // Contribution to the upper path: at least the node itself.
  *gain = node->val + std::max(left_gain, right_gain);
}

int maxPathSumImpl(TreeNode* root) {
  int ans = INT_MIN;
  int gain = 0;
  dfs(root, ans, &gain);
  return ans;
}

}  // namespace

BinaryTreeMaximumPathSumSolution::BinaryTreeMaximumPathSumSolution() {
  setMetaInfo({.id = 124,
               .title = "Binary Tree Maximum Path Sum",
               .url = "https://leetcode.com/problems/binary-tree-maximum-path-sum/"});
  registerStrategy(
      {.name = "postorder-dfs",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(H)",
       .tags = {"Dynamic Programming", "Tree", "Depth-First Search",
                "Binary Tree"}},
      maxPathSumImpl);
}

int BinaryTreeMaximumPathSumSolution::maxPathSum(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_124
}  // namespace leetcode

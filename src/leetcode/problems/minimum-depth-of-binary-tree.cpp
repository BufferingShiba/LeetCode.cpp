#include "leetcode/problems/minimum-depth-of-binary-tree.h"
#include <queue>
#include <utility>

namespace leetcode::problem_111 {

static int minDepthBFS(TreeNode* root) {
  if (!root) return 0;
  std::queue<std::pair<TreeNode*, int>> q;
  q.push({root, 1});
  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();
    if (!node->left && !node->right) return depth;
    if (node->left) q.push({node->left, depth + 1});
    if (node->right) q.push({node->right, depth + 1});
  }
  return 0;
}

int MinimumDepthOfBinaryTreeSolution::minDepth(TreeNode* root) {
  return getSolution()(root);
}

MinimumDepthOfBinaryTreeSolution::MinimumDepthOfBinaryTreeSolution() {
  setMetaInfo({.id = 111,
               .title = "Minimum Depth of Binary Tree",
               .url = "https://leetcode.com/problems/minimum-depth-of-binary-tree/"});
  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"BFS", "Binary Tree"}},
      minDepthBFS);
}

}  // namespace leetcode::problem_111

#include "leetcode/problems/binary-tree-right-side-view.h"

namespace leetcode {
namespace problem_199 {

namespace {

void dfs(TreeNode* node, int depth, std::vector<int>& result) {
  if (node == nullptr) return;
  // 首次到达该深度 → 当前是最右节点
  if (depth == static_cast<int>(result.size())) {
    result.push_back(node->val);
  }
  // 先右后左，保证每层先遇到的必然是最右节点
  dfs(node->right, depth + 1, result);
  dfs(node->left, depth + 1, result);
}

std::vector<int> rightSideViewImpl(TreeNode* root) {
  std::vector<int> result;
  dfs(root, 0, result);
  return result;
}

}  // namespace

BinaryTreeRightSideViewSolution::BinaryTreeRightSideViewSolution() {
  setMetaInfo({.id = 199,
               .title = "Binary Tree Right Side View",
               .url = "https://leetcode.com/problems/binary-tree-right-side-view/"});

  registerStrategy(
      {.name = "DFS Right-First",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Breadth-First Search", "Binary Tree"}},
      rightSideViewImpl);
}

std::vector<int> BinaryTreeRightSideViewSolution::rightSideView(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_199
}  // namespace leetcode

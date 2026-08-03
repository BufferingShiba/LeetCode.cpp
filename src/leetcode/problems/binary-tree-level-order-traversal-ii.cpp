#include "leetcode/problems/binary-tree-level-order-traversal-ii.h"

#include <algorithm>
#include <queue>

namespace leetcode {
namespace problem_107 {

namespace {

std::vector<std::vector<int>> levelOrderBottomImpl(TreeNode* root) {
  std::vector<std::vector<int>> result;
  if (root == nullptr) {
    return result;
  }
  std::queue<TreeNode*> queue;
  queue.push(root);
  while (!queue.empty()) {
    int level_size = static_cast<int>(queue.size());
    std::vector<int> level_node;
    level_node.reserve(level_size);
    for (int i = 0; i < level_size; ++i) {
      TreeNode* node = queue.front();
      queue.pop();
      level_node.push_back(node->val);
      if (node->left != nullptr) {
        queue.push(node->left);
      }
      if (node->right != nullptr) {
        queue.push(node->right);
      }
    }
    result.push_back(std::move(level_node));
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

BinaryTreeLevelOrderTraversalIiSolution::BinaryTreeLevelOrderTraversalIiSolution() {
  setMetaInfo({.id = 107,
               .title = "Binary Tree Level Order Traversal II",
               .url = "https://leetcode.com/problems/binary-tree-level-order-traversal-ii/"});
  registerStrategy({.name = "BFS Bottom-Up",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Tree", "Breadth-First Search", "Binary Tree"}},
                   levelOrderBottomImpl);
}

std::vector<std::vector<int>> BinaryTreeLevelOrderTraversalIiSolution::levelOrderBottom(
    TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_107
}  // namespace leetcode

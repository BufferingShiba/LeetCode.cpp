#include "leetcode/problems/average-of-levels-in-binary-tree.h"

#include <queue>

namespace leetcode::problem_637 {

static std::vector<double> levelOrderBFS(leetcode::TreeNode* root) {
  std::vector<double> result;
  if (root == nullptr) return result;

  std::queue<leetcode::TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = static_cast<int>(q.size());
    double levelSum = 0.0;

    for (int i = 0; i < levelSize; ++i) {
      leetcode::TreeNode* node = q.front();
      q.pop();
      levelSum += static_cast<double>(node->val);

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    result.push_back(levelSum / levelSize);
  }

  return result;
}

AverageOfLevelsInBinaryTreeSolution::AverageOfLevelsInBinaryTreeSolution() {
  setMetaInfo({.id = 637,
               .title = "Average of Levels in Binary Tree",
               .url = "https://leetcode.com/problems/average-of-levels-in-binary-tree/"});

  registerStrategy(
      {.name = "BFS Level Order",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Breadth-First Search", "Binary Tree"}},
      levelOrderBFS);
}

std::vector<double> AverageOfLevelsInBinaryTreeSolution::averageOfLevels(
    leetcode::TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_637

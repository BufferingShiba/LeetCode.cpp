#include "leetcode/problems/even-odd-tree.h"

#include <climits>
#include <queue>

namespace leetcode {
namespace problem_1609 {

static bool isEvenOddTreeImpl(TreeNode* root) {
  std::queue<TreeNode*> q;
  q.push(root);
  int level = 0;
  while (!q.empty()) {
    int size = static_cast<int>(q.size());
    int prev = (level % 2 == 0) ? 0 : INT_MAX;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      int val = node->val;
      if (level % 2 == 0) {
        // Even level: must be odd and strictly increasing
        if (val % 2 == 0 || val <= prev) return false;
      } else {
        // Odd level: must be even and strictly decreasing
        if (val % 2 != 0 || val >= prev) return false;
      }
      prev = val;
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    ++level;
  }
  return true;
}

EvenOddTreeSolution::EvenOddTreeSolution() {
  setMetaInfo({.id = 1609,
               .title = "Even Odd Tree",
               .url = "https://leetcode.com/problems/even-odd-tree/"});
  registerStrategy({.name = "BFS",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(w)",
                    .tags = {"Tree", "Breadth-First Search", "Binary Tree"}},
                   isEvenOddTreeImpl);
}

bool EvenOddTreeSolution::isEvenOddTree(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_1609
}  // namespace leetcode

#include "leetcode/problems/deepest-leaves-sum.h"

#include <vector>

namespace leetcode {
namespace problem_1302 {

static int solution1(TreeNode* root) {
  if (root == nullptr) return 0;

  // BFS level-order: accumulate sum at each level, resetting for the next level.
  // After the traversal, `sum` holds the total of the last (deepest) level.
  int sum = 0;
  std::vector<TreeNode*> queue;
  queue.push_back(root);
  while (!queue.empty()) {
    sum = 0;
    std::vector<TreeNode*> next_queue;
    for (TreeNode* node : queue) {
      sum += node->val;
      if (node->left) next_queue.push_back(node->left);
      if (node->right) next_queue.push_back(node->right);
    }
    if (next_queue.empty()) break;
    queue = next_queue;
  }
  return sum;
}

DeepestLeavesSumSolution::DeepestLeavesSumSolution() {
  setMetaInfo({
      .id = 1302,
      .title = "Deepest Leaves Sum",
      .url = "https://leetcode.com/problems/deepest-leaves-sum"
  });
  registerStrategy({.name = "Brute Force",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"BFS", "Tree"}},
                   solution1);
}

int DeepestLeavesSumSolution::deepestLeavesSum(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_1302
}  // namespace leetcode

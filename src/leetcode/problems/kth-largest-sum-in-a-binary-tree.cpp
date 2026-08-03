#include "leetcode/problems/kth-largest-sum-in-a-binary-tree.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

namespace leetcode {
namespace problem_2583 {

static long long kthLargestLevelSumImpl(TreeNode* root, int k) {
  if (root == nullptr) {
    return -1;
  }

  std::vector<long long> level_sums;
  std::queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int size = static_cast<int>(q.size());
    long long sum = 0;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      sum += node->val;
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    level_sums.push_back(sum);
  }

  if (k > static_cast<int>(level_sums.size())) {
    return -1;
  }

  // 降序排序，取第 k 大
  std::sort(level_sums.begin(), level_sums.end(), std::greater<long long>());
  return level_sums[k - 1];
}

long long KthLargestSumInABinaryTreeSolution::kthLargestLevelSum(
    TreeNode* root, int k) {
  return getSolution()(root, k);
}

KthLargestSumInABinaryTreeSolution::KthLargestSumInABinaryTreeSolution() {
  setMetaInfo({.id = 2583,
               .title = "Kth Largest Sum in a Binary Tree",
               .url =
                   "https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/"});
  registerStrategy(
      {.name = "BFS + Sorting",
       .expected = "Accepted",
       .time_complexity = "O(n + L log L)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Breadth-First Search", "Sorting", "Binary Tree"}},
      kthLargestLevelSumImpl);
}

}  // namespace problem_2583
}  // namespace leetcode

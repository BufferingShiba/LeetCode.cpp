#include "leetcode/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level.h"

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2471 {

// 计算将数组排为升序所需的最少两两交换次数
static int minSwapsToSort(std::vector<int>& arr) {
  int n = static_cast<int>(arr.size());
  if (n <= 1) return 0;

  // 排序后的目标数组
  std::vector<int> sorted = arr;
  std::sort(sorted.begin(), sorted.end());

  // value -> 目标下标
  std::unordered_map<int, int> val_to_idx;
  for (int i = 0; i < n; ++i) {
    val_to_idx[sorted[i]] = i;
  }

  // 将当前值替换为目标位置，形成置换数组
  std::vector<int> pos(n);
  for (int i = 0; i < n; ++i) {
    pos[i] = val_to_idx[arr[i]];
  }

  // 统计循环
  std::vector<bool> visited(n, false);
  int swaps = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i]) continue;
    visited[i] = true;
    int cycle_len = 1;
    int j = pos[i];
    while (j != i) {
      visited[j] = true;
      ++cycle_len;
      j = pos[j];
    }
    swaps += cycle_len - 1;
  }

  return swaps;
}

static int minimumOperationsImpl(TreeNode* root) {
  if (!root) return 0;

  std::queue<TreeNode*> q;
  q.push(root);
  int total_ops = 0;

  while (!q.empty()) {
    int level_size = static_cast<int>(q.size());
    std::vector<int> level_vals;
    level_vals.reserve(level_size);

    for (int i = 0; i < level_size; ++i) {
      TreeNode* node = q.front();
      q.pop();
      level_vals.push_back(node->val);
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }

    total_ops += minSwapsToSort(level_vals);
  }

  return total_ops;
}

MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution::MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution() {
  setMetaInfo({.id = 2471,
               .title = "Minimum Number of Operations to Sort a Binary Tree by Level",
               .url = "https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/"});
  registerStrategy({.name = "BFS + Cycle Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(N log N)",
                    .space_complexity = "O(N)",
                    .tags = {"Tree", "Breadth-First Search", "Binary Tree"}},
                   minimumOperationsImpl);
}

int MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution::minimumOperations(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_2471
}  // namespace leetcode

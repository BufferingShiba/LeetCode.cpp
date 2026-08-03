#include "leetcode/problems/maximum-width-of-binary-tree.h"

#include <algorithm>
#include <queue>
#include <utility>

namespace leetcode {
namespace problem_662 {

namespace {

int widthOfBinaryTreeImpl(TreeNode* root) {
  if (!root) return 0;

  using ull = unsigned long long;
  std::queue<std::pair<TreeNode*, ull>> q;
  q.push({root, 0ULL});  // 0-based indexing

  ull max_width = 0;

  while (!q.empty()) {
    int sz = static_cast<int>(q.size());
    ull left = q.front().second;
    ull right = q.back().second;
    max_width = std::max(max_width, right - left + 1);

    for (int i = 0; i < sz; ++i) {
      auto [node, idx] = q.front();
      q.pop();
      ull rel = idx - left;  // normalize to prevent overflow
      if (node->left) {
        q.push({node->left, 2 * rel + 1});
      }
      if (node->right) {
        q.push({node->right, 2 * rel + 2});
      }
    }
  }

  return static_cast<int>(max_width);
}

}  // anonymous namespace

MaximumWidthOfBinaryTreeSolution::MaximumWidthOfBinaryTreeSolution() {
  setMetaInfo({.id = 662,
               .title = "Maximum Width of Binary Tree",
               .url = "https://leetcode.com/problems/maximum-width-of-binary-tree/"});
  registerStrategy(
      {.name = "BFS with Index Normalization",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Tree", "Breadth-First Search", "Binary Tree"}},
      widthOfBinaryTreeImpl);
}

int MaximumWidthOfBinaryTreeSolution::widthOfBinaryTree(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_662
}  // namespace leetcode

#include "leetcode/problems/longest-univalue-path.h"

#include <algorithm>

namespace leetcode::problem_687 {

namespace {

int dfs(TreeNode* node, int& result) {
  if (node == nullptr) {
    return 0;
  }
  int left_len = dfs(node->left, result);
  int right_len = dfs(node->right, result);

  int left_path = 0;
  int right_path = 0;
  if (node->left != nullptr && node->left->val == node->val) {
    left_path = left_len + 1;
  }
  if (node->right != nullptr && node->right->val == node->val) {
    right_path = right_len + 1;
  }
  result = std::max(result, left_path + right_path);
  return std::max(left_path, right_path);
}

int longestUnivaluePathImpl(TreeNode* root) {
  int result = 0;
  dfs(root, result);
  return result;
}

}  // namespace

LongestUnivaluePathSolution::LongestUnivaluePathSolution() {
  this->setMetaInfo({.id = 687,
                     .title = "Longest Univalue Path",
                     .url = "https://leetcode.com/problems/longest-univalue-path/"});
  this->registerStrategy(
      {.name = "DFS",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      longestUnivaluePathImpl);
}

int LongestUnivaluePathSolution::longestUnivaluePath(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace leetcode::problem_687

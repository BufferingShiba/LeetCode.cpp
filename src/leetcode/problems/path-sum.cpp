#include "leetcode/problems/path-sum.h"

namespace leetcode::problem_112 {
namespace {

bool hasPathSumImpl(TreeNode* root, int targetSum) {
  if (root == nullptr) {
    return false;
  }
  targetSum -= root->val;
  if (root->left == nullptr && root->right == nullptr) {
    return targetSum == 0;
  }
  return hasPathSumImpl(root->left, targetSum) ||
         hasPathSumImpl(root->right, targetSum);
}

}  // namespace

PathSumSolution::PathSumSolution() {
  setMetaInfo(
      {.id = 112, .title = "Path Sum", .url = "https://leetcode.com/problems/path-sum/"});
  registerStrategy(
      {.name = "DFS Recursive",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(h)",
       .tags = {"Tree", "Depth-First Search", "Binary Tree"}},
      hasPathSumImpl);
}

bool PathSumSolution::hasPathSum(TreeNode* root, int targetSum) {
  return getSolution()(root, targetSum);
}

}  // namespace leetcode::problem_112

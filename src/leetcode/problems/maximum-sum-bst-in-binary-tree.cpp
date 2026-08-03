#include <algorithm>
#include <climits>
#include <functional>

#include "leetcode/core.h"
#include "leetcode/problems/maximum-sum-bst-in-binary-tree.h"

namespace leetcode {
namespace problem_1373 {
namespace {

struct Result {
  bool isBST;
  int minVal;
  int maxVal;
  int sum;
};

Result maxSumBSTImpl(TreeNode* root, int& ans) {
  if (root == nullptr) {
    // Empty subtree is a valid BST.
    return {true, INT_MAX, INT_MIN, 0};
  }
  Result left = maxSumBSTImpl(root->left, ans);
  Result right = maxSumBSTImpl(root->right, ans);
  if (left.isBST && right.isBST && left.maxVal < root->val &&
      root->val < right.minVal) {
    int sum = left.sum + root->val + right.sum;
    ans = std::max(ans, sum);
    return {true, std::min(left.minVal, root->val),
            std::max(right.maxVal, root->val), sum};
  }
  return {false, 0, 0, 0};
}

int maxSumBSTFree(TreeNode* root) {
  int ans = 0;  // Empty BST gives sum 0.
  maxSumBSTImpl(root, ans);
  return ans;
}

}  // namespace

MaximumSumBstInBinaryTreeSolution::MaximumSumBstInBinaryTreeSolution() {
  setMetaInfo({.id = 1373, .title = "Maximum Sum BST in Binary Tree",
               .url = "https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/"});
  registerStrategy(
      {.name = "dfs", .expected = "Accepted", .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Tree", "Depth-First Search", "Binary Search Tree"}},
      maxSumBSTFree);
}

int MaximumSumBstInBinaryTreeSolution::maxSumBST(TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_1373
}  // namespace leetcode

#include "leetcode/problems/binary-tree-postorder-traversal.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_145 {

namespace {

// Iterative postorder: do a modified preorder (root, right, left) by pushing
// left then right onto the stack, then reverse to get (left, right, root).
std::vector<int> postorderTraversalImpl(TreeNode* root) {
  std::vector<int> result;
  if (root == nullptr) {
    return result;
  }
  std::vector<TreeNode*> stack;
  stack.push_back(root);
  while (!stack.empty()) {
    TreeNode* node = stack.back();
    stack.pop_back();
    result.push_back(node->val);
    if (node->left != nullptr) {
      stack.push_back(node->left);
    }
    if (node->right != nullptr) {
      stack.push_back(node->right);
    }
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

BinaryTreePostorderTraversalSolution::BinaryTreePostorderTraversalSolution() {
  setMetaInfo({.id = 145,
               .title = "Binary Tree Postorder Traversal",
               .url = "https://leetcode.com/problems/binary-tree-postorder-traversal/"});
  registerStrategy(
      {.name = "Iterative Stack + Reverse",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Stack", "Tree", "Depth-First Search", "Binary Tree"}},
      postorderTraversalImpl);
}

std::vector<int> BinaryTreePostorderTraversalSolution::postorderTraversal(
    TreeNode* root) {
  return getSolution()(root);
}

}  // namespace problem_145
}  // namespace leetcode

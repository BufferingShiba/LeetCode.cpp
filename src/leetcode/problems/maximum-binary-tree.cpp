#include "leetcode/problems/maximum-binary-tree.h"

#include <vector>

namespace leetcode {
namespace problem_654 {

namespace {

// Monotonic decreasing stack approach.
// For each element, pop all smaller elements (they form the left subtree chain
// of the current element). The last popped becomes the left child of the
// current node. If the stack is non-empty after popping, the top (largest
// smaller-than-current already seen) becomes the parent candidate whose right
// child points to the current node.
TreeNode* constructMaximumBinaryTreeImpl(std::vector<int>& nums) {
  std::vector<TreeNode*> stack;
  for (int val : nums) {
    TreeNode* node = new TreeNode(val);
    TreeNode* lastPopped = nullptr;
    while (!stack.empty() && stack.back()->val < val) {
      lastPopped = stack.back();
      stack.pop_back();
    }
    node->left = lastPopped;
    if (!stack.empty()) {
      stack.back()->right = node;
    }
    stack.push_back(node);
  }
  return stack.empty() ? nullptr : stack.front();
}

}  // namespace

MaximumBinaryTreeSolution::MaximumBinaryTreeSolution() {
  setMetaInfo({.id = 654,
               .title = "Maximum Binary Tree",
               .url =
                   "https://leetcode.com/problems/maximum-binary-tree/"});
  registerStrategy({.name = "MonotonicStack",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Monotonic Stack", "Binary Tree"}},
                   constructMaximumBinaryTreeImpl);
}

TreeNode* MaximumBinaryTreeSolution::constructMaximumBinaryTree(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_654
}  // namespace leetcode

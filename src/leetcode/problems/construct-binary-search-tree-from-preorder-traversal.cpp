#include "leetcode/problems/construct-binary-search-tree-from-preorder-traversal.h"

#include <vector>

#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_1008 {
namespace {

// Build the BST from its preorder traversal using a monotonic stack.
//
// Preorder visits root, then left subtree, then right subtree. For a BST, the
// first element is the root. We scan the remaining elements and keep a
// strictly decreasing stack that represents the current right spine of nodes
// whose right child has not been set yet. When we encounter a value larger
// than the top of the stack, we pop while the top is smaller than the new
// value; the last popped node becomes the parent of the new node (the new
// node hangs on its right). Otherwise the new node becomes the left child of
// the current stack top. Then the new node is pushed onto the stack.
//
// Time complexity : O(n) (each node is pushed and popped once).
// Space complexity: O(n) for the stack.
TreeNode* bstFromPreorderImpl(std::vector<int>& preorder) {
  if (preorder.empty()) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(preorder[0]);
  std::vector<TreeNode*> stack;
  stack.push_back(root);

  for (int i = 1; i < static_cast<int>(preorder.size()); ++i) {
    TreeNode* node = new TreeNode(preorder[i]);
    TreeNode* last = nullptr;

    while (!stack.empty() && stack.back()->val < preorder[i]) {
      last = stack.back();
      stack.pop_back();
    }

    if (last != nullptr) {
      last->right = node;
    } else {
      // preorder[i] < stack.back()->val: belongs to the left subtree of the
      // current stack top.
      stack.back()->left = node;
    }
    stack.push_back(node);
  }

  return root;
}

}  // namespace

TreeNode* ConstructBinarySearchTreeFromPreorderTraversalSolution::
    bstFromPreorder(std::vector<int>& preorder) {
  return getSolution()(preorder);
}

ConstructBinarySearchTreeFromPreorderTraversalSolution::
    ConstructBinarySearchTreeFromPreorderTraversalSolution() {
  setMetaInfo({.id = 1008,
               .title = "Construct Binary Search Tree from Preorder Traversal",
               .url = "https://leetcode.com/problems/"
                      "construct-binary-search-tree-from-preorder-traversal"});

  registerStrategy(
      {.name = "monotonic_stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"array", "stack", "tree", "binary-search-tree",
                "monotonic-stack", "binary-tree"},
       .notes = "Scan preorder with a strictly decreasing stack of the current "
                "right-spine nodes to attach each next value in O(n) time."},
      bstFromPreorderImpl);
}

}  // namespace problem_1008
}  // namespace leetcode

#include "leetcode/problems/recover-binary-search-tree.h"

#include <functional>

namespace leetcode {
namespace problem_99 {

namespace {

void recoverTreeInorderImpl(TreeNode* root) {
  TreeNode* prev = nullptr;
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;

  std::function<void(TreeNode*)> inorder = [&](TreeNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    if (prev != nullptr && prev->val > node->val) {
      if (first == nullptr) {
        first = prev;
      }
      second = node;
    }
    prev = node;
    inorder(node->right);
  };

  inorder(root);
  std::swap(first->val, second->val);
}

void recoverTreeMorrisImpl(TreeNode* root) {
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;

  // Iterative (stackless) Morris traversal for in-order, using O(1) space.
  TreeNode* current = root;
  TreeNode* prev = nullptr;
  while (current != nullptr) {
    if (current->left == nullptr) {
      // Visit current in inorder.
      if (prev != nullptr && prev->val > current->val) {
        if (first == nullptr) first = prev;
        second = current;
      }
      prev = current;
      current = current->right;
    } else {
      // Find the inorder predecessor of current.
      TreeNode* pred = current->left;
      while (pred->right != nullptr && pred->right != current) {
        pred = pred->right;
      }
      if (pred->right == nullptr) {
        // First visit: link predecessor to current.
        pred->right = current;
        current = current->left;
      } else {
        // Restore the tree (unlink).
        pred->right = nullptr;
        // Visit current in inorder.
        if (prev != nullptr && prev->val > current->val) {
          if (first == nullptr) first = prev;
          second = current;
        }
        prev = current;
        current = current->right;
      }
    }
  }

  std::swap(first->val, second->val);
}

}  // namespace

void RecoverBinarySearchTreeSolution::recoverTreeInorder(TreeNode* root) {
  return recoverTreeInorderImpl(root);
}

void RecoverBinarySearchTreeSolution::recoverTreeMorris(TreeNode* root) {
  return recoverTreeMorrisImpl(root);
}

}  // namespace problem_99
}  // namespace leetcode

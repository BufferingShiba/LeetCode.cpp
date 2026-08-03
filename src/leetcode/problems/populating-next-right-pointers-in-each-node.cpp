#include "leetcode/problems/populating-next-right-pointers-in-each-node.h"

namespace leetcode {
namespace problem_116 {

namespace {

// Static strategy: walk level by level using established next pointers.
// O(n) time, O(1) extra space.
Node* connectLevelByLevel(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }
  Node* leftmost = root;
  while (leftmost->left != nullptr) {
    Node* curr = leftmost;
    while (curr != nullptr) {
      curr->left->next = curr->right;
      if (curr->next != nullptr) {
        curr->right->next = curr->next->left;
      }
      curr = curr->next;
    }
    leftmost = leftmost->left;
  }
  return root;
}

}  // namespace

}  // namespace problem_116
}  // namespace leetcode

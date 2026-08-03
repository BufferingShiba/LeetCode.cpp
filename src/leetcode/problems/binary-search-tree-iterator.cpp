#include "leetcode/problems/binary-search-tree-iterator.h"

namespace leetcode {
namespace problem_173 {

BinarySearchTreeIterator::BinarySearchTreeIterator(TreeNode* root) {
  pushLeftPath(root);
}

int BinarySearchTreeIterator::next() {
  TreeNode* node = stack_.back();
  stack_.pop_back();
  pushLeftPath(node->right);
  return node->val;
}

bool BinarySearchTreeIterator::hasNext() { return !stack_.empty(); }

void BinarySearchTreeIterator::pushLeftPath(TreeNode* node) {
  while (node != nullptr) {
    stack_.push_back(node);
    node = node->left;
  }
}

}  // namespace problem_173
}  // namespace leetcode

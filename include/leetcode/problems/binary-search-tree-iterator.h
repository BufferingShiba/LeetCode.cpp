#ifndef LEETCODE_PROBLEMS_173_BINARY_SEARCH_TREE_ITERATOR_H__
#define LEETCODE_PROBLEMS_173_BINARY_SEARCH_TREE_ITERATOR_H__

#include <vector>

#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_173 {

//! BST in-order iterator using an explicit stack (O(h) space, amortized
//! O(1) per call).
class BinarySearchTreeIterator {
 public:
  explicit BinarySearchTreeIterator(TreeNode* root);

  int next();

  bool hasNext();

 private:
  //! Push the left-spine of node (node and all its left descendants) onto the
  //! stack, so the top is the next in-order element.
  void pushLeftPath(TreeNode* node);

  std::vector<TreeNode*> stack_;
};

}  // namespace problem_173
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_173_BINARY_SEARCH_TREE_ITERATOR_H__

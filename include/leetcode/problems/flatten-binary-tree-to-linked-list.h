#ifndef LEETCODE_PROBLEMS_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H__
#define LEETCODE_PROBLEMS_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_114 {

using Func = std::function<void(TreeNode*)>;

class FlattenBinaryTreeToLinkedListSolution
    : public SolutionBase<Func> {
 public:
  FlattenBinaryTreeToLinkedListSolution();

  // LeetCode entry point.
  void flatten(TreeNode* root);
};

}  // namespace leetcode::problem_114

#endif  // LEETCODE_PROBLEMS_FLATTEN_BINARY_TREE_TO_LINKED_LIST_H__

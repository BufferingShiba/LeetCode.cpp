#ifndef LEETCODE_PROBLEMS_BINARY_TREE_PREORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_PREORDER_TRAVERSAL_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_144 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class BinaryTreePreorderTraversalSolution : public SolutionBase<Func> {
 public:
  BinaryTreePreorderTraversalSolution();

  std::vector<int> preorderTraversal(TreeNode* root);
};

}  // namespace leetcode::problem_144

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_PREORDER_TRAVERSAL_H__

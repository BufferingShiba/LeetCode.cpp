#ifndef LEETCODE_PROBLEMS_EVALUATE_BOOLEAN_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_EVALUATE_BOOLEAN_BINARY_TREE_H__

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_2331 {

using Func = std::function<bool(TreeNode*)>;

class EvaluateBooleanBinaryTreeSolution
    : public SolutionBase<Func> {
 public:
  EvaluateBooleanBinaryTreeSolution();

  bool evaluateTree(TreeNode* root);
};

}  // namespace problem_2331
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_EVALUATE_BOOLEAN_BINARY_TREE_H__

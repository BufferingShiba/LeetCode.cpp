#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUM_BST_IN_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_SUM_BST_IN_BINARY_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1373 {

class MaximumSumBstInBinaryTreeSolution
    : public SolutionBase<std::function<int(TreeNode*)>> {
 public:
  MaximumSumBstInBinaryTreeSolution();

  int maxSumBST(TreeNode* root);
};

}  // namespace problem_1373
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUM_BST_IN_BINARY_TREE_H__

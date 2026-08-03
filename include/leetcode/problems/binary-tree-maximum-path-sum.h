#ifndef LEETCODE_PROBLEMS_BINARY_TREE_MAXIMUM_PATH_SUM_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_MAXIMUM_PATH_SUM_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_124 {

using Func = std::function<int(TreeNode*)>;

class BinaryTreeMaximumPathSumSolution
    : public SolutionBase<Func> {
 public:
  BinaryTreeMaximumPathSumSolution();

  int maxPathSum(TreeNode* root);
};

}  // namespace problem_124
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_MAXIMUM_PATH_SUM_H__

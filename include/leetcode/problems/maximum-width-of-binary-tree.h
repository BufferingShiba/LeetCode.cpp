#ifndef LEETCODE_PROBLEMS_MAXIMUM_WIDTH_OF_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_MAXIMUM_WIDTH_OF_BINARY_TREE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_662 {

using Func = std::function<int(TreeNode*)>;

class MaximumWidthOfBinaryTreeSolution : public SolutionBase<Func> {
 public:
  MaximumWidthOfBinaryTreeSolution();

  int widthOfBinaryTree(TreeNode* root);
};

}  // namespace problem_662
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_WIDTH_OF_BINARY_TREE_H_

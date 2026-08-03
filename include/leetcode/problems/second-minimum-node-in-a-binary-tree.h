#ifndef LEETCODE_PROBLEMS_SECOND_MINIMUM_NODE_IN_A_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_SECOND_MINIMUM_NODE_IN_A_BINARY_TREE_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_671 {

using Func = std::function<int(TreeNode*)>;

class SecondMinimumNodeInABinaryTreeSolution : public SolutionBase<Func> {
 public:
  SecondMinimumNodeInABinaryTreeSolution();
  int findSecondMinimumValue(TreeNode* root);
};

}  // namespace problem_671
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SECOND_MINIMUM_NODE_IN_A_BINARY_TREE_H_

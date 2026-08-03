#ifndef LEETCODE_PROBLEMS_STEP_BY_STEP_DIRECTIONS_FROM_A_BINARY_TREE_NODE_TO_ANOTHER_H__
#define LEETCODE_PROBLEMS_STEP_BY_STEP_DIRECTIONS_FROM_A_BINARY_TREE_NODE_TO_ANOTHER_H__

#include <functional>
#include <string>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_2096 {

using Func = std::function<std::string(TreeNode*, int, int)>;

class StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution
    : public SolutionBase<Func> {
 public:
  StepByStepDirectionsFromABinaryTreeNodeToAnotherSolution();

  std::string getDirections(TreeNode* root, int startValue, int destValue);
};

}  // namespace leetcode::problem_2096

#endif  // LEETCODE_PROBLEMS_STEP_BY_STEP_DIRECTIONS_FROM_A_BINARY_TREE_NODE_TO_ANOTHER_H__

#ifndef LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H__
#define LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_530 {

using Func = std::function<int(TreeNode*)>;

class MinimumAbsoluteDifferenceInBstSolution
    : public SolutionBase<Func> {
 public:
  MinimumAbsoluteDifferenceInBstSolution();

  int getMinimumDifference(TreeNode* root);
};

}  // namespace problem_530
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_ABSOLUTE_DIFFERENCE_IN_BST_H__

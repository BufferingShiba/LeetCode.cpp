#ifndef LEETCODE_PROBLEM_111_H
#define LEETCODE_PROBLEM_111_H

#include "leetcode/core.h"

namespace leetcode::problem_111 {

using Func = std::function<int(TreeNode*)>;

class MinimumDepthOfBinaryTreeSolution : public SolutionBase<Func> {
 public:
  int minDepth(TreeNode* root);

  MinimumDepthOfBinaryTreeSolution();
};

}  // namespace leetcode::problem_111

#endif

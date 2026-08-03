#ifndef LEETCODE_PROBLEMS_SUM_OF_LEFT_LEAVES_H__
#define LEETCODE_PROBLEMS_SUM_OF_LEFT_LEAVES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_404 {

using Func = std::function<int(TreeNode*)>;

class SumOfLeftLeavesSolution : public SolutionBase<Func> {
 public:
  SumOfLeftLeavesSolution();

  int sumOfLeftLeaves(TreeNode* root);
};

}  // namespace leetcode::problem_404

#endif  // LEETCODE_PROBLEMS_SUM_OF_LEFT_LEAVES_H__

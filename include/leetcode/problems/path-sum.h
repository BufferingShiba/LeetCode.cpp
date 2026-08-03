#ifndef LEETCODE_PROBLEMS_PATH_SUM_H__
#define LEETCODE_PROBLEMS_PATH_SUM_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_112 {

using Func = std::function<bool(TreeNode*, int)>;

class PathSumSolution : public SolutionBase<Func> {
 public:
  bool hasPathSum(TreeNode* root, int targetSum);

  PathSumSolution();
};

}  // namespace leetcode::problem_112

#endif  // LEETCODE_PROBLEMS_PATH_SUM_H__

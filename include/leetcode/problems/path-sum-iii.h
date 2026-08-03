#ifndef LEETCODE_PROBLEMS_PATH_SUM_III_H__
#define LEETCODE_PROBLEMS_PATH_SUM_III_H__

#include <functional>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode::problem_437 {

using leetcode::TreeNode;

using Func = std::function<int(TreeNode*, int)>;

class PathSumIiiSolution : public SolutionBase<Func> {
 public:
  PathSumIiiSolution();

  int pathSum(TreeNode* root, int targetSum);
};

}  // namespace leetcode::problem_437

#endif  // LEETCODE_PROBLEMS_PATH_SUM_III_H__

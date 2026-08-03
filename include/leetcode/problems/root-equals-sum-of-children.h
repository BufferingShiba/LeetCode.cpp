#ifndef LEETCODE_PROBLEMS_ROOT_EQUALS_SUM_OF_CHILDREN_H__
#define LEETCODE_PROBLEMS_ROOT_EQUALS_SUM_OF_CHILDREN_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2236 {

using Func = std::function<bool(TreeNode*)>;

class RootEqualsSumOfChildrenSolution : public SolutionBase<Func> {
 public:
  RootEqualsSumOfChildrenSolution();
};

}  // namespace problem_2236
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ROOT_EQUALS_SUM_OF_CHILDREN_H__

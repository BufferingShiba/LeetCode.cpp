#ifndef LEETCODE_PROBLEM_2471_H_
#define LEETCODE_PROBLEM_2471_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2471 {

using Func = std::function<int(TreeNode*)>;

class MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfOperationsToSortABinaryTreeByLevelSolution();
  int minimumOperations(TreeNode* root);
};

}  // namespace problem_2471
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2471_H_

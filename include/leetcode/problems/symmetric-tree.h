#ifndef LEETCODE_PROBLEMS_SYMMETRIC_TREE_H__
#define LEETCODE_PROBLEMS_SYMMETRIC_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_101 {

using Func = std::function<bool(TreeNode*)>;

class SymmetricTreeSolution : public SolutionBase<Func> {
 public:
  SymmetricTreeSolution();

  bool isSymmetric(TreeNode* root);
};

}  // namespace problem_101
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SYMMETRIC_TREE_H__

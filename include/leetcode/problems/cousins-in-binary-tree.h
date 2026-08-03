#ifndef LEETCODE_PROBLEMS_COUSINS_IN_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_COUSINS_IN_BINARY_TREE_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_993 {

using Func = std::function<bool(TreeNode*, int, int)>;

class CousinsInBinaryTreeSolution : public SolutionBase<Func> {
 public:
  CousinsInBinaryTreeSolution();
  bool isCousins(TreeNode* root, int x, int y);
};

}  // namespace problem_993
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUSINS_IN_BINARY_TREE_H__

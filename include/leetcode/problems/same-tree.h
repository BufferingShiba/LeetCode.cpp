#ifndef LEETCODE_PROBLEMS_SAME_TREE_H__
#define LEETCODE_PROBLEMS_SAME_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_100 {

using Func = std::function<bool(TreeNode*, TreeNode*)>;

class SameTreeSolution : public SolutionBase<Func> {
 public:
  SameTreeSolution();

  bool isSameTree(TreeNode* p, TreeNode* q);
};

}  // namespace problem_100
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SAME_TREE_H__

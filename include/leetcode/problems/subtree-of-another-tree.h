#ifndef LEETCODE_PROBLEMS_SUBTREE_OF_ANOTHER_TREE_H_
#define LEETCODE_PROBLEMS_SUBTREE_OF_ANOTHER_TREE_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_572 {

using Func = std::function<bool(TreeNode*, TreeNode*)>;

class SubtreeOfAnotherTreeSolution : public SolutionBase<Func> {
 public:
  SubtreeOfAnotherTreeSolution();

  bool isSubtree(TreeNode* root, TreeNode* subRoot);
};

}  // namespace leetcode::problem_572

#endif  // LEETCODE_PROBLEMS_SUBTREE_OF_ANOTHER_TREE_H_

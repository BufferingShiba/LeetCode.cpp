#ifndef LEETCODE_PROBLEMS_TRIM_A_BINARY_SEARCH_TREE_H_
#define LEETCODE_PROBLEMS_TRIM_A_BINARY_SEARCH_TREE_H_

#include "leetcode/core.h"

namespace leetcode::problem_669 {

using Func = std::function<TreeNode*(TreeNode*, int, int)>;

class TrimABinarySearchTreeSolution : public SolutionBase<Func> {
 public:
  TrimABinarySearchTreeSolution();

  TreeNode* trimBST(TreeNode* root, int low, int high);
};

}  // namespace leetcode::problem_669

#endif  // LEETCODE_PROBLEMS_TRIM_A_BINARY_SEARCH_TREE_H_

#ifndef LEETCODE_PROBLEMS_SEARCH_IN_A_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_SEARCH_IN_A_BINARY_SEARCH_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_700 {

using Func = std::function<TreeNode*(TreeNode*, int)>;

class SearchInABinarySearchTreeSolution
    : public SolutionBase<Func> {
 public:
  SearchInABinarySearchTreeSolution();

  TreeNode* searchBST(TreeNode* root, int val);
};

}  // namespace leetcode::problem_700

#endif  // LEETCODE_PROBLEMS_SEARCH_IN_A_BINARY_SEARCH_TREE_H__

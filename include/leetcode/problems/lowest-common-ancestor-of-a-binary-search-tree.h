#ifndef LEETCODE_PROBLEMS_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_
#define LEETCODE_PROBLEMS_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_

#include "leetcode/core.h"

namespace leetcode::problem_235 {

using Func = std::function<TreeNode*(TreeNode*, TreeNode*, TreeNode*)>;

class LowestCommonAncestorOfABinarySearchTreeSolution : public SolutionBase<Func> {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

  explicit LowestCommonAncestorOfABinarySearchTreeSolution();
};

}  // namespace leetcode::problem_235

#endif  // LEETCODE_PROBLEMS_LOWEST_COMMON_ANCESTOR_OF_A_BINARY_SEARCH_TREE_H_

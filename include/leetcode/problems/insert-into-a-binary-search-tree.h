#ifndef LEETCODE_PROBLEMS_INSERT_INTO_A_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_INSERT_INTO_A_BINARY_SEARCH_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_701 {

using Func = std::function<TreeNode*(TreeNode*, int)>;

class InsertIntoABinarySearchTreeSolution : public SolutionBase<Func> {
 public:
  InsertIntoABinarySearchTreeSolution();

  TreeNode* insertIntoBST(TreeNode* root, int val);
};

}  // namespace problem_701
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INSERT_INTO_A_BINARY_SEARCH_TREE_H__

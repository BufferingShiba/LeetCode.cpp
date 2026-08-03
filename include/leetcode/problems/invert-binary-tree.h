#ifndef LEETCODE_PROBLEMS_INVERT_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_INVERT_BINARY_TREE_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_226 {

using Func = std::function<TreeNode*(TreeNode*)>;

class InvertBinaryTreeSolution : public SolutionBase<Func> {
 public:
  InvertBinaryTreeSolution();

  TreeNode* invertTree(TreeNode* root);
};

}  // namespace problem_226
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INVERT_BINARY_TREE_H__

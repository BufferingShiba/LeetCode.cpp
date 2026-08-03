#ifndef LEETCODE_PROBLEMS_UNIVALUED_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_UNIVALUED_BINARY_TREE_H__

#include <functional>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_965 {

using Func = std::function<bool(TreeNode*)>;

class UnivaluedBinaryTreeSolution
    : public SolutionBase<Func> {
 public:
  UnivaluedBinaryTreeSolution();

  bool isUnivalTree(TreeNode* root);
};

}  // namespace problem_965
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_UNIVALUED_BINARY_TREE_H__

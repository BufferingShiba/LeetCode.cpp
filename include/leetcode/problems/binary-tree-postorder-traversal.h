#ifndef LEETCODE_PROBLEMS_BINARY_TREE_POSTORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_POSTORDER_TRAVERSAL_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_145 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class BinaryTreePostorderTraversalSolution
    : public SolutionBase<Func> {
 public:
  BinaryTreePostorderTraversalSolution();

  std::vector<int> postorderTraversal(TreeNode* root);
};

}  // namespace problem_145
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_POSTORDER_TRAVERSAL_H__

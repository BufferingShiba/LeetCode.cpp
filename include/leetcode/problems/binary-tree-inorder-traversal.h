#ifndef LEETCODE_PROBLEMS_BINARY_TREE_INORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_INORDER_TRAVERSAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_94 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class BinaryTreeInorderTraversalSolution
    : public SolutionBase<Func> {
 public:
  BinaryTreeInorderTraversalSolution();

  std::vector<int> inorderTraversal(TreeNode* root);
};

}  // namespace problem_94
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_INORDER_TRAVERSAL_H__

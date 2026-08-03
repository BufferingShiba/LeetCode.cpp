#ifndef LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_
#define LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_105 {

using Func = std::function<TreeNode*(std::vector<int>&, std::vector<int>&)>;

class ConstructBinaryTreeFromPreorderAndInorderTraversalSolution
    : public SolutionBase<Func> {
 public:
  ConstructBinaryTreeFromPreorderAndInorderTraversalSolution();

  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
};

}  // namespace problem_105
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_

#ifndef LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_POSTORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_POSTORDER_TRAVERSAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_889 {

using Func = std::function<TreeNode*(std::vector<int>&, std::vector<int>&)>;

class ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution
    : public SolutionBase<Func> {
 public:
  ConstructBinaryTreeFromPreorderAndPostorderTraversalSolution();

  TreeNode* constructFromPrePost(std::vector<int>& preorder,
                                 std::vector<int>& postorder);
};

}  // namespace problem_889
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_POSTORDER_TRAVERSAL_H__

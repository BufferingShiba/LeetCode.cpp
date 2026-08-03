#ifndef LEETCODE_PROBLEMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PREORDER_TRAVERSAL_H__
#define LEETCODE_PROBLEMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PREORDER_TRAVERSAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1008 {

using Func = std::function<leetcode::TreeNode*(std::vector<int>&)>;

class ConstructBinarySearchTreeFromPreorderTraversalSolution
    : public SolutionBase<Func> {
 public:
  ConstructBinarySearchTreeFromPreorderTraversalSolution();
  leetcode::TreeNode* bstFromPreorder(std::vector<int>& preorder);
};

}  // namespace problem_1008
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CONSTRUCT_BINARY_SEARCH_TREE_FROM_PREORDER_TRAVERSAL_H__

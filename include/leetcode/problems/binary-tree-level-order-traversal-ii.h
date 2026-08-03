#ifndef LEETCODE_PROBLEMS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H__
#define LEETCODE_PROBLEMS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"
#include "leetcode/utils/tree.h"

namespace leetcode {
namespace problem_107 {

using Func = std::function<std::vector<std::vector<int>>(TreeNode*)>;

class BinaryTreeLevelOrderTraversalIiSolution
    : public SolutionBase<Func> {
 public:
  BinaryTreeLevelOrderTraversalIiSolution();

  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root);
};

}  // namespace problem_107
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_II_H__

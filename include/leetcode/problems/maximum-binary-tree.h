#ifndef LEETCODE_PROBLEMS_MAXIMUM_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_BINARY_TREE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_654 {

using Func = std::function<TreeNode*(std::vector<int>&)>;

class MaximumBinaryTreeSolution : public SolutionBase<Func> {
 public:
  MaximumBinaryTreeSolution();

  TreeNode* constructMaximumBinaryTree(std::vector<int>& nums);
};

}  // namespace problem_654
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_BINARY_TREE_H__

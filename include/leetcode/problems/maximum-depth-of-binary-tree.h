#ifndef LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_BINARY_TREE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_BINARY_TREE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_104 {

using Func = std::function<int(TreeNode*)>;

class MaximumDepthOfBinaryTreeSolution
    : public SolutionBase<Func> {
 public:
  MaximumDepthOfBinaryTreeSolution();

  int maxDepth(TreeNode* root);
};

}  // namespace problem_104
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DEPTH_OF_BINARY_TREE_H__

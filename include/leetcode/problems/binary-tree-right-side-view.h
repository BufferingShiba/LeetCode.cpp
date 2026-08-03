#ifndef LEETCODE_PROBLEMS_BINARY_TREE_RIGHT_SIDE_VIEW_H_
#define LEETCODE_PROBLEMS_BINARY_TREE_RIGHT_SIDE_VIEW_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_199 {

using Func = std::function<std::vector<int>(TreeNode*)>;

class BinaryTreeRightSideViewSolution : public SolutionBase<Func> {
 public:
  BinaryTreeRightSideViewSolution();

  std::vector<int> rightSideView(TreeNode* root);
};

}  // namespace problem_199
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_RIGHT_SIDE_VIEW_H_

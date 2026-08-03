#ifndef LEETCODE_PROBLEMS_BINARY_TREE_TILT_H_
#define LEETCODE_PROBLEMS_BINARY_TREE_TILT_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_563 {

using Func = std::function<int(TreeNode*)>;

class BinaryTreeTiltSolution : public SolutionBase<Func> {
 public:
  int findTilt(TreeNode* root);

  BinaryTreeTiltSolution();
};

}  // namespace problem_563
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_TILT_H_

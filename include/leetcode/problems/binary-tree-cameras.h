#ifndef LEETCODE_PROBLEMS_BINARY_TREE_CAMERAS_H_
#define LEETCODE_PROBLEMS_BINARY_TREE_CAMERAS_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_968 {

using Func = std::function<int(TreeNode*)>;

class BinaryTreeCamerasSolution : public SolutionBase<Func> {
 public:
  BinaryTreeCamerasSolution();

  int minCameraCover(TreeNode* root);
};

}  // namespace problem_968
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_BINARY_TREE_CAMERAS_H_

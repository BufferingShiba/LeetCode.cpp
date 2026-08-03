#ifndef LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H__
#define LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_783 {

using Func = std::function<int(TreeNode*)>;

class MinimumDistanceBetweenBstNodesSolution
    : public SolutionBase<Func> {
 public:
  MinimumDistanceBetweenBstNodesSolution();

  int minDiffInBST(TreeNode* root);
};

}  // namespace problem_783
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_BST_NODES_H__

#ifndef LEETCODE_PROBLEMS_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H_
#define LEETCODE_PROBLEMS_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H_

#include "leetcode/core.h"

namespace leetcode::problem_863 {

using Func = std::function<std::vector<int>(TreeNode*, TreeNode*, int)>;

class AllNodesDistanceKInBinaryTreeSolution : public SolutionBase<Func> {
 public:
  AllNodesDistanceKInBinaryTreeSolution();

  std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k);
};

}  // namespace leetcode::problem_863

#endif  // LEETCODE_PROBLEMS_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_H_

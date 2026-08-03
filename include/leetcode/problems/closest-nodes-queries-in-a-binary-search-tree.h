#ifndef LEETCODE_PROBLEMS_CLOSEST_NODES_QUERIES_IN_A_BINARY_SEARCH_TREE_H__
#define LEETCODE_PROBLEMS_CLOSEST_NODES_QUERIES_IN_A_BINARY_SEARCH_TREE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2476 {

using Func =
    std::function<std::vector<std::vector<int>>(TreeNode*, std::vector<int>&)>;

class ClosestNodesQueriesInABinarySearchTreeSolution : public SolutionBase<Func> {
 public:
  // The original problem method.
  std::vector<std::vector<int>> closestNodes(TreeNode* root,
                                              std::vector<int>& queries);

  ClosestNodesQueriesInABinarySearchTreeSolution();
};

}  // namespace problem_2476
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CLOSEST_NODES_QUERIES_IN_A_BINARY_SEARCH_TREE_H__

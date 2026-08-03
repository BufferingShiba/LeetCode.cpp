#ifndef LEETCODE_PROBLEMS_DELETE_NODES_AND_RETURN_FOREST_H_
#define LEETCODE_PROBLEMS_DELETE_NODES_AND_RETURN_FOREST_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1110 {

using Func = std::function<std::vector<TreeNode*>(TreeNode*, std::vector<int>&)>;

class DeleteNodesAndReturnForestSolution : public SolutionBase<Func> {
 public:
  std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete);

  DeleteNodesAndReturnForestSolution();
};

}  // namespace problem_1110
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DELETE_NODES_AND_RETURN_FOREST_H_

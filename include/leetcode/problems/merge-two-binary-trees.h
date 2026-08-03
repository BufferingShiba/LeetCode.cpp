#ifndef LEETCODE_PROBLEMS_MERGE_TWO_BINARY_TREES_H_
#define LEETCODE_PROBLEMS_MERGE_TWO_BINARY_TREES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_617 {

using Func = std::function<TreeNode*(TreeNode*, TreeNode*)>;

class MergeTwoBinaryTreesSolution : public SolutionBase<Func> {
 public:
  MergeTwoBinaryTreesSolution();

  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);
};

}  // namespace problem_617
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_TWO_BINARY_TREES_H_

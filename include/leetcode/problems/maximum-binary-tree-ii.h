#include "leetcode/core.h"

namespace leetcode {
namespace problem_998 {

using Func = std::function<TreeNode*(TreeNode*, int)>;

class MaximumBinaryTreeIiSolution : public SolutionBase<Func> {
 public:
  //! 998. Maximum Binary Tree II
  //! https://leetcode.com/problems/maximum-binary-tree-ii/
  TreeNode* insertIntoMaxTree(TreeNode* root, int val);

  MaximumBinaryTreeIiSolution();
};

}  // namespace problem_998
}  // namespace leetcode

#include "leetcode/core.h"

namespace leetcode {
namespace problem_606 {

using Func = std::function<string(TreeNode*)>;

class ConstructStringFromBinaryTreeSolution : public SolutionBase<Func> {
 public:
  //! 606. Construct String from Binary Tree
  //! https://leetcode.com/problems/construct-string-from-binary-tree/
  string tree2str(TreeNode* root);

  ConstructStringFromBinaryTreeSolution();
};

}  // namespace problem_606
}  // namespace leetcode

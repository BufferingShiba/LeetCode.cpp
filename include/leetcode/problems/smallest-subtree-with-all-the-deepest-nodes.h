#include "leetcode/core.h"

namespace leetcode {
namespace problem_865 {

using Func = std::function<TreeNode*(TreeNode*)>;

class SmallestSubtreeWithAllTheDeepestNodesSolution : public SolutionBase<Func> {
 public:
  //! 865. Smallest Subtree with all the Deepest Nodes
  //! https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
  TreeNode* subtreeWithAllDeepest(TreeNode* root);

  SmallestSubtreeWithAllTheDeepestNodesSolution();
};

}  // namespace problem_865
}  // namespace leetcode
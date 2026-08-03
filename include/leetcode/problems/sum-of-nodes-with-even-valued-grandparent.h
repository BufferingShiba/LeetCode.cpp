#include "leetcode/core.h"

namespace leetcode {
namespace problem_1315 {

using Func = std::function<int(TreeNode*)>;

class SumOfNodesWithEvenValuedGrandparentSolution : public SolutionBase<Func> {
 public:
  //! 1315. Sum of Nodes with Even-Valued Grandparent
  //! https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
  int sumEvenGrandparent(TreeNode* root);

  SumOfNodesWithEvenValuedGrandparentSolution();
};

}  // namespace problem_1315
}  // namespace leetcode

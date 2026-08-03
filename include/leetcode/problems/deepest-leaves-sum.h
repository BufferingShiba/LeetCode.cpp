#include "leetcode/core.h"

namespace leetcode {
namespace problem_1302 {

using Func = std::function<int(TreeNode*)>;

class DeepestLeavesSumSolution : public SolutionBase<Func> {
 public:
  //! 1302. Deepest Leaves Sum
  //! https://leetcode.com/problems/deepest-leaves-sum/
  int deepestLeavesSum(TreeNode* root);

  DeepestLeavesSumSolution();
};

}  // namespace problem_1302
}  // namespace leetcode

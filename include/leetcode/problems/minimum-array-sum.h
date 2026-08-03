#include "leetcode/core.h"

namespace leetcode {
namespace problem_3366 {

using Func = std::function<int(std::vector<int>&, int, int, int)>;

class MinimumArraySumSolution : public SolutionBase<Func> {
 public:
  //! 3366. Minimum Array Sum
  //! https://leetcode.com/problems/minimum-array-sum/
  int minArraySum(std::vector<int>& nums, int k, int op1, int op2);

  MinimumArraySumSolution();
};

}  // namespace problem_3366
}  // namespace leetcode

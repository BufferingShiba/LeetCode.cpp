
#include "leetcode/core.h"

namespace leetcode {
namespace problem_1877 {

using Func = std::function<int(vector<int>&)>;

class MinimizeMaximumPairSumInArraySolution : public SolutionBase<Func> {
 public:
  //! 1877. Minimize Maximum Pair Sum in Array
  //! https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
  int minPairSum(vector<int>& nums);

  MinimizeMaximumPairSumInArraySolution();
};

}  // namespace problem_1877
}  // namespace leetcode
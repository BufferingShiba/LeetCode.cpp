#include "leetcode/core.h"

namespace leetcode {
namespace problem_2817 {

using Func = std::function<int(vector<int>&, int)>;

class MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution : public SolutionBase<Func> {
 public:
  //! 2817. Minimum Absolute Difference Between Elements With Constraint
  //! https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/
  int minAbsoluteDifference(vector<int>& nums, int x);

  MinimumAbsoluteDifferenceBetweenElementsWithConstraintSolution();
};

}  // namespace problem_2817
}  // namespace leetcode

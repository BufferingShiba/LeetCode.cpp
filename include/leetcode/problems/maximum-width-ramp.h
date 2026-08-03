#include "leetcode/core.h"

namespace leetcode {
namespace problem_962 {

using Func = std::function<int(vector<int>&)>;

class MaximumWidthRampSolution : public SolutionBase<Func> {
 public:
  //! 962. Maximum Width Ramp
  //! https://leetcode.com/problems/maximum-width-ramp/
  int maxWidthRamp(vector<int>& nums);

  MaximumWidthRampSolution();
};

}  // namespace problem_962
}  // namespace leetcode

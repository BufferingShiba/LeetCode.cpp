#include "leetcode/core.h"

namespace leetcode {
namespace problem_795 {

using Func = std::function<int(vector<int>&, int, int)>;

class NumberOfSubarraysWithBoundedMaximumSolution : public SolutionBase<Func> {
 public:
  //! 795. Number of Subarrays with Bounded Maximum
  //! https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right);

  NumberOfSubarraysWithBoundedMaximumSolution();
};

}  // namespace problem_795
}  // namespace leetcode

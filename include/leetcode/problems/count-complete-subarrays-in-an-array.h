#include "leetcode/core.h"

namespace leetcode {
namespace problem_2799 {

using Func = std::function<int(vector<int>&)>;

class CountCompleteSubarraysInAnArraySolution : public SolutionBase<Func> {
 public:
  //! 2799. Count Complete Subarrays in an Array
  //! https://leetcode.com/problems/count-complete-subarrays-in-an-array/
  int countCompleteSubarrays(vector<int>& nums);

  CountCompleteSubarraysInAnArraySolution();
};

}  // namespace problem_2799
}  // namespace leetcode

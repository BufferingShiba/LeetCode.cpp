#include "leetcode/core.h"

namespace leetcode {
namespace problem_3728 {

using Func = std::function<long long(vector<int>&)>;

class StableSubarraysWithEqualBoundaryAndInteriorSumSolution : public SolutionBase<Func> {
 public:
  //! 3728. Stable Subarrays With Equal Boundary and Interior Sum
  //! https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/
  long long countStableSubarrays(vector<int>& capacity);

  StableSubarraysWithEqualBoundaryAndInteriorSumSolution();
};

}  // namespace problem_3728
}  // namespace leetcode

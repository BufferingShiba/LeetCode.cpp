#include "leetcode/core.h"

namespace leetcode {
namespace problem_581 {

using Func = std::function<int(vector<int>&)>;

class ShortestUnsortedContinuousSubarraySolution : public SolutionBase<Func> {
 public:
  //! 581. Shortest Unsorted Continuous Subarray
  //! https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
  int findUnsortedSubarray(vector<int>& nums);

  ShortestUnsortedContinuousSubarraySolution();
};

}  // namespace problem_581
}  // namespace leetcode

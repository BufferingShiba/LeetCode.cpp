#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INCREMOVABLE_SUBARRAYS_I_H
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INCREMOVABLE_SUBARRAYS_I_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2970 {

using Func = std::function<int(std::vector<int>&)>;

class CountTheNumberOfIncremovableSubarraysISolution : public SolutionBase<Func> {
 public:
  int incremovableSubarrayCount(std::vector<int>& nums);
  CountTheNumberOfIncremovableSubarraysISolution();
};

}  // namespace problem_2970
}  // namespace leetcode

#endif

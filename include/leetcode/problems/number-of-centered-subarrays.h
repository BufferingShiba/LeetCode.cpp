#ifndef LEETCODE_NUMBER_OF_CENTERED_SUBARRAYS_H__
#define LEETCODE_NUMBER_OF_CENTERED_SUBARRAYS_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3804 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfCenteredSubarraysSolution : public SolutionBase<Func> {
 public:
  NumberOfCenteredSubarraysSolution();

  int centeredSubarrays(std::vector<int>& nums);
};

}  // namespace problem_3804
}  // namespace leetcode

#endif  // LEETCODE_NUMBER_OF_CENTERED_SUBARRAYS_H__

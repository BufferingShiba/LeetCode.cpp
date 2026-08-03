#ifndef LEETCODE_PROBLEMS_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2348 {

using Func = std::function<long long(std::vector<int>&)>;

class NumberOfZeroFilledSubarraysSolution
    : public SolutionBase<Func> {
 public:
  NumberOfZeroFilledSubarraysSolution();

  long long zeroFilledSubarray(std::vector<int>& nums);
};

}  // namespace problem_2348
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H__

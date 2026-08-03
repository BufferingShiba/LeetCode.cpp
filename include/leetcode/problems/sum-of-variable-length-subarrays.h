#ifndef LEETCODE_PROBLEMS_SUM_OF_VARIABLE_LENGTH_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_SUM_OF_VARIABLE_LENGTH_SUBARRAYS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3427 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfVariableLengthSubarraysSolution : public SolutionBase<Func> {
 public:
  SumOfVariableLengthSubarraysSolution();

  int subarraySum(std::vector<int>& nums);
};

}  // namespace problem_3427
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_VARIABLE_LENGTH_SUBARRAYS_H_

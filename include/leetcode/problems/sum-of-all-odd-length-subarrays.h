#ifndef LEETCODE_PROBLEMS_SUM_OF_ALL_ODD_LENGTH_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_SUM_OF_ALL_ODD_LENGTH_SUBARRAYS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1588 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfAllOddLengthSubarraysSolution : public SolutionBase<Func> {
 public:
  SumOfAllOddLengthSubarraysSolution();

  int sumOddLengthSubarrays(std::vector<int>& arr);
};

}  // namespace problem_1588
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_ALL_ODD_LENGTH_SUBARRAYS_H_

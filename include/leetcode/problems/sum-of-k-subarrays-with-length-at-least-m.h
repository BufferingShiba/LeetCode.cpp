#ifndef LEETCODE_PROBLEMS_SUM_OF_K_SUBARRAYS_WITH_LENGTH_AT_LEAST_M_H__
#define LEETCODE_PROBLEMS_SUM_OF_K_SUBARRAYS_WITH_LENGTH_AT_LEAST_M_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3473 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class SumOfKSubarraysWithLengthAtLeastMSolution
    : public SolutionBase<Func> {
 public:
  SumOfKSubarraysWithLengthAtLeastMSolution();

  int maxSum(std::vector<int>& nums, int k, int m);
};

}  // namespace problem_3473
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_K_SUBARRAYS_WITH_LENGTH_AT_LEAST_M_H__

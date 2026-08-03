#ifndef LEETCODE_PROBLEMS_COUNT_PRIME_GAP_BALANCED_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_COUNT_PRIME_GAP_BALANCED_SUBARRAYS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3589 {

using Func = std::function<int(std::vector<int>&, int)>;

class CountPrimeGapBalancedSubarraysSolution : public SolutionBase<Func> {
 public:
  CountPrimeGapBalancedSubarraysSolution();

  int primeSubarray(std::vector<int>& nums, int k);
};

}  // namespace problem_3589
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_PRIME_GAP_BALANCED_SUBARRAYS_H_

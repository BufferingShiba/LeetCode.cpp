#ifndef LEETCODE_PROBLEMS_SMALLEST_SUBARRAYS_WITH_MAXIMUM_BITWISE_OR_H__
#define LEETCODE_PROBLEMS_SMALLEST_SUBARRAYS_WITH_MAXIMUM_BITWISE_OR_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2411 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SmallestSubarraysWithMaximumBitwiseOrSolution
    : public SolutionBase<Func> {
 public:
  SmallestSubarraysWithMaximumBitwiseOrSolution();

  std::vector<int> smallestSubarrays(std::vector<int>& nums);
};

}  // namespace problem_2411
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_SUBARRAYS_WITH_MAXIMUM_BITWISE_OR_H__

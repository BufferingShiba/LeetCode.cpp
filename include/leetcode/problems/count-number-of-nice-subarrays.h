#ifndef LEETCODE_PROBLEMS_COUNT_NUMBER_OF_NICE_SUBARRAYS_H__
#define LEETCODE_PROBLEMS_COUNT_NUMBER_OF_NICE_SUBARRAYS_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1248 {

using Func = std::function<int(std::vector<int>&, int)>;

class CountNumberOfNiceSubarraysSolution : public SolutionBase<Func> {
 public:
  CountNumberOfNiceSubarraysSolution();

  int numberOfSubarrays(std::vector<int>& nums, int k);
};

}  // namespace problem_1248
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBER_OF_NICE_SUBARRAYS_H__

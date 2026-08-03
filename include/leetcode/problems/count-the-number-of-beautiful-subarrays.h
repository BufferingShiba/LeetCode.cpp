#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_BEAUTIFUL_SUBARRAYS_H_
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_BEAUTIFUL_SUBARRAYS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2588 {

using Func = std::function<long long(std::vector<int>&)>;

class CountTheNumberOfBeautifulSubarraysSolution : public SolutionBase<Func> {
 public:
  CountTheNumberOfBeautifulSubarraysSolution();

  long long beautifulSubarrays(std::vector<int>& nums);
};

}  // namespace problem_2588
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_BEAUTIFUL_SUBARRAYS_H_

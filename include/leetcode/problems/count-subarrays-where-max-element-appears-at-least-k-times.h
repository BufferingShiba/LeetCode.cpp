#ifndef LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WHERE_MAX_ELEMENT_APPEARS_AT_LEAST_K_TIMES_H__
#define LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WHERE_MAX_ELEMENT_APPEARS_AT_LEAST_K_TIMES_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2962 {

using Func = std::function<long long(std::vector<int>&, int)>;

class CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution
    : public SolutionBase<Func> {
 public:
  CountSubarraysWhereMaxElementAppearsAtLeastKTimesSolution();

  long long countSubarrays(std::vector<int>& nums, int k);
};

}  // namespace problem_2962
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SUBARRAYS_WHERE_MAX_ELEMENT_APPEARS_AT_LEAST_K_TIMES_H__

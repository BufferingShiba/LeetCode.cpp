#ifndef LEETCODE_PROBLEMS_DIVIDE_AN_ARRAY_INTO_SUBARRAYS_WITH_MINIMUM_COST_I_H__
#define LEETCODE_PROBLEMS_DIVIDE_AN_ARRAY_INTO_SUBARRAYS_WITH_MINIMUM_COST_I_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3010 {

using Func = std::function<int(std::vector<int>&)>;

class DivideAnArrayIntoSubarraysWithMinimumCostISolution
    : public SolutionBase<Func> {
 public:
  DivideAnArrayIntoSubarraysWithMinimumCostISolution();

  int minimumCost(std::vector<int>& nums);
};

}  // namespace problem_3010
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIVIDE_AN_ARRAY_INTO_SUBARRAYS_WITH_MINIMUM_COST_I_H__

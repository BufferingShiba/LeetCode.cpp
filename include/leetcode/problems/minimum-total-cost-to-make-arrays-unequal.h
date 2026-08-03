#ifndef LEETCODE_PROBLEMS_MINIMUM_TOTAL_COST_TO_MAKE_ARRAYS_UNEQUAL_H_
#define LEETCODE_PROBLEMS_MINIMUM_TOTAL_COST_TO_MAKE_ARRAYS_UNEQUAL_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2499 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&)>;

class MinimumTotalCostToMakeArraysUnequalSolution
    : public SolutionBase<Func> {
 public:
  MinimumTotalCostToMakeArraysUnequalSolution();
};

}  // namespace problem_2499
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_TOTAL_COST_TO_MAKE_ARRAYS_UNEQUAL_H_

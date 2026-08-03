#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_THE_ARRAY_INCREASING_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_THE_ARRAY_INCREASING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1827 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumOperationsToMakeTheArrayIncreasingSolution
    : public SolutionBase<Func> {
 public:
  int minOperations(std::vector<int>& nums);
  MinimumOperationsToMakeTheArrayIncreasingSolution();
};

}  // namespace leetcode::problem_1827

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_THE_ARRAY_INCREASING_H__

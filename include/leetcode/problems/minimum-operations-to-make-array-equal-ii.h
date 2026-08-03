#ifndef LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_EQUAL_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_EQUAL_II_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_2541 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, int)>;

class MinimumOperationsToMakeArrayEqualIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumOperationsToMakeArrayEqualIiSolution();
  long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2,
                          int k);
};

}  // namespace leetcode::problem_2541

#endif  // LEETCODE_PROBLEMS_MINIMUM_OPERATIONS_TO_MAKE_ARRAY_EQUAL_II_H__

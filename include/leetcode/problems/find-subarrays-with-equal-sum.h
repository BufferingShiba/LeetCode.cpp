#ifndef LEETCODE_PROBLEMS_FIND_SUBARRAYS_WITH_EQUAL_SUM_H__
#define LEETCODE_PROBLEMS_FIND_SUBARRAYS_WITH_EQUAL_SUM_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2395 {

using Func = std::function<bool(std::vector<int>&)>;

class FindSubarraysWithEqualSumSolution
    : public SolutionBase<Func> {
 public:
  FindSubarraysWithEqualSumSolution();

  bool findSubarrays(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2395

#endif  // LEETCODE_PROBLEMS_FIND_SUBARRAYS_WITH_EQUAL_SUM_H__

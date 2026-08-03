#ifndef LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAYS_IDENTICAL_H__
#define LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAYS_IDENTICAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3424 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, long long)>;

class MinimumCostToMakeArraysIdenticalSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToMakeArraysIdenticalSolution();

  long long minCost(std::vector<int>& arr, std::vector<int>& brr, long long k);
};

}  // namespace problem_3424
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_COST_TO_MAKE_ARRAYS_IDENTICAL_H__

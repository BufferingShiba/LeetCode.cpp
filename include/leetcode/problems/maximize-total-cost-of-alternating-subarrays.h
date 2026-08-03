#ifndef LEETCODE_PROBLEM_3196_H
#define LEETCODE_PROBLEM_3196_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3196 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximizeTotalCostOfAlternatingSubarraysSolution : public SolutionBase<Func> {
 public:
  MaximizeTotalCostOfAlternatingSubarraysSolution();

  long long maximumTotalCost(std::vector<int>& nums);
};

}  // namespace problem_3196
}  // namespace leetcode

#endif

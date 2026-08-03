#ifndef LEETCODE_PROBLEMS_SUM_OF_ELEMENTS_WITH_FREQUENCY_DIVISIBLE_BY_K_H__
#define LEETCODE_PROBLEMS_SUM_OF_ELEMENTS_WITH_FREQUENCY_DIVISIBLE_BY_K_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3712 {

using Func = std::function<int(std::vector<int>&, int)>;

class SumOfElementsWithFrequencyDivisibleByKSolution
    : public SolutionBase<Func> {
 public:
  SumOfElementsWithFrequencyDivisibleByKSolution();

  int sumDivisibleByK(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3712

#endif  // LEETCODE_PROBLEMS_SUM_OF_ELEMENTS_WITH_FREQUENCY_DIVISIBLE_BY_K_H__

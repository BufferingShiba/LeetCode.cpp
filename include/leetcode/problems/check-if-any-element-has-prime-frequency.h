#ifndef LEETCODE_PROBLEMS_CHECK_IF_ANY_ELEMENT_HAS_PRIME_FREQUENCY_H__
#define LEETCODE_PROBLEMS_CHECK_IF_ANY_ELEMENT_HAS_PRIME_FREQUENCY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3591 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfAnyElementHasPrimeFrequencySolution
    : public SolutionBase<Func> {
 public:
  CheckIfAnyElementHasPrimeFrequencySolution();

  bool checkPrimeFrequency(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3591

#endif  // LEETCODE_PROBLEMS_CHECK_IF_ANY_ELEMENT_HAS_PRIME_FREQUENCY_H__

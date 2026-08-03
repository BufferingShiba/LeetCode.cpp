#ifndef LEETCODE_PROBLEMS_SUM_OF_IMBALANCE_NUMBERS_OF_ALL_SUBARRAYS_H__
#define LEETCODE_PROBLEMS_SUM_OF_IMBALANCE_NUMBERS_OF_ALL_SUBARRAYS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2763 {

using Func = std::function<int(std::vector<int>&)>;

class SumOfImbalanceNumbersOfAllSubarraysSolution : public SolutionBase<Func> {
 public:
  SumOfImbalanceNumbersOfAllSubarraysSolution();

  int sumImbalanceNumbers(std::vector<int>& nums);
};

}  // namespace problem_2763
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SUM_OF_IMBALANCE_NUMBERS_OF_ALL_SUBARRAYS_H__

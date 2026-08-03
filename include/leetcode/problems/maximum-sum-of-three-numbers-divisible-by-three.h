#ifndef LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_THREE_NUMBERS_DIVISIBLE_BY_THREE_H_
#define LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_THREE_NUMBERS_DIVISIBLE_BY_THREE_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3780 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumSumOfThreeNumbersDivisibleByThreeSolution
    : public SolutionBase<Func> {
 public:
  MaximumSumOfThreeNumbersDivisibleByThreeSolution();

  int maximumSum(std::vector<int>& nums);
};

}  // namespace problem_3780
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_SUM_OF_THREE_NUMBERS_DIVISIBLE_BY_THREE_H_

#ifndef LEETCODE_PROBLEMS_SMALLEST_MISSING_INTEGER_GREATER_THAN_SEQUENTIAL_PREFIX_SUM_H__
#define LEETCODE_PROBLEMS_SMALLEST_MISSING_INTEGER_GREATER_THAN_SEQUENTIAL_PREFIX_SUM_H__

#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_2996 {

using Func = std::function<int(std::vector<int>&)>;

class SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution
    : public SolutionBase<Func> {
 public:
  SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution();

  int missingInteger(std::vector<int>& nums);
};

}  // namespace problem_2996
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_MISSING_INTEGER_GREATER_THAN_SEQUENTIAL_PREFIX_SUM_H__

#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_PAIRS_IN_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_PAIRS_IN_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2341 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class MaximumNumberOfPairsInArraySolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfPairsInArraySolution();

  std::vector<int> numberOfPairs(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2341

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_PAIRS_IN_ARRAY_H__

#ifndef LEETCODE_PROBLEMS_MAXIMUM_XOR_OF_TWO_NUMBERS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_XOR_OF_TWO_NUMBERS_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_421 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumXorOfTwoNumbersInAnArraySolution
    : public SolutionBase<Func> {
 public:
  MaximumXorOfTwoNumbersInAnArraySolution();

  int findMaximumXOR(std::vector<int>& nums);
};

}  // namespace leetcode::problem_421

#endif  // LEETCODE_PROBLEMS_MAXIMUM_XOR_OF_TWO_NUMBERS_IN_AN_ARRAY_H__

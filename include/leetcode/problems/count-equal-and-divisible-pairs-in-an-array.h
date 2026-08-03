#ifndef LEETCODE_PROBLEMS_COUNT_EQUAL_AND_DIVISIBLE_PAIRS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_COUNT_EQUAL_AND_DIVISIBLE_PAIRS_IN_AN_ARRAY_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2176 {

using Func = std::function<int(std::vector<int>&, int)>;

class CountEqualAndDivisiblePairsInAnArraySolution
    : public SolutionBase<Func> {
 public:
  int countPairs(std::vector<int>& nums, int k);
  CountEqualAndDivisiblePairsInAnArraySolution();
};

}  // namespace problem_2176
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_EQUAL_AND_DIVISIBLE_PAIRS_IN_AN_ARRAY_H__

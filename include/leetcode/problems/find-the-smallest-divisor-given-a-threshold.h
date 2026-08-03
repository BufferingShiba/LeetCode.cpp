#ifndef LEETCODE_PROBLEMS_FIND_THE_SMALLEST_DIVISOR_GIVEN_A_THRESHOLD_H_
#define LEETCODE_PROBLEMS_FIND_THE_SMALLEST_DIVISOR_GIVEN_A_THRESHOLD_H_

#include "leetcode/core.h"

namespace leetcode::problem_1283 {

using Func = std::function<int(std::vector<int>&, int)>;

class FindTheSmallestDivisorGivenAThresholdSolution : public SolutionBase<Func> {
 public:
  FindTheSmallestDivisorGivenAThresholdSolution();

  int smallestDivisor(std::vector<int>& nums, int threshold);
};

}  // namespace leetcode::problem_1283

#endif  // LEETCODE_PROBLEMS_FIND_THE_SMALLEST_DIVISOR_GIVEN_A_THRESHOLD_H_

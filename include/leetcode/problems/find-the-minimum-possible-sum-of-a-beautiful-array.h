#ifndef LEETCODE_PROBLEMS_FIND_THE_MINIMUM_POSSIBLE_SUM_OF_A_BEAUTIFUL_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_THE_MINIMUM_POSSIBLE_SUM_OF_A_BEAUTIFUL_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode::problem_2834 {

using Func = std::function<int(int, int)>;

class FindTheMinimumPossibleSumOfABeautifulArraySolution : public SolutionBase<Func> {
 public:
  FindTheMinimumPossibleSumOfABeautifulArraySolution();

  int minimumPossibleSum(int n, int target);
};

}  // namespace leetcode::problem_2834

#endif  // LEETCODE_PROBLEMS_FIND_THE_MINIMUM_POSSIBLE_SUM_OF_A_BEAUTIFUL_ARRAY_H_

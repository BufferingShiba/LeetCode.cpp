// Find the Maximum Achievable Number
// Problem: https://leetcode.com/problems/find-the-maximum-achievable-number/

#ifndef LEETCODE_PROBLEMS_2769_FIND_THE_MAXIMUM_ACHIEVABLE_NUMBER_H_
#define LEETCODE_PROBLEMS_2769_FIND_THE_MAXIMUM_ACHIEVABLE_NUMBER_H_

#include "leetcode/core.h"

#include <functional>

namespace leetcode::problem_2769 {

using Func = std::function<int(int num, int t)>;

class FindTheMaximumAchievableNumberSolution
    : public SolutionBase<Func> {
 public:
  FindTheMaximumAchievableNumberSolution();

  int theMaximumAchievableX(int num, int t);
};

}  // namespace leetcode::problem_2769

#endif  // LEETCODE_PROBLEMS_2769_FIND_THE_MAXIMUM_ACHIEVABLE_NUMBER_H_

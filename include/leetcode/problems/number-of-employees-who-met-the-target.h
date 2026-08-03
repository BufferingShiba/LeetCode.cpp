#ifndef LEETCODE_PROBLEMS_NUMBER_OF_EMPLOYEES_WHO_MET_THE_TARGET_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_EMPLOYEES_WHO_MET_THE_TARGET_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2798 {

using Func = std::function<int(std::vector<int>&, int)>;

class NumberOfEmployeesWhoMetTheTargetSolution
    : public SolutionBase<Func> {
 public:
  NumberOfEmployeesWhoMetTheTargetSolution();
  int numberOfEmployeesWhoMetTarget(std::vector<int>& hours, int target);
};

}  // namespace leetcode::problem_2798

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_EMPLOYEES_WHO_MET_THE_TARGET_H__

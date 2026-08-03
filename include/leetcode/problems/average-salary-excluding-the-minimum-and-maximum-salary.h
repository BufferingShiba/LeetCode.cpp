#ifndef LEETCODE_PROBLEMS_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H__
#define LEETCODE_PROBLEMS_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1491 {

using Func = std::function<double(std::vector<int>&)>;

class AverageSalaryExcludingTheMinimumAndMaximumSalarySolution
    : public SolutionBase<Func> {
 public:
  AverageSalaryExcludingTheMinimumAndMaximumSalarySolution();

  double average(std::vector<int>& salary);
};

}  // namespace leetcode::problem_1491

#endif  // LEETCODE_PROBLEMS_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H__

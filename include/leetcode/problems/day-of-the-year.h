#ifndef LEETCODE_PROBLEMS_DAY_OF_THE_YEAR_H_
#define LEETCODE_PROBLEMS_DAY_OF_THE_YEAR_H_

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_1154 {

using Func = std::function<int(std::string)>;

class DayOfTheYearSolution : public SolutionBase<Func> {
 public:
  DayOfTheYearSolution();
  int dayOfYear(std::string date);
};

}  // namespace leetcode::problem_1154

#endif  // LEETCODE_PROBLEMS_DAY_OF_THE_YEAR_H_

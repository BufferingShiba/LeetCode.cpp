#ifndef LEETCODE_PROBLEMS_DAY_OF_THE_WEEK_H__
#define LEETCODE_PROBLEMS_DAY_OF_THE_WEEK_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1185 {

using Func = std::function<std::string(int, int, int)>;

class DayOfTheWeekSolution : public SolutionBase<Func> {
 public:
  DayOfTheWeekSolution();

  std::string dayOfTheWeek(int day, int month, int year);
};

}  // namespace leetcode::problem_1185

#endif  // LEETCODE_PROBLEMS_DAY_OF_THE_WEEK_H__

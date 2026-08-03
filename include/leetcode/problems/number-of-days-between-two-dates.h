#ifndef LEETCODE_PROBLEMS_NUMBER_OF_DAYS_BETWEEN_TWO_DATES_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_DAYS_BETWEEN_TWO_DATES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_1360 {

using Func = std::function<int(std::string, std::string)>;

class NumberOfDaysBetweenTwoDatesSolution
    : public SolutionBase<Func> {
 public:
  NumberOfDaysBetweenTwoDatesSolution();

  int daysBetweenDates(std::string date1, std::string date2);
};

}  // namespace problem_1360
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_DAYS_BETWEEN_TWO_DATES_H__

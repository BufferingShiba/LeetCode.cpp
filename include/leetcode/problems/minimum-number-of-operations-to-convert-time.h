#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_CONVERT_TIME_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_CONVERT_TIME_H_

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2224 {

using Func = std::function<int(std::string, std::string)>;

class MinimumNumberOfOperationsToConvertTimeSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfOperationsToConvertTimeSolution();

  int convertTime(std::string current, std::string correct);
};

}  // namespace problem_2224
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_OPERATIONS_TO_CONVERT_TIME_H_

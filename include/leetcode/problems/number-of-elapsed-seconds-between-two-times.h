#ifndef LEETCODE_PROBLEMS_NUMBER_OF_ELAPSED_SECONDS_BETWEEN_TWO_TIMES_H_
#define LEETCODE_PROBLEMS_NUMBER_OF_ELAPSED_SECONDS_BETWEEN_TWO_TIMES_H_

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_3986 {

using Func = std::function<int(std::string, std::string)>;

class NumberOfElapsedSecondsBetweenTwoTimesSolution
    : public SolutionBase<Func> {
 public:
  NumberOfElapsedSecondsBetweenTwoTimesSolution();

  int secondsBetweenTimes(std::string startTime, std::string endTime);
};

}  // namespace leetcode::problem_3986

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_ELAPSED_SECONDS_BETWEEN_TWO_TIMES_H_

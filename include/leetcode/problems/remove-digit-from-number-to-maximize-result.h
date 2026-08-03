#ifndef LEETCODE_PROBLEMS_REMOVE_DIGIT_FROM_NUMBER_TO_MAXIMIZE_RESULT_H_
#define LEETCODE_PROBLEMS_REMOVE_DIGIT_FROM_NUMBER_TO_MAXIMIZE_RESULT_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2259 {

using Func = std::function<std::string(std::string, char)>;

class RemoveDigitFromNumberToMaximizeResultSolution : public SolutionBase<Func> {
 public:
  RemoveDigitFromNumberToMaximizeResultSolution();

  std::string removeDigit(std::string number, char digit);
};

}  // namespace problem_2259
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_DIGIT_FROM_NUMBER_TO_MAXIMIZE_RESULT_H_

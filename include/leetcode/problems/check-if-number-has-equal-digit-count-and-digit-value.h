#ifndef LEETCODE_PROBLEMS_CHECK_IF_NUMBER_HAS_EQUAL_DIGIT_COUNT_AND_DIGIT_VALUE_H_
#define LEETCODE_PROBLEMS_CHECK_IF_NUMBER_HAS_EQUAL_DIGIT_COUNT_AND_DIGIT_VALUE_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2283 {

using CheckIfNumberHasEqualDigitCountAndDigitValueFunc =
    std::function<bool(std::string)>;

class CheckIfNumberHasEqualDigitCountAndDigitValueSolution
    : public SolutionBase<CheckIfNumberHasEqualDigitCountAndDigitValueFunc> {
 public:
  CheckIfNumberHasEqualDigitCountAndDigitValueSolution();

  bool digitCount(std::string num);
};

}  // namespace problem_2283
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_NUMBER_HAS_EQUAL_DIGIT_COUNT_AND_DIGIT_VALUE_H_

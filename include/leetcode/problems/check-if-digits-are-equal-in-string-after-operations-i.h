#ifndef LEETCODE_PROBLEMS_CHECK_IF_DIGITS_ARE_EQUAL_IN_STRING_AFTER_OPERATIONS_I_H__
#define LEETCODE_PROBLEMS_CHECK_IF_DIGITS_ARE_EQUAL_IN_STRING_AFTER_OPERATIONS_I_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3461 {

using Func = std::function<bool(std::string)>;

class CheckIfDigitsAreEqualInStringAfterOperationsISolution
    : public SolutionBase<Func> {
 public:
  CheckIfDigitsAreEqualInStringAfterOperationsISolution();

  bool hasSameDigits(std::string s);
};

}  // namespace problem_3461
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_DIGITS_ARE_EQUAL_IN_STRING_AFTER_OPERATIONS_I_H__

#ifndef LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_I_H__
#define LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_I_H__

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode::problem_2839 {

using Func = std::function<bool(std::string, std::string)>;

class CheckIfStringsCanBeMadeEqualWithOperationsISolution
    : public SolutionBase<Func> {
 public:
  CheckIfStringsCanBeMadeEqualWithOperationsISolution();
  bool canBeEqual(std::string s1, std::string s2);
};

}  // namespace leetcode::problem_2839

#endif  // LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_I_H__

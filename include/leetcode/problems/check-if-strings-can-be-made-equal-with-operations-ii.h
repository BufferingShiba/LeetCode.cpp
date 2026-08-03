#ifndef LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_II_H__
#define LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_II_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_2840 {

using Func = std::function<bool(std::string, std::string)>;

class CheckIfStringsCanBeMadeEqualWithOperationsIiSolution
    : public SolutionBase<Func> {
 public:
  CheckIfStringsCanBeMadeEqualWithOperationsIiSolution();
  bool checkStrings(std::string s1, std::string s2);
};

}  // namespace leetcode::problem_2840

#endif  // LEETCODE_PROBLEMS_CHECK_IF_STRINGS_CAN_BE_MADE_EQUAL_WITH_OPERATIONS_II_H__

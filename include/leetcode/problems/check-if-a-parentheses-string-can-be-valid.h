#ifndef LEETCODE_PROBLEMS_CHECK_IF_A_PARENTHESES_STRING_CAN_BE_VALID_H_
#define LEETCODE_PROBLEMS_CHECK_IF_A_PARENTHESES_STRING_CAN_BE_VALID_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2116 {

using Func = std::function<bool(std::string, std::string)>;

class CheckIfAParenthesesStringCanBeValidSolution : public SolutionBase<Func> {
 public:
  CheckIfAParenthesesStringCanBeValidSolution();

  bool canBeValid(std::string s, std::string locked);
};

}  // namespace problem_2116
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_A_PARENTHESES_STRING_CAN_BE_VALID_H_

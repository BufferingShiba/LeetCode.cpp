#ifndef LEETCODE_PROBLEMS_MINIMIZE_RESULT_BY_ADDING_PARENTHESES_TO_EXPRESSION_H__
#define LEETCODE_PROBLEMS_MINIMIZE_RESULT_BY_ADDING_PARENTHESES_TO_EXPRESSION_H__

#include <string>
#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2232 {

using Func = std::function<std::string(std::string)>;

class MinimizeResultByAddingParenthesesToExpressionSolution : public SolutionBase<Func> {
 public:
  MinimizeResultByAddingParenthesesToExpressionSolution();

  std::string minimizeResult(std::string expression);
};

}  // namespace problem_2232
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMIZE_RESULT_BY_ADDING_PARENTHESES_TO_EXPRESSION_H__

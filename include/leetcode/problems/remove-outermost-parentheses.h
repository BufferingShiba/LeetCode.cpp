#ifndef LEETCODE_PROBLEMS_REMOVE_OUTERMOST_PARENTHESES_H_
#define LEETCODE_PROBLEMS_REMOVE_OUTERMOST_PARENTHESES_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1021 {

using Func = std::function<std::string(std::string)>;

class RemoveOutermostParenthesesSolution : public SolutionBase<Func> {
 public:
  RemoveOutermostParenthesesSolution();

  std::string removeOuterParentheses(std::string s);
};

}  // namespace leetcode::problem_1021

#endif  // LEETCODE_PROBLEMS_REMOVE_OUTERMOST_PARENTHESES_H_

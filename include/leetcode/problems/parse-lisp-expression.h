#ifndef LEETCODE_PROBLEMS_PARSE_LISP_EXPRESSION_H
#define LEETCODE_PROBLEMS_PARSE_LISP_EXPRESSION_H

#include "leetcode/core.h"
#include <functional>
#include <string>

namespace leetcode {
namespace problem_736 {

using Func = std::function<int(std::string)>;

class ParseLispExpressionSolution : public SolutionBase<Func> {
 public:
  ParseLispExpressionSolution();

  int evaluate(std::string expression);
};

}  // namespace problem_736
}  // namespace leetcode

#endif

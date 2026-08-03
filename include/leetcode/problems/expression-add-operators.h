#ifndef LEETCODE_PROBLEM_282_EXPRESSION_ADD_OPERATORS_H_
#define LEETCODE_PROBLEM_282_EXPRESSION_ADD_OPERATORS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_282 {

using Func = std::function<std::vector<std::string>(std::string, int)>;

class ExpressionAddOperatorsSolution : public SolutionBase<Func> {
 public:
  ExpressionAddOperatorsSolution();

  std::vector<std::string> addOperators(std::string num, int target);
};

}  // namespace problem_282
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_282_EXPRESSION_ADD_OPERATORS_H_

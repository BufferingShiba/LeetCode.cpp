#ifndef LEETCODE_PROBLEMS_FINAL_VALUE_OF_VARIABLE_AFTER_PERFORMING_OPERATIONS_H__
#define LEETCODE_PROBLEMS_FINAL_VALUE_OF_VARIABLE_AFTER_PERFORMING_OPERATIONS_H__

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2011 {

using Func = std::function<int(std::vector<std::string>&)>;

class FinalValueOfVariableAfterPerformingOperationsSolution
    : public SolutionBase<Func> {
 public:
  FinalValueOfVariableAfterPerformingOperationsSolution();

  int finalValueAfterOperations(std::vector<std::string>& operations);
};

}  // namespace problem_2011
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FINAL_VALUE_OF_VARIABLE_AFTER_PERFORMING_OPERATIONS_H__

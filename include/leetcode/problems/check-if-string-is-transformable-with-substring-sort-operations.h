#ifndef LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_TRANSFORMABLE_WITH_SUBSTRING_SORT_OPERATIONS_H__
#define LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_TRANSFORMABLE_WITH_SUBSTRING_SORT_OPERATIONS_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode::problem_1585 {

using Func = std::function<bool(std::string, std::string)>;

class CheckIfStringIsTransformableWithSubstringSortOperationsSolution
    : public SolutionBase<Func> {
 public:
  bool isTransformable(std::string s, std::string t);

  CheckIfStringIsTransformableWithSubstringSortOperationsSolution();
};

}  // namespace leetcode::problem_1585

#endif  // LEETCODE_PROBLEMS_CHECK_IF_STRING_IS_TRANSFORMABLE_WITH_SUBSTRING_SORT_OPERATIONS_H__

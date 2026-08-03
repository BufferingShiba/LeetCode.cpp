#ifndef LEETCODE_PROBLEMS_SPECIAL_ARRAY_WITH_X_ELEMENTS_GREATER_THAN_OR_EQUAL_X_H__
#define LEETCODE_PROBLEMS_SPECIAL_ARRAY_WITH_X_ELEMENTS_GREATER_THAN_OR_EQUAL_X_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1608 {

using Func = std::function<int(std::vector<int>&)>;

class SpecialArrayWithXElementsGreaterThanOrEqualXSolution
    : public SolutionBase<Func> {
 public:
  SpecialArrayWithXElementsGreaterThanOrEqualXSolution();

  int specialArray(std::vector<int>& nums);
};

}  // namespace problem_1608
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPECIAL_ARRAY_WITH_X_ELEMENTS_GREATER_THAN_OR_EQUAL_X_H__

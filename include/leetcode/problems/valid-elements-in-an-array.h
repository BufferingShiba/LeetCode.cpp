#ifndef LEETCODE_PROBLEMS_VALID_ELEMENTS_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_VALID_ELEMENTS_IN_AN_ARRAY_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_3912 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ValidElementsInAnArraySolution : public SolutionBase<Func> {
 public:
  ValidElementsInAnArraySolution();

  std::vector<int> findValidElements(std::vector<int>& nums);
};

// 兼容公开类名（metadata 指定 solution_class_base）
using ValidElementsInAnArray = ValidElementsInAnArraySolution;

}  // namespace problem_3912
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_ELEMENTS_IN_AN_ARRAY_H__

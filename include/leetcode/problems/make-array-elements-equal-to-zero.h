#ifndef LEETCODE_PROBLEMS_MAKE_ARRAY_ELEMENTS_EQUAL_TO_ZERO_H__
#define LEETCODE_PROBLEMS_MAKE_ARRAY_ELEMENTS_EQUAL_TO_ZERO_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3354 {

using Func = std::function<int(std::vector<int>&)>;

class MakeArrayElementsEqualToZeroSolution
    : public SolutionBase<Func> {
 public:
  MakeArrayElementsEqualToZeroSolution();

  int countValidSelections(std::vector<int>& nums) const {
    return getSolution()(nums);
  }
};

}  // namespace leetcode::problem_3354

#endif  // LEETCODE_PROBLEMS_MAKE_ARRAY_ELEMENTS_EQUAL_TO_ZERO_H__

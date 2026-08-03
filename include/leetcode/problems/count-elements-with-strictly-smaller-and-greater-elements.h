#ifndef LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_STRICTLY_SMALLER_AND_GREATER_ELEMENTS_H__
#define LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_STRICTLY_SMALLER_AND_GREATER_ELEMENTS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2148 {

using Func = std::function<int(std::vector<int>&)>;

class CountElementsWithStrictlySmallerAndGreaterElementsSolution
    : public SolutionBase<Func> {
 public:
  int countElements(std::vector<int>& nums);

  CountElementsWithStrictlySmallerAndGreaterElementsSolution();
};

}  // namespace leetcode::problem_2148

#endif  // LEETCODE_PROBLEMS_COUNT_ELEMENTS_WITH_STRICTLY_SMALLER_AND_GREATER_ELEMENTS_H__

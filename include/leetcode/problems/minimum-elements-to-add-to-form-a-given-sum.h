#ifndef LEETCODE_PROBLEMS_MINIMUM_ELEMENTS_TO_ADD_TO_FORM_A_GIVEN_SUM_H__
#define LEETCODE_PROBLEMS_MINIMUM_ELEMENTS_TO_ADD_TO_FORM_A_GIVEN_SUM_H__

#include "leetcode/core.h"

namespace leetcode::problem_1785 {

int minElementsImpl(std::vector<int>& nums, int limit, int goal);

class MinimumElementsToAddToFormAGivenSumSolution
    : public SolutionBase<std::function<int(std::vector<int>&, int, int)>> {
 public:
  MinimumElementsToAddToFormAGivenSumSolution();

  int minElements(std::vector<int>& nums, int limit, int goal) {
    return getSolution()(nums, limit, goal);
  }
};

}  // namespace leetcode::problem_1785

#endif  // LEETCODE_PROBLEMS_MINIMUM_ELEMENTS_TO_ADD_TO_FORM_A_GIVEN_SUM_H__

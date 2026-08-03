#ifndef LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3423 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution
    : public SolutionBase<Func> {
 public:
  MaximumDifferenceBetweenAdjacentElementsInACircularArraySolution();

  int maxAdjacentDistance(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3423

#endif  // LEETCODE_PROBLEMS_MAXIMUM_DIFFERENCE_BETWEEN_ADJACENT_ELEMENTS_IN_A_CIRCULAR_ARRAY_H__

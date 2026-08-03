#ifndef LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_BETWEEN_LARGEST_AND_SMALLEST_VALUE_IN_THREE_MOVES_H
#define LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_BETWEEN_LARGEST_AND_SMALLEST_VALUE_IN_THREE_MOVES_H

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1509 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution
    : public SolutionBase<Func> {
 public:
  MinimumDifferenceBetweenLargestAndSmallestValueInThreeMovesSolution();

  int minDifference(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1509

#endif  // LEETCODE_PROBLEMS_MINIMUM_DIFFERENCE_BETWEEN_LARGEST_AND_SMALLEST_VALUE_IN_THREE_MOVES_H

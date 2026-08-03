#ifndef LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_II_H__
#define LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_II_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3741 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumDistanceBetweenThreeEqualElementsIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumDistanceBetweenThreeEqualElementsIiSolution();

  int minimumDistance(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3741

#endif  // LEETCODE_PROBLEMS_MINIMUM_DISTANCE_BETWEEN_THREE_EQUAL_ELEMENTS_II_H__

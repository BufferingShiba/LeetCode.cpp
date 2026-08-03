#ifndef LEETCODE_PROBLEMS_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_34 {

using Func = std::function<std::vector<int>(std::vector<int>&, int)>;

class FindFirstAndLastPositionOfElementInSortedArraySolution
    : public SolutionBase<Func> {
 public:
  FindFirstAndLastPositionOfElementInSortedArraySolution();

  std::vector<int> searchRange(std::vector<int>& nums, int target);
};

}  // namespace leetcode::problem_34

#endif  // LEETCODE_PROBLEMS_FIND_FIRST_AND_LAST_POSITION_OF_ELEMENT_IN_SORTED_ARRAY_H__

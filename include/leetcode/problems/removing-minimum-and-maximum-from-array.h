#ifndef LEETCODE_PROBLEMS_REMOVING_MINIMUM_AND_MAXIMUM_FROM_ARRAY_H__
#define LEETCODE_PROBLEMS_REMOVING_MINIMUM_AND_MAXIMUM_FROM_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2091 {

using Func = std::function<int(std::vector<int>&)>;

class RemovingMinimumAndMaximumFromArraySolution
    : public SolutionBase<Func> {
 public:
  RemovingMinimumAndMaximumFromArraySolution();

  int minimumDeletions(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2091

#endif  // LEETCODE_PROBLEMS_REMOVING_MINIMUM_AND_MAXIMUM_FROM_ARRAY_H__

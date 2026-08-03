#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_JUMPS_TO_REACH_THE_LAST_INDEX_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_JUMPS_TO_REACH_THE_LAST_INDEX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2770 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximumNumberOfJumpsToReachTheLastIndexSolution
    : public SolutionBase<Func> {
 public:
  MaximumNumberOfJumpsToReachTheLastIndexSolution();
  int maximumJumps(std::vector<int>& nums, int target);
};

}  // namespace problem_2770
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_JUMPS_TO_REACH_THE_LAST_INDEX_H__

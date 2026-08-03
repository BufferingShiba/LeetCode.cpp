#ifndef LEETCODE_PROBLEMS_FIND_CLOSEST_NUMBER_TO_ZERO_H__
#define LEETCODE_PROBLEMS_FIND_CLOSEST_NUMBER_TO_ZERO_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2239 {

using Func = std::function<int(std::vector<int>&)>;

class FindClosestNumberToZeroSolution
    : public SolutionBase<Func> {
 public:
  FindClosestNumberToZeroSolution();

  int findClosestNumber(std::vector<int>& nums);
};

}  // namespace problem_2239
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_CLOSEST_NUMBER_TO_ZERO_H__

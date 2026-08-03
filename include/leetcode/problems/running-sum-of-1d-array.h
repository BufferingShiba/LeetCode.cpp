#ifndef LEETCODE_PROBLEMS_RUNNING_SUM_OF_1D_ARRAY_H__
#define LEETCODE_PROBLEMS_RUNNING_SUM_OF_1D_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1480 {

using Func =
    std::function<std::vector<int>(std::vector<int>& nums)>;

class RunningSumOf1dArraySolution
    : public SolutionBase<Func> {
 public:
  RunningSumOf1dArraySolution();

  std::vector<int> runningSum(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1480

#endif  // LEETCODE_PROBLEMS_RUNNING_SUM_OF_1D_ARRAY_H__

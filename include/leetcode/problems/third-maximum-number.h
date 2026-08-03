#ifndef LEETCODE_PROBLEMS_THIRD_MAXIMUM_NUMBER_H__
#define LEETCODE_PROBLEMS_THIRD_MAXIMUM_NUMBER_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_414 {

using Func = std::function<int(std::vector<int>&)>;

class ThirdMaximumNumberSolution : public SolutionBase<Func> {
 public:
  ThirdMaximumNumberSolution();

  int thirdMax(std::vector<int>& nums);
};

}  // namespace leetcode::problem_414

#endif  // LEETCODE_PROBLEMS_THIRD_MAXIMUM_NUMBER_H__

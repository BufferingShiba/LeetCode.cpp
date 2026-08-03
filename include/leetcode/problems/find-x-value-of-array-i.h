#ifndef LEETCODE_PROBLEMS_FIND_X_VALUE_OF_ARRAY_I_H__
#define LEETCODE_PROBLEMS_FIND_X_VALUE_OF_ARRAY_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3524 {

using Func = std::function<std::vector<long long>(std::vector<int>&, int)>;

class FindXValueOfArrayISolution : public SolutionBase<Func> {
 public:
  FindXValueOfArrayISolution();

  std::vector<long long> resultArray(std::vector<int>& nums, int k);
};

}  // namespace leetcode::problem_3524

#endif  // LEETCODE_PROBLEMS_FIND_X_VALUE_OF_ARRAY_I_H__

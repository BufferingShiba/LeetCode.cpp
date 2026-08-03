#ifndef LEETCODE_PROBLEM_238_H_
#define LEETCODE_PROBLEM_238_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_238 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ProductOfArrayExceptSelfSolution : public SolutionBase<Func> {
 public:
  ProductOfArrayExceptSelfSolution();

  std::vector<int> productExceptSelf(std::vector<int>& nums);
};

}  // namespace leetcode::problem_238

#endif  // LEETCODE_PROBLEM_238_H_

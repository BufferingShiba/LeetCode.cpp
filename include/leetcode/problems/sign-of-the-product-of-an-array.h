#ifndef LEETCODE_PROBLEM_1822_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H__
#define LEETCODE_PROBLEM_1822_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H__

#include "leetcode/core.h"

namespace leetcode::problem_1822 {

using Func = std::function<int(std::vector<int>&)>;

class SignOfTheProductOfAnArraySolution : public SolutionBase<Func> {
 public:
  int arraySign(std::vector<int>& nums);
  SignOfTheProductOfAnArraySolution();
};

}  // namespace leetcode::problem_1822

#endif  // LEETCODE_PROBLEM_1822_SIGN_OF_THE_PRODUCT_OF_AN_ARRAY_H__

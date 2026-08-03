#ifndef LEETCODE_PROBLEMS_REPLACE_NON_COPRIME_NUMBERS_IN_ARRAY_H_
#define LEETCODE_PROBLEMS_REPLACE_NON_COPRIME_NUMBERS_IN_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode::problem_2197 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ReplaceNonCoprimeNumbersInArraySolution : public SolutionBase<Func> {
 public:
  ReplaceNonCoprimeNumbersInArraySolution();

  std::vector<int> replaceNonCoprimes(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2197

#endif  // LEETCODE_PROBLEMS_REPLACE_NON_COPRIME_NUMBERS_IN_ARRAY_H_

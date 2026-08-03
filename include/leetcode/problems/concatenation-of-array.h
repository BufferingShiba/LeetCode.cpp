#ifndef LEETCODE_PROBLEM_1929_CONCATENATION_OF_ARRAY_H_
#define LEETCODE_PROBLEM_1929_CONCATENATION_OF_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode::problem_1929 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ConcatenationOfArraySolution : public SolutionBase<Func> {
 public:
  ConcatenationOfArraySolution();
  std::vector<int> getConcatenation(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1929

#endif  // LEETCODE_PROBLEM_1929_CONCATENATION_OF_ARRAY_H_

#ifndef LEETCODE_PROBLEM_3925_H_
#define LEETCODE_PROBLEM_3925_H_

#include "leetcode/core.h"

namespace leetcode::problem_3925 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class ConcatenateArrayWithReverseSolution : public SolutionBase<Func> {
 public:
  ConcatenateArrayWithReverseSolution();

  std::vector<int> concatWithReverse(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3925

#endif  // LEETCODE_PROBLEM_3925_H_

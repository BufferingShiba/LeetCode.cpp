#ifndef LEETCODE_PROBLEMS_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H_
#define LEETCODE_PROBLEMS_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H_

#include "leetcode/core.h"

namespace leetcode::problem_2007 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindOriginalArrayFromDoubledArraySolution : public SolutionBase<Func> {
 public:
  FindOriginalArrayFromDoubledArraySolution();

  std::vector<int> findOriginalArray(std::vector<int>& changed);
};

}  // namespace leetcode::problem_2007

#endif  // LEETCODE_PROBLEMS_FIND_ORIGINAL_ARRAY_FROM_DOUBLED_ARRAY_H_

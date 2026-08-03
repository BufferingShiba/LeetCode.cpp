#ifndef LEETCODE_PROBLEMS_FIND_THE_MIDDLE_INDEX_IN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_THE_MIDDLE_INDEX_IN_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1991 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheMiddleIndexInArraySolution : public SolutionBase<Func> {
 public:
  FindTheMiddleIndexInArraySolution();

  int findMiddleIndex(std::vector<int>& nums);
};

}  // namespace leetcode::problem_1991

#endif  // LEETCODE_PROBLEMS_FIND_THE_MIDDLE_INDEX_IN_ARRAY_H__

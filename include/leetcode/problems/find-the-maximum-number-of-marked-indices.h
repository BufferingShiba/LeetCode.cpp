#ifndef LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_NUMBER_OF_MARKED_INDICES_H__
#define LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_NUMBER_OF_MARKED_INDICES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2576 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheMaximumNumberOfMarkedIndicesSolution
    : public SolutionBase<Func> {
 public:
  FindTheMaximumNumberOfMarkedIndicesSolution();

  int maxNumOfMarkedIndices(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2576

#endif  // LEETCODE_PROBLEMS_FIND_THE_MAXIMUM_NUMBER_OF_MARKED_INDICES_H__

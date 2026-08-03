#ifndef LEETCODE_PROBLEMS_FIND_MISSING_AND_REPEATED_VALUES_H__
#define LEETCODE_PROBLEMS_FIND_MISSING_AND_REPEATED_VALUES_H__

#include "leetcode/core.h"
#include <vector>

namespace leetcode::problem_2965 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class FindMissingAndRepeatedValuesSolution
    : public SolutionBase<Func> {
 public:
  FindMissingAndRepeatedValuesSolution();

  std::vector<int> findMissingAndRepeatedValues(
      std::vector<std::vector<int>>& grid);
};

}  // namespace leetcode::problem_2965

#endif  // LEETCODE_PROBLEMS_FIND_MISSING_AND_REPEATED_VALUES_H__

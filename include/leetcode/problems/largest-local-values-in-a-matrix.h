#ifndef LEETCODE_PROBLEMS_LARGEST_LOCAL_VALUES_IN_A_MATRIX_H__
#define LEETCODE_PROBLEMS_LARGEST_LOCAL_VALUES_IN_A_MATRIX_H__

#include "leetcode/core.h"

namespace leetcode::problem_2373 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class LargestLocalValuesInAMatrixSolution
    : public SolutionBase<Func> {
 public:
  std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid);

  LargestLocalValuesInAMatrixSolution();
};

}  // namespace leetcode::problem_2373

#endif  // LEETCODE_PROBLEMS_LARGEST_LOCAL_VALUES_IN_A_MATRIX_H__

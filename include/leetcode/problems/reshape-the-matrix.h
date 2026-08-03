#ifndef LEETCODE_PROBLEMS_RESHAPE_THE_MATRIX_H_
#define LEETCODE_PROBLEMS_RESHAPE_THE_MATRIX_H_

#include "leetcode/core.h"

namespace leetcode::problem_566 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&, int, int)>;

class ReshapeTheMatrixSolution : public SolutionBase<Func> {
 public:
  ReshapeTheMatrixSolution();
  std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c);
};

}  // namespace leetcode::problem_566

#endif  // LEETCODE_PROBLEMS_RESHAPE_THE_MATRIX_H_

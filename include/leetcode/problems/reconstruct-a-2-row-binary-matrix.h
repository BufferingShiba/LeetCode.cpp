#ifndef LEETCODE_PROBLEMS_RECONSTRUCT_A_2_ROW_BINARY_MATRIX_H_
#define LEETCODE_PROBLEMS_RECONSTRUCT_A_2_ROW_BINARY_MATRIX_H_

#include "leetcode/core.h"

namespace leetcode::problem_1253 {

using Func = std::function<std::vector<std::vector<int>>(int, int, std::vector<int>&)>;

class ReconstructA2RowBinaryMatrixSolution : public SolutionBase<Func> {
 public:
  ReconstructA2RowBinaryMatrixSolution();

  std::vector<std::vector<int>> reconstructMatrix(int upper, int lower,
                                                   std::vector<int>& colsum) {
    return getSolution()(upper, lower, colsum);
  }
};

}  // namespace leetcode::problem_1253

#endif  // LEETCODE_PROBLEMS_RECONSTRUCT_A_2_ROW_BINARY_MATRIX_H_

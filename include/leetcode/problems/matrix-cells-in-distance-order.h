#ifndef LEETCODE_PROBLEMS_MATRIX_CELLS_IN_DISTANCE_ORDER_H
#define LEETCODE_PROBLEMS_MATRIX_CELLS_IN_DISTANCE_ORDER_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1030 {

using Func = std::function<std::vector<std::vector<int>>(int, int, int, int)>;

class MatrixCellsInDistanceOrderSolution : public SolutionBase<Func> {
 public:
  MatrixCellsInDistanceOrderSolution();

  std::vector<std::vector<int>> allCellsDistOrder(int rows, int cols,
                                                   int rCenter, int cCenter);
};

}  // namespace problem_1030
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MATRIX_CELLS_IN_DISTANCE_ORDER_H

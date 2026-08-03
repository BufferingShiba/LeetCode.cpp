#ifndef LEETCODE_PROBLEMS_SORT_MATRIX_BY_DIAGONALS_H_
#define LEETCODE_PROBLEMS_SORT_MATRIX_BY_DIAGONALS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3446 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&)>;

class SortMatrixByDiagonalsSolution
    : public SolutionBase<Func> {
 public:
  SortMatrixByDiagonalsSolution();

  std::vector<std::vector<int>> sortMatrix(
      std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3446
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SORT_MATRIX_BY_DIAGONALS_H_

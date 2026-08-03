#ifndef LEETCODE_PROBLEMS_FIND_VALID_MATRIX_GIVEN_ROW_AND_COLUMN_SUMS_H__
#define LEETCODE_PROBLEMS_FIND_VALID_MATRIX_GIVEN_ROW_AND_COLUMN_SUMS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1605 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<int>&, std::vector<int>&)>;

class FindValidMatrixGivenRowAndColumnSumsSolution
    : public SolutionBase<Func> {
 public:
  FindValidMatrixGivenRowAndColumnSumsSolution();

  std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum,
                                              std::vector<int>& colSum);
};

}  // namespace problem_1605
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_VALID_MATRIX_GIVEN_ROW_AND_COLUMN_SUMS_H__

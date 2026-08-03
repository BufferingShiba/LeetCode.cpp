#ifndef LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ONES_AND_ZEROS_IN_ROW_AND_COLUMN_H__
#define LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ONES_AND_ZEROS_IN_ROW_AND_COLUMN_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2482 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&)>;

class DifferenceBetweenOnesAndZerosInRowAndColumnSolution
    : public SolutionBase<Func> {
 public:
  DifferenceBetweenOnesAndZerosInRowAndColumnSolution();

  std::vector<std::vector<int>> onesMinusZeros(
      std::vector<std::vector<int>>& grid);
};

}  // namespace problem_2482
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIFFERENCE_BETWEEN_ONES_AND_ZEROS_IN_ROW_AND_COLUMN_H__

#ifndef LEETCODE_PROBLEM_1252_CELLS_WITH_ODD_VALUES_IN_A_MATRIX_H__
#define LEETCODE_PROBLEM_1252_CELLS_WITH_ODD_VALUES_IN_A_MATRIX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1252 {

using Func = std::function<int(int m, int n, std::vector<std::vector<int>>& indices)>;

class CellsWithOddValuesInAMatrixSolution : public SolutionBase<Func> {
 public:
  CellsWithOddValuesInAMatrixSolution();

  // 题目原方法
  int oddCells(int m, int n, std::vector<std::vector<int>>& indices);
};

}  // namespace problem_1252
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1252_CELLS_WITH_ODD_VALUES_IN_A_MATRIX_H__

#ifndef LEETCODE_PROBLEMS_TOEPLITZ_MATRIX_H__
#define LEETCODE_PROBLEMS_TOEPLITZ_MATRIX_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_766 {

using Func = std::function<bool(std::vector<std::vector<int>>&)>;

class ToeplitzMatrixSolution : public SolutionBase<Func> {
 public:
  ToeplitzMatrixSolution();

  bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix);
};

}  // namespace leetcode::problem_766

#endif  // LEETCODE_PROBLEMS_TOEPLITZ_MATRIX_H__

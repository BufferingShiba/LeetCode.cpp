#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_CONVERT_BINARY_MATRIX_TO_ZERO_MATRIX_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_CONVERT_BINARY_MATRIX_TO_ZERO_MATRIX_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_1284 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfFlipsToConvertBinaryMatrixToZeroMatrixSolution();

  int minFlips(std::vector<std::vector<int>>& mat);
};

}  // namespace leetcode::problem_1284

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_FLIPS_TO_CONVERT_BINARY_MATRIX_TO_ZERO_MATRIX_H_

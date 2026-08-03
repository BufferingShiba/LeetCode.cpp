#ifndef LEETCODE_PROBLEMS_SPIRAL_MATRIX_II_H_
#define LEETCODE_PROBLEMS_SPIRAL_MATRIX_II_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_59 {

using Func = std::function<std::vector<std::vector<int>>(int)>;

class SpiralMatrixIiSolution : public SolutionBase<Func> {
 public:
  SpiralMatrixIiSolution();

  std::vector<std::vector<int>> generateMatrix(int n);
};

}  // namespace problem_59
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPIRAL_MATRIX_II_H_

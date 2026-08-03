#include "leetcode/core.h"

namespace leetcode {
namespace problem_885 {

using Func = std::function<vector<vector<int>>(int, int, int, int)>;

class SpiralMatrixIiiSolution : public SolutionBase<Func> {
 public:
  //! 885. Spiral Matrix III
  //! https://leetcode.com/problems/spiral-matrix-iii/
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart);

  SpiralMatrixIiiSolution();
};

}  // namespace problem_885
}  // namespace leetcode

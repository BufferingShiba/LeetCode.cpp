#include "leetcode/core.h"

namespace leetcode {
namespace problem_1329 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class SortTheMatrixDiagonallySolution : public SolutionBase<Func> {
 public:
  //! 1329. Sort the Matrix Diagonally
  //! https://leetcode.com/problems/sort-the-matrix-diagonally/
  std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat);

  SortTheMatrixDiagonallySolution();
};

}  // namespace problem_1329
}  // namespace leetcode

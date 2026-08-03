#ifndef LEETCODE_PROBLEMS_FLIP_SQUARE_SUBMATRIX_VERTICALLY_H_
#define LEETCODE_PROBLEMS_FLIP_SQUARE_SUBMATRIX_VERTICALLY_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3643 {

using Func =
    std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&,
                                                 int, int, int)>;

class FlipSquareSubmatrixVerticallySolution
    : public SolutionBase<Func> {
 public:
  FlipSquareSubmatrixVerticallySolution();

  std::vector<std::vector<int>> reverseSubmatrix(
      std::vector<std::vector<int>>& grid, int x, int y, int k);
};

}  // namespace problem_3643
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FLIP_SQUARE_SUBMATRIX_VERTICALLY_H_


#include "leetcode/core.h"

namespace leetcode {
namespace problem_2579 {

using Func = std::function<long long(int)>;

class CountTotalNumberOfColoredCellsSolution : public SolutionBase<Func> {
 public:
  //! 2579. Count Total Number of Colored Cells
  //! https://leetcode.com/problems/count-total-number-of-colored-cells/
  long long coloredCells(int n);

  CountTotalNumberOfColoredCellsSolution();
};

}  // namespace problem_2579
}  // namespace leetcode

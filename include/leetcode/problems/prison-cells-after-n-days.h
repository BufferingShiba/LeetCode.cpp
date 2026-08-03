#include "leetcode/core.h"

namespace leetcode {
namespace problem_957 {

using Func = std::function<vector<int>(vector<int>&, int)>;

class PrisonCellsAfterNDaysSolution : public SolutionBase<Func> {
 public:
  //! 957. Prison Cells After N Days
  //! https://leetcode.com/problems/prison-cells-after-n-days/
  vector<int> prisonAfterNDays(vector<int>& cells, int n);

  PrisonCellsAfterNDaysSolution();
};

}  // namespace problem_957
}  // namespace leetcode

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2943 {

using Func = std::function<int(int, int, vector<int>&, vector<int>&)>;

class MaximizeAreaOfSquareHoleInGridSolution : public SolutionBase<Func> {
 public:
  //! 2943. Maximize Area of Square Hole in Grid
  //! https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars);

  MaximizeAreaOfSquareHoleInGridSolution();
};

}  // namespace problem_2943
}  // namespace leetcode
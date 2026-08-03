#include "leetcode/core.h"

namespace leetcode {
namespace problem_2812 {

using Func = std::function<int(vector<vector<int>>&)>;

class FindTheSafestPathInAGridSolution : public SolutionBase<Func> {
 public:
  //! 2812. Find the Safest Path in a Grid
  //! https://leetcode.com/problems/find-the-safest-path-in-a-grid/
  int maximumSafenessFactor(vector<vector<int>>& grid);

  FindTheSafestPathInAGridSolution();
};

}  // namespace problem_2812
}  // namespace leetcode

#include "leetcode/core.h"

namespace leetcode {
namespace problem_452 {

using Func = std::function<int(vector<vector<int>>&)>;

class MinimumNumberOfArrowsToBurstBalloonsSolution : public SolutionBase<Func> {
 public:
  //! 452. Minimum Number of Arrows to Burst Balloons
  //! https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
  int findMinArrowShots(vector<vector<int>>& points);

  MinimumNumberOfArrowsToBurstBalloonsSolution();
};

}  // namespace problem_452
}  // namespace leetcode

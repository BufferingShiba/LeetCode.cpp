#include "leetcode/core.h"

namespace leetcode {
namespace problem_1266 {

using Func = std::function<int(vector<vector<int>>&)>;

class MinimumTimeVisitingAllPointsSolution : public SolutionBase<Func> {
 public:
  //! 1266. Minimum Time Visiting All Points
  //! https://leetcode.com/problems/minimum-time-visiting-all-points/
  int minTimeToVisitAllPoints(vector<vector<int>>& points);

  MinimumTimeVisitingAllPointsSolution();
};

}  // namespace problem_1266
}  // namespace leetcode
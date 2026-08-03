#include "leetcode/core.h"

namespace leetcode {
namespace problem_3648 {

using Func = std::function<int(int, int, int)>;

class MinimumSensorsToCoverGridSolution : public SolutionBase<Func> {
 public:
  //! 3648. Minimum Sensors to Cover Grid
  //! https://leetcode.com/problems/minimum-sensors-to-cover-grid/
  int minSensors(int n, int m, int k);

  MinimumSensorsToCoverGridSolution();
};

}  // namespace problem_3648
}  // namespace leetcode

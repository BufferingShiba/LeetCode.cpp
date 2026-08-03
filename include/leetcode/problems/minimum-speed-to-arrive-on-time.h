#include "leetcode/core.h"

namespace leetcode {
namespace problem_1870 {

using Func = std::function<int(vector<int>&, double)>;

class MinimumSpeedToArriveOnTimeSolution : public SolutionBase<Func> {
 public:
  //! 1870. Minimum Speed to Arrive on Time
  //! https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
  int minSpeedOnTime(vector<int>& dist, double hour);

  MinimumSpeedToArriveOnTimeSolution();
};

}  // namespace problem_1870
}  // namespace leetcode

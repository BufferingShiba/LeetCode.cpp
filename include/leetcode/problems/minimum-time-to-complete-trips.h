#include "leetcode/core.h"

namespace leetcode {
namespace problem_2187 {

using Func = std::function<long(vector<int>&, int)>;

class MinimumTimeToCompleteTripsSolution : public SolutionBase<Func> {
 public:
  //! 2187. Minimum Time to Complete Trips
  //! https://leetcode.com/problems/minimum-time-to-complete-trips/
  long minimumTime(vector<int>& time, int totalTrips);

  MinimumTimeToCompleteTripsSolution();
};

}  // namespace problem_2187
}  // namespace leetcode

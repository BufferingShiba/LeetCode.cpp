#include "leetcode/core.h"

namespace leetcode {
namespace problem_3439 {

using Func = std::function<int(int, int, vector<int>&, vector<int>&)>;

class RescheduleMeetingsForMaximumFreeTimeISolution : public SolutionBase<Func> {
 public:
  //! 3439. Reschedule Meetings for Maximum Free Time I
  //! https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime);

  RescheduleMeetingsForMaximumFreeTimeISolution();
};

}  // namespace problem_3439
}  // namespace leetcode

#ifndef LEETCODE_PROBLEMS_MINIMUM_SKIPS_TO_ARRIVE_AT_MEETING_ON_TIME_H__
#define LEETCODE_PROBLEMS_MINIMUM_SKIPS_TO_ARRIVE_AT_MEETING_ON_TIME_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1883 {

using Func = std::function<int(std::vector<int>&, int, int)>;

class MinimumSkipsToArriveAtMeetingOnTimeSolution
    : public SolutionBase<Func> {
 public:
  MinimumSkipsToArriveAtMeetingOnTimeSolution();

  int minSkips(std::vector<int>& dist, int speed, int hoursBefore) {
    return getSolution()(dist, speed, hoursBefore);
  }
};

}  // namespace problem_1883
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SKIPS_TO_ARRIVE_AT_MEETING_ON_TIME_H__

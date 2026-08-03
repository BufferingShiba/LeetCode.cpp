#include "leetcode/problems/my-calendar-iii.h"

namespace leetcode {
namespace problem_732 {

MyCalendarThree::MyCalendarThree() = default;

int MyCalendarThree::book(int startTime, int endTime) {
  // Difference array over an ordered map: +1 at start, -1 at end.
  ++delta_[startTime];
  --delta_[endTime];

  // Sweep in ascending time order accumulating the prefix sum; the running
  // maximum is the largest k such that some time belongs to k events.
  int current = 0;
  int maxK = 0;
  for (const auto& [time, diff] : delta_) {
    current += diff;
    if (current > maxK) maxK = current;
  }
  return maxK;
}

}  // namespace problem_732
}  // namespace leetcode

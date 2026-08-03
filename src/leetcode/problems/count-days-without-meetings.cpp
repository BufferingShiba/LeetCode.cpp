#include "leetcode/problems/count-days-without-meetings.h"

#include <algorithm>

namespace leetcode {
namespace problem_3169 {

static int countDaysImpl(int days, std::vector<std::vector<int>>& meetings) {
  if (meetings.empty()) {
    return days;
  }

  // Sort by start day
  std::sort(meetings.begin(), meetings.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
            });

  int free_days = 0;
  int prev_end = 0;  // end of last merged interval

  for (const auto& m : meetings) {
    int start = m[0];
    int end = m[1];

    if (start > prev_end) {
      // Gap between previous merged interval and current meeting
      // Also covers the gap before the first meeting
      free_days += start - prev_end - 1;
    }

    // Merge: extend the current merged interval
    if (end > prev_end) {
      prev_end = end;
    }
  }

  // Gap after the last merged interval
  if (prev_end < days) {
    free_days += days - prev_end;
  }

  return free_days;
}

CountDaysWithoutMeetingsSolution::CountDaysWithoutMeetingsSolution() {
  setMetaInfo({.id = 3169,
               .title = "Count Days Without Meetings",
               .url = "https://leetcode.com/problems/count-days-without-meetings/"});

  registerStrategy(
      {.name = "Merge Intervals",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Sorting"}},
      countDaysImpl);
}

int CountDaysWithoutMeetingsSolution::countDays(
    int days, std::vector<std::vector<int>>& meetings) {
  return getSolution()(days, meetings);
}

}  // namespace problem_3169
}  // namespace leetcode

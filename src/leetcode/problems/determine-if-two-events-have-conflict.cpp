#include "leetcode/problems/determine-if-two-events-have-conflict.h"

namespace leetcode {
namespace problem_2446 {

namespace {

int toMinutes(const std::string& time) {
  int hour = (time[0] - '0') * 10 + (time[1] - '0');
  int minute = (time[3] - '0') * 10 + (time[4] - '0');
  return hour * 60 + minute;
}

bool haveConflictImpl(std::vector<std::string>& event1,
                      std::vector<std::string>& event2) {
  int s1 = toMinutes(event1[0]);
  int e1 = toMinutes(event1[1]);
  int s2 = toMinutes(event2[0]);
  int e2 = toMinutes(event2[1]);
  return s1 <= e2 && s2 <= e1;
}

}  // namespace

DetermineIfTwoEventsHaveConflictSolution::DetermineIfTwoEventsHaveConflictSolution() {
  setMetaInfo({.id = 2446, .title = "Determine if Two Events Have Conflict", .url = "https://leetcode.com/problems/determine-if-two-events-have-conflict/"});
  registerStrategy(
      {.name = "interval-overlap",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      haveConflictImpl);
}

bool DetermineIfTwoEventsHaveConflictSolution::haveConflict(
    std::vector<std::string>& event1,
    std::vector<std::string>& event2) {
  return getSolution()(event1, event2);
}

}  // namespace problem_2446
}  // namespace leetcode

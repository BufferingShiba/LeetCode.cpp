#include "leetcode/problems/number-of-students-unable-to-eat-lunch.h"

#include <vector>

namespace leetcode {
namespace problem_1700 {
namespace {

int countStudentsImpl(std::vector<int>& students,
                      std::vector<int>& sandwiches) {
  int pref[2] = {0, 0};
  for (int s : students) {
    ++pref[s];
  }
  int n = static_cast<int>(sandwiches.size());
  for (int i = 0; i < n; ++i) {
    int t = sandwiches[i];
    if (pref[t] > 0) {
      --pref[t];
    } else {
      // Current sandwich and the rest cannot be eaten.
      return n - i;
    }
  }
  return 0;
}

}  // namespace

NumberOfStudentsUnableToEatLunchSolution::NumberOfStudentsUnableToEatLunchSolution() {
  setMetaInfo({.id = 1700,
               .title = "Number of Students Unable to Eat Lunch",
               .url = "https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/"});
  registerStrategy(
      {.name = "CountingPreferences",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Stack", "Queue", "Simulation"}},
      countStudentsImpl);
}

int NumberOfStudentsUnableToEatLunchSolution::countStudents(
    std::vector<int>& students, std::vector<int>& sandwiches) {
  return getSolution()(students, sandwiches);
}

}  // namespace problem_1700
}  // namespace leetcode

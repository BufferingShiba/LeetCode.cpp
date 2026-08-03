#include "leetcode/problems/earliest-time-to-finish-one-task.h"

#include <algorithm>

namespace leetcode {
namespace problem_3683 {

static int earliestTimeImpl(std::vector<std::vector<int>>& tasks) {
  int ans = INT_MAX;
  for (const auto& t : tasks) {
    ans = std::min(ans, t[0] + t[1]);
  }
  return ans;
}

EarliestTimeToFinishOneTaskSolution::EarliestTimeToFinishOneTaskSolution() {
  setMetaInfo({.id = 3683,
               .title = "Earliest Time to Finish One Task",
               .url = "https://leetcode.com/problems/earliest-time-to-finish-one-task/"});
  registerStrategy(
      {.name = "Linear Scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      earliestTimeImpl);
}

int EarliestTimeToFinishOneTaskSolution::earliestTime(
    std::vector<std::vector<int>>& tasks) {
  return getSolution()(tasks);
}

}  // namespace problem_3683
}  // namespace leetcode

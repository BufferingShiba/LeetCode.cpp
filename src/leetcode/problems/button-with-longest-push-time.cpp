#include "leetcode/problems/button-with-longest-push-time.h"

namespace leetcode {
namespace problem_3386 {

namespace {

int buttonWithLongestTimeImpl(std::vector<std::vector<int>>& events) {
  int bestIndex = events[0][0];
  int bestDuration = events[0][1];
  for (int i = 1; i < static_cast<int>(events.size()); ++i) {
    int idx = events[i][0];
    int duration = events[i][1] - events[i - 1][1];
    if (duration > bestDuration ||
        (duration == bestDuration && idx < bestIndex)) {
      bestDuration = duration;
      bestIndex = idx;
    }
  }
  return bestIndex;
}

}  // namespace

ButtonWithLongestPushTimeSolution::ButtonWithLongestPushTimeSolution() {
  setMetaInfo({.id = 3386,
               .title = "Button with Longest Push Time",
               .url = "https://leetcode.com/problems/button-with-longest-push-time/"});

  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"}},
      [](std::vector<std::vector<int>>& events) -> int {
        return buttonWithLongestTimeImpl(events);
      });
}

int ButtonWithLongestPushTimeSolution::buttonWithLongestTime(
    std::vector<std::vector<int>>& events) {
  return getSolution()(events);
}

}  // namespace problem_3386
}  // namespace leetcode

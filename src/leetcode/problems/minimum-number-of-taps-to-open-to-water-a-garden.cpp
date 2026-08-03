#include "leetcode/problems/minimum-number-of-taps-to-open-to-water-a-garden.h"

namespace leetcode {
namespace problem_1326 {

namespace {

int minTapsImpl(int n, std::vector<int>& ranges) {
  // For each position left end, we want the furthest right endpoint reachable.
  std::vector<int> maxReach(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    int left = std::max(0, i - ranges[i]);
    int right = std::min(n, i + ranges[i]);
    maxReach[left] = std::max(maxReach[left], right);
  }

  int taps = 0;
  int currentEnd = 0;  // furthest covered by current selected taps
  int nextEnd = 0;     // furthest we can reach from current window
  for (int i = 0; i <= n; ++i) {
    if (i > currentEnd) {
      // gap: cannot extend coverage
      if (nextEnd <= currentEnd) return -1;
      currentEnd = nextEnd;
      ++taps;
    }
    nextEnd = std::max(nextEnd, maxReach[i]);
  }

  // After processing, if currentEnd still hasn't reached n, add final step if
  // nextEnd allows.
  if (currentEnd < n) {
    if (nextEnd <= currentEnd) return -1;
    currentEnd = nextEnd;
    ++taps;
  }
  return taps;
}

}  // namespace

MinimumNumberOfTapsToOpenToWaterAGardenSolution::
    MinimumNumberOfTapsToOpenToWaterAGardenSolution() {
  setMetaInfo({1326, "Minimum Number of Taps to Open to Water a Garden",
               "https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/"});
  registerStrategy({.name = "greedy_interval_cover",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Greedy"}},
                   minTapsImpl);
}

}  // namespace problem_1326
}  // namespace leetcode

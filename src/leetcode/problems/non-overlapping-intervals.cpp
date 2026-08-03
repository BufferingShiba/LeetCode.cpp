#include "leetcode/problems/non-overlapping-intervals.h"

#include <algorithm>
#include <vector>

namespace {

int greedyImpl(std::vector<std::vector<int>>& intervals) {
  int n = static_cast<int>(intervals.size());
  if (n <= 1) return 0;

  // Sort by end time ascending
  std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[1] < b[1];
            });

  int keep = 1;              // always keep the first (earliest-ending) interval
  int last_end = intervals[0][1];

  for (int i = 1; i < n; ++i) {
    if (intervals[i][0] >= last_end) {  // non-overlapping (touching allowed)
      ++keep;
      last_end = intervals[i][1];
    }
    // else: overlaps → remove this interval (don't update last_end)
  }

  return n - keep;
}

}  // namespace

namespace leetcode {
namespace problem_435 {

NonOverlappingIntervalsSolution::NonOverlappingIntervalsSolution() {
  setMetaInfo({.id = 435,
               .title = "Non-overlapping Intervals",
               .url = "https://leetcode.com/problems/non-overlapping-intervals/"});
  registerStrategy(
      {.name = "GreedyByEnd",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"}},
      greedyImpl);
  setDefaultStrategy();
}

int NonOverlappingIntervalsSolution::eraseOverlapIntervals(
    std::vector<std::vector<int>>& intervals) {
  return getSolution()(intervals);
}

}  // namespace problem_435
}  // namespace leetcode

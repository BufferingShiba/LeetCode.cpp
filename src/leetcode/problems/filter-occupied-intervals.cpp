#include "leetcode/problems/filter-occupied-intervals.h"

#include <algorithm>

namespace leetcode {
namespace problem_3975 {

namespace {

std::vector<std::vector<int>> mergeAndFilter(
    std::vector<std::vector<int>>& occupiedIntervals, int freeStart,
    int freeEnd) {
  if (occupiedIntervals.empty()) {
    return {};
  }

  // 1. Sort by start time
  std::sort(occupiedIntervals.begin(), occupiedIntervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[0] < b[0];
            });

  // 2. Merge touching and overlapping intervals
  std::vector<std::vector<int>> merged;
  for (const auto& interval : occupiedIntervals) {
    int start = interval[0];
    int end = interval[1];

    if (merged.empty() || merged.back()[1] + 1 < start) {
      // No overlap/touch: push new interval
      merged.push_back({start, end});
    } else {
      // Overlap or touch: extend the last interval
      merged.back()[1] = std::max(merged.back()[1], end);
    }
  }

  // 3. Filter out the free interval [freeStart, freeEnd]
  std::vector<std::vector<int>> result;
  for (const auto& interval : merged) {
    int L = interval[0];
    int R = interval[1];

    if (R < freeStart) {
      // Entirely before the free interval → keep as is
      result.push_back({L, R});
    } else if (L > freeEnd) {
      // Entirely after the free interval → keep as is
      result.push_back({L, R});
    } else {
      // Overlaps with the free interval → split
      if (L < freeStart) {
        // Left part survives
        result.push_back({L, freeStart - 1});
      }
      if (R > freeEnd) {
        // Right part survives
        result.push_back({freeEnd + 1, R});
      }
      // The middle part [max(L, freeStart), min(R, freeEnd)] is removed
    }
  }

  return result;
}

}  // namespace

FilterOccupiedIntervalsSolution::FilterOccupiedIntervalsSolution() {
  setMetaInfo({.id = 3975,
               .title = "Filter Occupied Intervals",
               .url = "https://leetcode.com/problems/filter-occupied-intervals/"});

  registerStrategy(
      {.name = "Merge & Filter",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting"}},
      mergeAndFilter);

  setDefaultStrategy();
}

std::vector<std::vector<int>>
FilterOccupiedIntervalsSolution::filterOccupiedIntervals(
    std::vector<std::vector<int>>& occupiedIntervals, int freeStart,
    int freeEnd) {
  return getSolution()(occupiedIntervals, freeStart, freeEnd);
}

}  // namespace problem_3975
}  // namespace leetcode

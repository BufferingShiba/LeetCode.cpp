#include "leetcode/problems/distance-between-bus-stops.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace leetcode::problem_1184 {

namespace {

int distanceBetweenBusStopsImpl(std::vector<int>& distance, int start,
                                int destination) {
  const int n = static_cast<int>(distance.size());
  if (start > destination) std::swap(start, destination);

  int clockwise = 0;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += distance[i];
    if (i >= start && i < destination) clockwise += distance[i];
  }
  return std::min(clockwise, total - clockwise);
}

}  // namespace

DistanceBetweenBusStopsSolution::DistanceBetweenBusStopsSolution() {
  setMetaInfo({.id = 1184,
               .title = "Distance Between Bus Stops",
               .url = "https://leetcode.com/problems/distance-between-bus-stops/"});
  registerStrategy(
      {.name = "two-pass-min",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array"},
       .notes =
           "Compute total circular distance and clockwise distance in one pass,"
           " then take min(clockwise, total-clockwise)."},
      distanceBetweenBusStopsImpl);
}

int DistanceBetweenBusStopsSolution::distanceBetweenBusStops(
    std::vector<int>& distance, int start, int destination) {
  return getSolution()(distance, start, destination);
}

}  // namespace leetcode::problem_1184

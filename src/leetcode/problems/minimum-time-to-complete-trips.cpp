#include "leetcode/problems/minimum-time-to-complete-trips.h"

#include <algorithm>

namespace leetcode {
namespace problem_2187 {

// Binary search on the time.
// At time t, bus i completes t / time[i] trips. Find the minimum t such that
// the sum of t / time[i] over all buses >= totalTrips.
static long solution1(vector<int>& time, int totalTrips) {
  long lo = 1;
  long hi = static_cast<long>(totalTrips) * (*std::min_element(time.begin(), time.end()));
  while (lo < hi) {
    long mid = lo + (hi - lo) / 2;
    long trips = 0;
    for (int t : time) {
      trips += mid / t;
      if (trips >= totalTrips) break;  // avoid overflow and early exit
    }
    if (trips >= totalTrips) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

MinimumTimeToCompleteTripsSolution::MinimumTimeToCompleteTripsSolution() {
  setMetaInfo({
      .id = 2187,
      .title = "Minimum Time to Complete Trips",
      .url = "https://leetcode.com/problems/minimum-time-to-complete-trips"
  });
  registerStrategy({.name = "Binary Search",
                    .expected = "Accepted",
                    .time_complexity = "O(n log(maxTime))",
                    .space_complexity = "O(1)",
                    .tags = {"Binary Search"}},
                   solution1);
}

long MinimumTimeToCompleteTripsSolution::minimumTime(vector<int>& time, int totalTrips) {
  return getSolution()(time, totalTrips);
}

}  // namespace problem_2187
}  // namespace leetcode

#include "leetcode/problems/minimum-speed-to-arrive-on-time.h"

#include <cmath>

namespace leetcode {
namespace problem_1870 {

static bool canReach(const std::vector<int>& dist, double hour, int speed) {
  double total = 0.0;
  for (size_t i = 0; i + 1 < dist.size(); ++i) {
    // Non-last trains: wait until next integer hour, so take ceil(dist/s).
    total += std::ceil(static_cast<double>(dist[i]) / speed);
  }
  // Last train: no rounding, arrive when ride finishes.
  total += static_cast<double>(dist.back()) / speed;
  return total <= hour + 1e-9;
}

static int solution1(std::vector<int>& dist, double hour) {
  int n = static_cast<int>(dist.size());
  // The first n-1 trains each need at least 1 hour (ceil to integer hour),
  // plus the last train takes positive time. If n-1 >= hour, impossible.
  if (static_cast<double>(n - 1) >= hour) {
    return -1;
  }
  int lo = 1, hi = 10000000;  // answer won't exceed 1e7.
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (canReach(dist, hour, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

MinimumSpeedToArriveOnTimeSolution::MinimumSpeedToArriveOnTimeSolution() {
  setMetaInfo({
      .id = 1870,
      .title = "Minimum Speed to Arrive on Time",
      .url = "https://leetcode.com/problems/minimum-speed-to-arrive-on-time"
  });
  registerStrategy({.name = "Binary Search",
                    .expected = "Accepted",
                    .time_complexity = "O(n log(1e7))",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Binary Search"}},
                   solution1);
}

int MinimumSpeedToArriveOnTimeSolution::minSpeedOnTime(std::vector<int>& dist, double hour) {
  return getSolution()(dist, hour);
}

}  // namespace problem_1870
}  // namespace leetcode

#include "leetcode/problems/minimum-number-of-seconds-to-make-mountain-height-zero.h"

#include <algorithm>
#include <cmath>

namespace leetcode {
namespace problem_3296 {
namespace {

// Returns the max units of height one worker (with per-unit time w) can
// reduce within `limit` seconds: largest x such that w*x*(x+1)/2 <= limit.
// Solve x^2 + x - 2*limit/w <= 0 -> x = floor((-1 + sqrt(1 + 8*limit/w)) / 2).
long long maxReduce(long long w, long long limit) {
  long long approx =
      (long long)((std::sqrt(1.0L + 8.0L * (long double)limit / (long double)w) - 1.0L) / 2.0L);
  if (approx < 0) approx = 0;
  // Small bounded correction for any floating-point rounding error.
  while (w * (approx + 1) * (approx + 2) / 2 <= limit) ++approx;
  while (w * approx * (approx + 1) / 2 > limit) --approx;
  if (approx < 0) approx = 0;
  return approx;
}

bool feasible(int height, const std::vector<int>& workerTimes, long long moment) {
  long long total = 0;
  for (int w : workerTimes) {
    total += maxReduce(w, moment);
    if (total >= height) return true;
  }
  return total >= height;
}

long long minNumberSecondsImpl(int mountainHeight, std::vector<int>& workerTimes) {
  long long lo = 1;
  long long hi = (long long)workerTimes[0] * mountainHeight * (mountainHeight + 1) / 2;
  while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (feasible(mountainHeight, workerTimes, mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

}  // namespace

MinimumNumberOfSecondsToMakeMountainHeightZeroSolution::
    MinimumNumberOfSecondsToMakeMountainHeightZeroSolution() {
  setMetaInfo({.id = 3296,
               .title = "Minimum Number of Seconds to Make Mountain Height Zero",
               .url = "https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/"});
  registerStrategy({.name = "binarySearch",
                    .expected = "Accepted",
                    .time_complexity = "O(W * log(w_max * H^3))",
                    .space_complexity = "O(1)",
                    .tags = {"Binary Search", "Greedy", "Math"}},
                   minNumberSecondsImpl);
}

long long MinimumNumberOfSecondsToMakeMountainHeightZeroSolution::
    minNumberOfSeconds(int mountainHeight, std::vector<int>& workerTimes) {
  return getSolution()(mountainHeight, workerTimes);
}

}  // namespace problem_3296
}  // namespace leetcode

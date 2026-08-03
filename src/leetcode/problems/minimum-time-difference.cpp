#include "leetcode/problems/minimum-time-difference.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_539 {
namespace {

int findMinDifferenceImpl(std::vector<std::string>& timePoints) {
  constexpr int kDayMinutes = 24 * 60;
  const int n = static_cast<int>(timePoints.size());

  // 超过一天可区分的分钟数时，必有重复时间，答案必为 0。
  if (n > kDayMinutes) {
    return 0;
  }

  std::vector<int> minutes;
  minutes.reserve(n);
  for (const std::string& tp : timePoints) {
    int h = (tp[0] - '0') * 10 + (tp[1] - '0');
    int m = (tp[3] - '0') * 10 + (tp[4] - '0');
    minutes.push_back(h * 60 + m);
  }

  std::sort(minutes.begin(), minutes.end());

  int best = kDayMinutes;
  for (int i = 1; i < n; ++i) {
    best = std::min(best, minutes[i] - minutes[i - 1]);
    if (best == 0) return 0;
  }

  // 环形：最后一个与第一个跨午夜的距离。
  best = std::min(best, minutes[0] + kDayMinutes - minutes[n - 1]);
  return best;
}

}  // namespace

MinimumTimeDifferenceSolution::MinimumTimeDifferenceSolution() {
  setMetaInfo({.id = 539,
               .title = "Minimum Time Difference",
               .url = "https://leetcode.com/problems/minimum-time-difference/"});
  registerStrategy(
      {"SortAndScan",
       "Accepted",
       "O(n log n)",
       "O(n)",
       {"Array", "Math", "String", "Sorting"},
       "Convert to minutes, sort, scan adjacent diffs plus the wrap-around "
       "gap; early exit on duplicate (pigeonhole) for large inputs."},
      findMinDifferenceImpl);
}

int MinimumTimeDifferenceSolution::findMinDifference(
    std::vector<std::string>& timePoints) {
  return getSolution()(timePoints);
}

}  // namespace problem_539
}  // namespace leetcode

#include "leetcode/problems/maximize-score-of-numbers-in-ranges.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3281 {

static int solution1(vector<int>& start, int d) {
  const int n = static_cast<int>(start.size());
  std::sort(start.begin(), start.end());

  // Returns true if we can pick one integer from each interval with
  // minimum pairwise gap >= gap.
  auto can = [&](long long gap) -> bool {
    long long prev = start[0];  // previous chosen value
    for (int i = 1; i < n; ++i) {
      long long need = prev + gap;
      if (need > static_cast<long long>(start[i]) + d) {
        return false;
      }
      prev = std::max(need, static_cast<long long>(start[i]));
    }
    return true;
  };

  long long lo = 0;
  long long hi = 4e9;  // generous upper bound (start, d up to 1e9)
  while (lo < hi) {
    long long mid = lo + (hi - lo + 1) / 2;
    if (can(mid)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return static_cast<int>(lo);
}

MaximizeScoreOfNumbersInRangesSolution::MaximizeScoreOfNumbersInRangesSolution() {
  setMetaInfo({
      .id = 3281,
      .title = "Maximize Score of Numbers in Ranges",
      .url = "https://leetcode.com/problems/maximize-score-of-numbers-in-ranges"
  });
  registerStrategy({.name = "Binary Search + Greedy",
                    .time_complexity = "O(n log C)",
                    .space_complexity = "O(1)",
                    .tags = {"Binary Search", "Greedy", "Sorting"}},
                   solution1);
}

int MaximizeScoreOfNumbersInRangesSolution::maxPossibleScore(vector<int>& start, int d) {
  return getSolution()(start, d);
}

}  // namespace problem_3281
}  // namespace leetcode

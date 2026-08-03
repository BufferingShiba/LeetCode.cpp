#include "leetcode/problems/maximum-score-of-non-overlapping-intervals.h"

#include <algorithm>

namespace leetcode {
namespace problem_3414 {

namespace {

struct Interval {
  long long l, r, w;
  int orig;
};

struct State {
  long long score = 0;
  std::vector<int> idx;
};

bool better(const State& a, const State& b) {
  if (a.score != b.score) return a.score > b.score;
  return a.idx < b.idx;
}

std::vector<int> maximumWeightImpl(std::vector<std::vector<int>>& intervals) {
  int n = static_cast<int>(intervals.size());
  std::vector<Interval> iv(n);
  for (int i = 0; i < n; ++i) {
    iv[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
  }
  std::sort(iv.begin(), iv.end(),
            [](const Interval& a, const Interval& b) { return a.r < b.r; });

  constexpr int MAXK = 4;
  // dp[k][pos]: best state choosing at most k intervals from the first pos
  // (sorted by right endpoint). idx stored ascending by original index.
  std::vector<std::vector<State>> dp(
      MAXK + 1, std::vector<State>(n + 1, State{0, {}}));

  for (int k = 1; k <= MAXK; ++k) {
    for (int pos = 1; pos <= n; ++pos) {
      const Interval& cur = iv[pos - 1];
      // option 1: skip the current interval
      State best = dp[k][pos - 1];

      // option 2: pick the current interval, provided it can follow an
      // earlier non-overlapping group from the first p (p = number of
      // intervals among the first pos-1 whose right endpoint < cur.l).
      int lo = 0, hi = pos - 1;  // search in [0, pos-1)
      while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (iv[mid].r < cur.l) {
          lo = mid + 1;
        } else {
          hi = mid;
        }
      }
      int p = lo;
      State pick = dp[k - 1][p];
      pick.score += cur.w;
      pick.idx.push_back(cur.orig);
      std::sort(pick.idx.begin(), pick.idx.end());
      if (better(pick, best)) best = pick;

      dp[k][pos] = best;
    }
  }

  return dp[MAXK][n].idx;
}

}  // namespace

MaximumScoreOfNonOverlappingIntervalsSolution::
    MaximumScoreOfNonOverlappingIntervalsSolution() {
  setMetaInfo({.id = 3414,
               .title = "Maximum Score of Non-overlapping Intervals",
               .url =
                   "https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/"});
  registerStrategy(
      {.name = "dp-sorted-binary-search",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Binary Search", "Sorting"},
       .notes =
           "Sort by right endpoint; DP over up to 4 intervals with binary "
           "search for non-overlapping predecessor; track lexicographically "
           "smallest index vector."},
      maximumWeightImpl);
}

}  // namespace problem_3414
}  // namespace leetcode

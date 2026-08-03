#include "leetcode/problems/reschedule-meetings-for-maximum-free-time-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_3439 {

static int solution1(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
  const int n = static_cast<int>(startTime.size());

  // Free time gaps between meetings: n + 1 gaps total.
  // gap[0]      = free time before the first meeting
  // gap[i]      = free time between meeting i-1 and meeting i
  // gap[n]      = free time after the last meeting
  vector<long long> gaps(n + 1, 0LL);
  gaps[0] = startTime[0];
  for (int i = 1; i < n; ++i) {
    gaps[i] = static_cast<long long>(startTime[i]) - endTime[i - 1];
  }
  gaps[n] = static_cast<long long>(eventTime) - endTime[n - 1];

  // Moving k meetings merges their k+1 surrounding free gaps into one block.
  // Maximize the sum of any (k+1) consecutive gaps.
  const int windowSize = k + 1;  // k <= n  ==>  windowSize <= n + 1 = gaps.size()
  long long window = 0;
  for (int i = 0; i < windowSize; ++i) {
    window += gaps[i];
  }
  long long best = window;
  for (int i = windowSize; i < n + 1; ++i) {
    window += gaps[i] - gaps[i - windowSize];
    best = std::max(best, window);
  }

  return static_cast<int>(best);
}

RescheduleMeetingsForMaximumFreeTimeISolution::RescheduleMeetingsForMaximumFreeTimeISolution() {
  setMetaInfo({
      .id = 3439,
      .title = "Reschedule Meetings for Maximum Free Time I",
      .url = "https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/"
  });
  registerStrategy({.name = "Sliding Window Over Gaps",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Sliding Window", "Greedy", "Array"}},
                   solution1);
}

int RescheduleMeetingsForMaximumFreeTimeISolution::maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
  return getSolution()(eventTime, k, startTime, endTime);
}

}  // namespace problem_3439
}  // namespace leetcode

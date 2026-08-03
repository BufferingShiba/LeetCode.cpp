#include "leetcode/problems/longest-well-performing-interval.h"

#include <unordered_map>

namespace leetcode::problem_1124 {

namespace {

int longestWPIImpl(std::vector<int>& hours) {
  // Convert hours to +1 (tiring) / -1 (non-tiring), then find longest
  // subarray with positive sum.
  int n = static_cast<int>(hours.size());
  std::unordered_map<int, int> first_pos;
  first_pos[0] = -1;  // prefix sum 0 starts at index -1.

  int running = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    running += (hours[i] > 8) ? 1 : -1;
    if (running > 0) {
      // Whole prefix [0..i] is well-performing.
      ans = i + 1;
    } else {
      // To make a positive-sum segment ending here, we need a prefix sum
      // strictly smaller than `running`. Since values only change by +/-1,
      // running - 1 is the immediate smaller value; recording the earliest
      // occurrence of each sum gives the longest such segment.
      auto it = first_pos.find(running - 1);
      if (it != first_pos.end()) {
        ans = std::max(ans, i - it->second);
      }
      if (first_pos.find(running) == first_pos.end()) {
        first_pos[running] = i;
      }
    }
  }
  return ans;
}

}  // namespace

LongestWellPerformingIntervalSolution::LongestWellPerformingIntervalSolution() {
  setMetaInfo({.id = 1124,
               .title = "Longest Well-Performing Interval",
               .url = "https://leetcode.com/problems/longest-well-performing-interval/"});
  registerStrategy(
      {.name = "prefix-sum-hashmap",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Prefix Sum"}},
      longestWPIImpl);
}

int LongestWellPerformingIntervalSolution::longestWPI(std::vector<int>& hours) {
  return getSolution()(hours);
}

}  // namespace leetcode::problem_1124

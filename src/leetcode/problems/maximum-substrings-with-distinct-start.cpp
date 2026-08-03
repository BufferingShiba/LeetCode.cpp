#include "leetcode/problems/maximum-substrings-with-distinct-start.h"

#include <string>
#include <vector>

namespace leetcode::problem_3760 {

namespace {

// The number of distinct starting characters bounds the number of substrings.
// This upper bound is always achievable: take each distinct character's first
// occurrence index (naturally increasing, with index 0 first) as cut points.
int maxDistinctImpl(const std::string& s) {
  std::vector<bool> seen(26, false);
  int count = 0;
  for (char c : s) {
    const int idx = c - 'a';
    if (!seen[idx]) {
      seen[idx] = true;
      ++count;
    }
  }
  return count;
}

}  // namespace

MaximumSubstringsWithDistinctStartSolution::
    MaximumSubstringsWithDistinctStartSolution() {
  setMetaInfo({.id = 3760,
               .title = "Maximum Substrings With Distinct Start",
               .url =
                   "https://leetcode.com/problems/maximum-substrings-with-"
                   "distinct-start/"});
  registerStrategy(
      {.name = "distinct_char_count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Greedy"}},
      maxDistinctImpl);
}

int MaximumSubstringsWithDistinctStartSolution::maxDistinct(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3760

#include "leetcode/problems/flip-string-to-monotone-increasing.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_926 {
namespace {

// Single-pass DP with O(1) space.
// Idea: Let `ones` = count of '1' seen so far, `flips` = minimal flips to make
// the prefix monotone increasing. On encountering '0', we can either flip it to
// '1' (cost flips+1) or flip all previous '1's to '0' (cost `ones`), so take
// min.  On '1', just increment ones (it can serve as the tail).
int minFlipsMonoIncrImpl(const std::string& s) {
  int ones = 0;
  int flips = 0;
  for (char c : s) {
    if (c == '1') {
      ++ones;
    } else {
      flips = std::min(flips + 1, ones);
    }
  }
  return flips;
}

}  // namespace

FlipStringToMonotoneIncreasingSolution::FlipStringToMonotoneIncreasingSolution() {
  setMetaInfo({.id = 926,
              .title = "Flip String to Monotone Increasing",
              .url = "https://leetcode.com/problems/flip-string-to-monotone-increasing/"});
  registerStrategy({.name = "greedy-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Dynamic Programming", "String"}},
                   minFlipsMonoIncrImpl);
}

}  // namespace problem_926
}  // namespace leetcode

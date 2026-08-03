#include "leetcode/problems/time-needed-to-rearrange-a-binary-string.h"

#include <algorithm>

namespace leetcode {
namespace problem_2380 {

static int secondsToRemoveOccurrencesImpl(std::string s) {
  int zeros = 0;
  int ans = 0;
  for (char c : s) {
    if (c == '0') {
      ++zeros;
    } else if (zeros > 0) {
      ans = std::max(ans + 1, zeros);
    }
  }
  return ans;
}

TimeNeededToRearrangeABinaryStringSolution::TimeNeededToRearrangeABinaryStringSolution() {
  setMetaInfo({.id = 2380,
               .title = "Time Needed to Rearrange a Binary String",
               .url = "https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Dynamic Programming", "Simulation"}},
                   secondsToRemoveOccurrencesImpl);
}

int TimeNeededToRearrangeABinaryStringSolution::secondsToRemoveOccurrences(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2380
}  // namespace leetcode

#include "leetcode/problems/length-of-the-longest-alphabetical-continuous-substring.h"

namespace leetcode {
namespace problem_2414 {

static int longestContinuousSubstringImpl(std::string s) {
  if (s.empty()) return 0;
  int ans = 1;
  int cur = 1;
  for (size_t i = 1; i < s.size(); ++i) {
    if (s[i] - s[i - 1] == 1) {
      ++cur;
      if (cur > ans) ans = cur;
    } else {
      cur = 1;
    }
  }
  return ans;
}

LengthOfTheLongestAlphabeticalContinuousSubstringSolution::LengthOfTheLongestAlphabeticalContinuousSubstringSolution() {
  setMetaInfo({.id = 2414,
               .title = "Length of the Longest Alphabetical Continuous Substring",
               .url = "https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/"});
  registerStrategy({.name = "SinglePass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   longestContinuousSubstringImpl);
  setDefaultStrategy();
}

int LengthOfTheLongestAlphabeticalContinuousSubstringSolution::longestContinuousSubstring(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2414
}  // namespace leetcode

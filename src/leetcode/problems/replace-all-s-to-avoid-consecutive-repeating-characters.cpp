#include "leetcode/problems/replace-all-s-to-avoid-consecutive-repeating-characters.h"

namespace leetcode {
namespace problem_1576 {

namespace {

std::string modifyStringImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      char prev = (i > 0) ? s[i - 1] : '\0';
      char next = (i + 1 < n) ? s[i + 1] : '\0';
      for (char c = 'a'; c <= 'z'; ++c) {
        if (c != prev && c != next) {
          s[i] = c;
          break;
        }
      }
    }
  }
  return s;
}

}  // namespace

ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution::
    ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution() {
  setMetaInfo({
      .id = 1576,
      .title = "Replace All ?'s to Avoid Consecutive Repeating Characters",
      .url = "https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/",
  });
  registerStrategy(
      {.name = "greedy_single_scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy"}},
      modifyStringImpl);
}

std::string ReplaceAllSToAvoidConsecutiveRepeatingCharactersSolution::
    modifyString(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1576
}  // namespace leetcode

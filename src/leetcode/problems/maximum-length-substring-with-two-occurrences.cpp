#include "leetcode/problems/maximum-length-substring-with-two-occurrences.h"

namespace leetcode {
namespace problem_3090 {
namespace {

int maximumLengthSubstringImpl(std::string s) {
  int count[26] = {0};
  int left = 0;
  int max_len = 0;
  for (int right = 0; right < static_cast<int>(s.size()); ++right) {
    ++count[s[right] - 'a'];
    while (count[s[right] - 'a'] > 2) {
      --count[s[left] - 'a'];
      ++left;
    }
    max_len = std::max(max_len, right - left + 1);
  }
  return max_len;
}

}  // namespace

MaximumLengthSubstringWithTwoOccurrencesSolution::
    MaximumLengthSubstringWithTwoOccurrencesSolution() {
  setMetaInfo({.id = 3090,
               .title = "Maximum Length Substring With Two Occurrences",
               .url = "https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/"});
  registerStrategy(
      {.name = "SlidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Sliding Window"}},
      maximumLengthSubstringImpl);
}

int MaximumLengthSubstringWithTwoOccurrencesSolution::maximumLengthSubstring(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3090
}  // namespace leetcode

#include "leetcode/problems/find-the-index-of-the-first-occurrence-in-a-string.h"

namespace leetcode {
namespace problem_28 {
namespace {

int strStrImpl(std::string haystack, std::string needle) {
  if (needle.empty()) {
    return 0;
  }
  int m = static_cast<int>(haystack.size());
  int n = static_cast<int>(needle.size());
  for (int i = 0; i + n <= m; ++i) {
    int j = 0;
    while (j < n && haystack[i + j] == needle[j]) {
      ++j;
    }
    if (j == n) {
      return i;
    }
  }
  return -1;
}

}  // namespace

FindTheIndexOfTheFirstOccurrenceInAStringSolution::
    FindTheIndexOfTheFirstOccurrenceInAStringSolution() {
  setMetaInfo({.id = 28,
               .title = "Find the Index of the First Occurrence in a String",
               .url = "https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/"});
  registerStrategy(
      {.name = "BruteForceTwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "String Matching"}},
      strStrImpl);
}

int FindTheIndexOfTheFirstOccurrenceInAStringSolution::strStr(
    std::string haystack, std::string needle) {
  return getSolution()(haystack, needle);
}

}  // namespace problem_28
}  // namespace leetcode

#include "leetcode/problems/check-if-all-characters-have-equal-number-of-occurrences.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_1941 {

namespace {

bool areOccurrencesEqualImpl(std::string s) {
  int freq[26] = {0};
  for (char c : s) {
    ++freq[c - 'a'];
  }

  int target = 0;
  for (int f : freq) {
    if (f == 0) continue;
    if (target == 0) {
      target = f;
    } else if (f != target) {
      return false;
    }
  }
  return true;
}

}  // namespace

CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution::
    CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution() {
  setMetaInfo({.id = 1941,
               .title = "Check if All Characters Have Equal Number of Occurrences",
               .url = "https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/"});

  registerStrategy(
      {.name = "Frequency Counter",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      areOccurrencesEqualImpl);
}

bool CheckIfAllCharactersHaveEqualNumberOfOccurrencesSolution::areOccurrencesEqual(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1941

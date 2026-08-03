#include "leetcode/problems/count-the-number-of-consistent-strings.h"

namespace leetcode::problem_1684 {

namespace {

int countConsistentStringsImpl(const std::string& allowed,
                               std::vector<std::string>& words) {
  bool present[26] = {false};
  for (char c : allowed) {
    present[c - 'a'] = true;
  }
  int count = 0;
  for (const std::string& word : words) {
    bool consistent = true;
    for (char c : word) {
      if (!present[c - 'a']) {
        consistent = false;
        break;
      }
    }
    if (consistent) {
      ++count;
    }
  }
  return count;
}

}  // namespace

int CountTheNumberOfConsistentStringsSolution::countConsistentStrings(
    std::string allowed, std::vector<std::string>& words) {
  return getSolution()(allowed, words);
}

CountTheNumberOfConsistentStringsSolution::
    CountTheNumberOfConsistentStringsSolution() {
  setMetaInfo({.id = 1684,
               .title = "Count the Number of Consistent Strings",
               .url = "https://leetcode.com/problems/count-the-number-of-"
                      "consistent-strings/"});
  registerStrategy(
      {.name = "hash_set",
       .expected = "Accepted",
       .time_complexity = "O(total_chars_in_words + len(allowed))",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      countConsistentStringsImpl);
}

}  // namespace leetcode::problem_1684

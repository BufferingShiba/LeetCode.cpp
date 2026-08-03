#include "leetcode/problems/count-the-number-of-vowel-strings-in-range.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2586 {

namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int vowelStringsImpl(std::vector<std::string>& words, int left, int right) {
  int count = 0;
  for (int i = left; i <= right; ++i) {
    const std::string& w = words[i];
    if (isVowel(w.front()) && isVowel(w.back())) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountTheNumberOfVowelStringsInRangeSolution::
    CountTheNumberOfVowelStringsInRangeSolution() {
  setMetaInfo({.id = 2586,
               .title = "Count the Number of Vowel Strings in Range",
               .url = "https://leetcode.com/problems/"
                      "count-the-number-of-vowel-strings-in-range/"});
  registerStrategy(
      {.name = "linear_scan",
       .expected = "Accepted",
       .time_complexity = "O((right-left+1) * L)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String", "Counting"}},
      vowelStringsImpl);
}

int CountTheNumberOfVowelStringsInRangeSolution::vowelStrings(
    std::vector<std::string>& words, int left, int right) {
  return getSolution()(words, left, right);
}

}  // namespace problem_2586
}  // namespace leetcode

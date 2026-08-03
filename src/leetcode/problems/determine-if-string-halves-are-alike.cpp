#include "leetcode/problems/determine-if-string-halves-are-alike.h"

namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool halvesAreAlikeImpl(std::string s) {
  int n = static_cast<int>(s.size());
  int half = n / 2;
  int count = 0;
  for (int i = 0; i < half; ++i) {
    if (isVowel(s[i])) ++count;
  }
  for (int i = half; i < n; ++i) {
    if (isVowel(s[i])) --count;
  }
  return count == 0;
}

}  // namespace

namespace leetcode::problem_1704 {

DetermineIfStringHalvesAreAlikeSolution::DetermineIfStringHalvesAreAlikeSolution() {
  setMetaInfo({.id = 1704,
               .title = "Determine if String Halves Are Alike",
               .url = "https://leetcode.com/problems/determine-if-string-halves-are-alike/"});
  registerStrategy({.name = "Counting",
                     .expected = "Accepted",
                     .time_complexity = "O(n)",
                     .space_complexity = "O(1)",
                     .tags = {"String", "Counting"}},
                    halvesAreAlikeImpl);
}

bool DetermineIfStringHalvesAreAlikeSolution::halvesAreAlike(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_1704

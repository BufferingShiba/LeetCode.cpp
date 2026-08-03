#include "leetcode/problems/trim-trailing-vowels.h"

namespace leetcode::problem_3856 {

namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

std::string trimTrailingVowelsImpl(std::string s) {
  while (!s.empty() && isVowel(s.back())) {
    s.pop_back();
  }
  return s;
}

}  // namespace

TrimTrailingVowelsSolution::TrimTrailingVowelsSolution() {
  setMetaInfo({.id = 3856,
               .title = "Trim Trailing Vowels",
               .url = "https://leetcode.com/problems/trim-trailing-vowels/"});
  registerStrategy({.name = "Single-pass Reverse Scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   trimTrailingVowelsImpl);
}

std::string TrimTrailingVowelsSolution::trimTrailingVowels(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3856

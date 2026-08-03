#include "leetcode/problems/reverse-only-letters.h"

#include <cctype>

namespace leetcode::problem_917 {

namespace {

std::string reverseOnlyLettersImpl(std::string s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (!std::isalpha(s[left])) {
      ++left;
    } else if (!std::isalpha(s[right])) {
      --right;
    } else {
      std::swap(s[left], s[right]);
      ++left;
      --right;
    }
  }
  return s;
}

}  // namespace

ReverseOnlyLettersSolution::ReverseOnlyLettersSolution() {
  setMetaInfo({.id = 917,
               .title = "Reverse Only Letters",
               .url = "https://leetcode.com/problems/reverse-only-letters/"});
  registerStrategy({.name = "Two Pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Two Pointers", "String"}},
                   reverseOnlyLettersImpl);
}

std::string ReverseOnlyLettersSolution::reverseOnlyLetters(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_917

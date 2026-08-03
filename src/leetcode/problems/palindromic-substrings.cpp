#include "leetcode/problems/palindromic-substrings.h"

namespace leetcode {
namespace problem_647 {
namespace {

int expandAroundCenter(const std::string& s, int left, int right) {
  int count = 0;
  while (left >= 0 && right < static_cast<int>(s.size()) &&
         s[left] == s[right]) {
    ++count;
    --left;
    ++right;
  }
  return count;
}

int countSubstringsExpandAroundCenter(const std::string& s) {
  int total = 0;
  const int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    // Odd-length palindromes centered at s[i].
    total += expandAroundCenter(s, i, i);
    // Even-length palindromes centered between s[i] and s[i+1].
    total += expandAroundCenter(s, i, i + 1);
  }
  return total;
}

}  // namespace

PalindromicSubstringsSolution::PalindromicSubstringsSolution() {
  setMetaInfo({.id = 647,
               .title = "Palindromic Substrings",
               .url = "https://leetcode.com/problems/palindromic-substrings/"});
  registerStrategy(
      {.name = "ExpandAroundCenter",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      countSubstringsExpandAroundCenter);
}

int PalindromicSubstringsSolution::countSubstrings(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_647
}  // namespace leetcode

#include "leetcode/problems/valid-palindrome-ii.h"

namespace leetcode {
namespace problem_680 {
namespace {

bool isPalindrome(const std::string& s, int left, int right) {
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

bool validPalindromeImpl(std::string s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      // Try deleting left or deleting right.
      return isPalindrome(s, left + 1, right) ||
             isPalindrome(s, left, right - 1);
    }
    ++left;
    --right;
  }
  return true;
}

}  // namespace

ValidPalindromeIiSolution::ValidPalindromeIiSolution() {
  setMetaInfo({680, "Valid Palindrome II",
               "https://leetcode.com/problems/valid-palindrome-ii/"});
  registerStrategy(
      {.name = "TwoPointersGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Greedy"}},
      validPalindromeImpl);
}

bool ValidPalindromeIiSolution::validPalindrome(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_680
}  // namespace leetcode

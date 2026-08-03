#include "leetcode/problems/palindrome-number.h"

namespace leetcode {
namespace problem_9 {

namespace {

bool isPalindromeImpl(int x) {
  if (x < 0) {
    return false;
  }
  if (x == 0) {
    return true;
  }
  if (x % 10 == 0) {
    return false;
  }
  int reversed = 0;
  while (x > reversed) {
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }
  return x == reversed || x == reversed / 10;
}

}  // namespace

PalindromeNumberSolution::PalindromeNumberSolution() {
  setMetaInfo({.id = 9,
               .title = "Palindrome Number",
               .url =
                   "https://leetcode.com/problems/palindrome-number/"});
  registerStrategy(
      {.name = "Reverse Half",
       .expected = "Accepted",
       .time_complexity = "O(log10 n)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      isPalindromeImpl);
}

bool PalindromeNumberSolution::isPalindrome(int x) {
  return getSolution()(x);
}

}  // namespace problem_9
}  // namespace leetcode

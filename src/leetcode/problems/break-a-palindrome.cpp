#include "leetcode/problems/break-a-palindrome.h"

namespace leetcode {
namespace problem_1328 {
namespace {

std::string breakPalindromeImpl(std::string palindrome) {
  const int n = static_cast<int>(palindrome.size());
  if (n == 1) return "";

  // Try to make the first non-'a' character in the first half into 'a'.
  for (int i = 0; i < n / 2; ++i) {
    if (palindrome[i] != 'a') {
      palindrome[i] = 'a';
      return palindrome;
    }
  }

  // First half is all 'a'; make the last character 'b'.
  palindrome[n - 1] = 'b';
  return palindrome;
}

}  // namespace

BreakAPalindromeSolution::BreakAPalindromeSolution() {
  setMetaInfo({.id = 1328,
               .title = "Break a Palindrome",
               .url = "https://leetcode.com/problems/break-a-palindrome/"});
  registerStrategy(
      {"Greedy", "Accepted", "O(n)", "O(1)", {"String", "Greedy"},
       "Scan the first half for the first non-'a'; change it to 'a'. "
       "Otherwise change the last character to 'b'."},
      breakPalindromeImpl);
}

std::string BreakAPalindromeSolution::breakPalindrome(std::string palindrome) {
  return getSolution()(palindrome);
}

}  // namespace problem_1328
}  // namespace leetcode

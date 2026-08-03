#include "leetcode/problems/longest-palindrome.h"

namespace leetcode {
namespace problem_409 {
namespace {

int longestPalindromeImpl(std::string s) {
  int count[128] = {0};
  for (char c : s) {
    ++count[static_cast<unsigned char>(c)];
  }

  int result = 0;
  bool hasOdd = false;
  for (int i = 0; i < 128; ++i) {
    if (count[i] % 2 == 0) {
      result += count[i];
    } else {
      result += count[i] - 1;
      hasOdd = true;
    }
  }
  return hasOdd ? result + 1 : result;
}

}  // namespace

LongestPalindromeSolution::LongestPalindromeSolution() {
  setMetaInfo({.id = 409,
               .title = "Longest Palindrome",
               .url = "https://leetcode.com/problems/longest-palindrome/"});
  registerStrategy(
      {.name = "greedy-freqcount",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Greedy"}},
      longestPalindromeImpl);
}

int LongestPalindromeSolution::longestPalindrome(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_409
}  // namespace leetcode

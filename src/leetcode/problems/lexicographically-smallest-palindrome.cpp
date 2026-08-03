#include "leetcode/problems/lexicographically-smallest-palindrome.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_2697 {

namespace {

std::string makeSmallestPalindromeImpl(std::string s) {
  std::string res = s;
  int left = 0;
  int right = static_cast<int>(res.size()) - 1;
  while (left < right) {
    if (res[left] != res[right]) {
      char smaller = static_cast<char>(std::min(res[left], res[right]));
      res[left] = smaller;
      res[right] = smaller;
    }
    ++left;
    --right;
  }
  return res;
}

}  // namespace

LexicographicallySmallestPalindromeSolution::LexicographicallySmallestPalindromeSolution() {
  setMetaInfo({.id = 2697,
               .title = "Lexicographically Smallest Palindrome",
               .url = "https://leetcode.com/problems/lexicographically-smallest-palindrome/"});
  registerStrategy({.name = "two-pointers-greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Two Pointers", "String", "Greedy"}},
                   makeSmallestPalindromeImpl);
}

std::string LexicographicallySmallestPalindromeSolution::makeSmallestPalindrome(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_2697

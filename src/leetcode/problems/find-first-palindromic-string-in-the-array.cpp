#include "leetcode/problems/find-first-palindromic-string-in-the-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2108 {

namespace {

bool isPalindrome(const std::string& s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    ++left;
    --right;
  }
  return true;
}

std::string firstPalindromeImpl(std::vector<std::string>& words) {
  for (const std::string& word : words) {
    if (isPalindrome(word)) {
      return word;
    }
  }
  return "";
}

}  // namespace

FindFirstPalindromicStringInTheArraySolution::FindFirstPalindromicStringInTheArraySolution() {
  setMetaInfo(
      {.id = 2108,
       .title = "Find First Palindromic String in the Array",
       .url = "https://leetcode.com/problems/find-first-palindromic-string-in-the-array/"});
  registerStrategy(
      {.name = "LinearScan",
       .expected = "Accepted",
       .time_complexity = "O(n*L)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "String"}},
      firstPalindromeImpl);
}

std::string FindFirstPalindromicStringInTheArraySolution::firstPalindrome(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_2108
}  // namespace leetcode

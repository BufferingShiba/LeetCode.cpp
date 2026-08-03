#include "leetcode/problems/longest-palindromic-substring.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_5 {

namespace {

// 中心扩展：返回以 left/right 为起点向外扩展的最长回文子串
std::string expandAroundCenter(const std::string& s, int left, int right) {
  while (left >= 0 && right < static_cast<int>(s.size()) &&
         s[left] == s[right]) {
    --left;
    ++right;
  }
  // 循环退出时 left 和 right 已在回文外，长度 = (right - 1) - (left + 1) + 1 = right - left - 1
  return s.substr(left + 1, right - left - 1);
}

std::string longestPalindromeImpl(const std::string& s) {
  if (s.empty()) {
    return "";
  }

  std::string longest;

  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    // 奇数长度回文，中心为 i
    std::string odd = expandAroundCenter(s, i, i);
    if (odd.size() > longest.size()) {
      longest = odd;
    }

    // 偶数长度回文，中心为 i 和 i+1 之间
    std::string even = expandAroundCenter(s, i, i + 1);
    if (even.size() > longest.size()) {
      longest = even;
    }
  }

  return longest;
}

}  // namespace

LongestPalindromicSubstringSolution::LongestPalindromicSubstringSolution() {
  setMetaInfo({.id = 5,
               .title = "Longest Palindromic Substring",
               .url = "https://leetcode.com/problems/longest-palindromic-substring/"});

  registerStrategy(
      {.name = "Expand Around Center",
       .expected = "Accepted",
       .time_complexity = "O(n²)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      longestPalindromeImpl);

  setDefaultStrategy();
}

std::string LongestPalindromicSubstringSolution::longestPalindrome(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_5

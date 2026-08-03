#include "leetcode/problems/shortest-palindrome.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_214 {

namespace {

// 使用 KMP 前缀函数找出 s 的最长回文前缀。
// 构造 comb = s + '#' + reverse(s)，则 comb 的前缀函数最后一个值
// 等于 s 的最长回文前缀长度。
std::string shortestPalindromeImpl(std::string s) {
  const int n = static_cast<int>(s.size());
  if (n <= 1) {
    return s;
  }

  std::string rev = s;
  std::reverse(rev.begin(), rev.end());
  std::string comb = s + "#" + rev;

  const int m = static_cast<int>(comb.size());
  std::vector<int> pi(m, 0);
  for (int i = 1; i < m; ++i) {
    int j = pi[i - 1];
    while (j > 0 && comb[i] != comb[j]) {
      j = pi[j - 1];
    }
    if (comb[i] == comb[j]) {
      ++j;
    }
    pi[i] = j;
  }

  // pi[m-1] 是最长回文前缀长度
  const int longest_pal_len = pi[m - 1];
  std::string suffix = s.substr(longest_pal_len);
  std::reverse(suffix.begin(), suffix.end());
  return suffix + s;
}

}  // namespace

ShortestPalindromeSolution::ShortestPalindromeSolution() {
  setMetaInfo({.id = 214,
               .title = "Shortest Palindrome",
               .url = "https://leetcode.com/problems/shortest-palindrome/"});

  registerStrategy(
      {.name = "kmp_prefix_function",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "String Matching"},
       .notes = "s + '#' + reverse(s) 的前缀函数最后一个值即最长回文前缀长度"},
      shortestPalindromeImpl);
}

std::string ShortestPalindromeSolution::shortestPalindrome(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_214

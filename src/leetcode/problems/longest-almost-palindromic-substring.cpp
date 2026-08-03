#include "leetcode/problems/longest-almost-palindromic-substring.h"

#include <vector>

namespace leetcode {
namespace problem_3844 {

// A substring [l, r] is identified by a two-pointer palindrome check that allows
// removing exactly one character.
//
// pal[l][r]  : [l, r] is a pure palindrome (0 removals).
// one[l][r]  : [l, r] becomes a palindrome after removing exactly one char.
//
// Recurrences (computed in increasing length order):
//   pal[l][r] = (l >= r) || (s[l] == s[r] && pal[l+1][r-1]);
//   one[l][r] = (l > r) ? false
//             : (l == r) ? true                       // remove the lone char -> empty palindrome
//             : ((s[l] == s[r] && one[l+1][r-1])      // keep the outer equal pair, remove inside
//                || pal[l+1][r]                       // remove s[l]
//                || pal[l][r-1]);                     // remove s[r]
//
// The answer is the maximum length of a substring with one[l][r] true.
static int solution1(string s) {
  const int n = static_cast<int>(s.size());
  if (n < 2) return 0;

  std::vector<std::vector<char>> pal(n, std::vector<char>(n, 0));
  std::vector<std::vector<char>> one(n, std::vector<char>(n, 0));

  // Base: empty / single-char intervals are pure palindromes.
  for (int i = 0; i < n; ++i) pal[i][i] = 1;
  // pal[l][r] for l>r is by definition true (empty interval),
  // handled implicitly below.

  auto isPal = [&](int l, int r) -> bool {
    // empty interval is a palindrome; single char too.
    if (l >= r) return true;
    return pal[l][r] != 0;
  };

  int best = 0;
  for (int len = 2; len <= n; ++len) {
    for (int l = 0; l + len - 1 < n; ++l) {
      const int r = l + len - 1;
      // pure palindrome
      if (s[l] == s[r] && isPal(l + 1, r - 1)) pal[l][r] = 1;

      // exactly-one-removal palindrome
      char v = 0;
      if (s[l] == s[r] && one[l + 1][r - 1]) v = 1;
      if (isPal(l + 1, r)) v = 1;
      if (isPal(l, r - 1)) v = 1;
      one[l][r] = v;

      if (v && len > best) best = len;
    }
  }

  return best;
}

LongestAlmostPalindromicSubstringSolution::LongestAlmostPalindromicSubstringSolution() {
  setMetaInfo({
      .id = 3844,
      .title = "Longest Almost-Palindromic Substring",
      .url = "https://leetcode.com/problems/longest-almost-palindromic-substring"
  });
  registerStrategy({.name = "DP (O(n^2))",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Dynamic Programming", "Two Pointers"}},
                   solution1);
}

int LongestAlmostPalindromicSubstringSolution::almostPalindromic(string s) {
  return getSolution()(s);
}

}  // namespace problem_3844
}  // namespace leetcode

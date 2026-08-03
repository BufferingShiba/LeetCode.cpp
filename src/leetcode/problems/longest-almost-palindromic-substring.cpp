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
// The rows are evaluated from right to left, so both tables can be kept as
// one-dimensional rolling rows. The answer is the maximum length of a
// substring with one[l][r] true.
static int solution1(string s) {
  const int n = static_cast<int>(s.size());
  if (n < 2) return 0;

  // pal[r] and one[r] hold the values for the row l+1 before column r is
  // overwritten. The diagonal values pal[l+1][r-1] and one[l+1][r-1] are
  // carried separately while scanning r from left to right.
  std::vector<char> pal(n, 0);
  std::vector<char> one(n, 0);

  int best = 0;
  for (int l = n - 1; l >= 0; --l) {
    // Single-character intervals: pure palindrome, and removing the lone
    // character leaves the empty palindrome.
    pal[l] = 1;
    one[l] = 1;

    char palDiagonal = 1;  // empty interval [l+1, l]
    char oneDiagonal = 0;
    char palLeft = 1;      // pal[l][l]
    for (int r = l + 1; r < n; ++r) {
      const char palBelow = pal[r];
      const char oneBelow = one[r];

      const char currentPal = s[l] == s[r] && palDiagonal;
      const char currentOne =
          (s[l] == s[r] && oneDiagonal) || palBelow || palLeft;

      pal[r] = currentPal;
      one[r] = currentOne;
      palDiagonal = palBelow;
      oneDiagonal = oneBelow;
      palLeft = currentPal;

      if (currentOne && r - l + 1 > best) {
        best = r - l + 1;
      }
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
                    .space_complexity = "O(n)",
                    .tags = {"Dynamic Programming", "Two Pointers"}},
                   solution1);
}

int LongestAlmostPalindromicSubstringSolution::almostPalindromic(string s) {
  return getSolution()(s);
}

}  // namespace problem_3844
}  // namespace leetcode

#include "leetcode/problems/lexicographically-smallest-beautiful-string.h"

#include <algorithm>

namespace leetcode {
namespace problem_2663 {

namespace {

// Greedy: repeatedly increment a position from the right, then fill the suffix
// with the smallest valid characters.
std::string smallestBeautifulStringImpl(std::string s, int k) {
  const int n = static_cast<int>(s.size());
  const char limit = static_cast<char>('a' + k - 1);

  // Return the smallest valid character for position i (must differ from the
  // immediate previous two positions to avoid palindromes of length 2 and 3),
  // searching strictly above `from` (exclusive) up to the alphabet limit, or -1.
  auto findValid = [&](int i, char from) -> char {
    for (char c = static_cast<char>(from + 1); c <= limit; ++c) {
      bool ok = true;
      if (i - 1 >= 0 && c == s[i - 1]) ok = false;
      if (i - 2 >= 0 && c == s[i - 2]) ok = false;
      if (ok) return c;
    }
    return -1;
  };

  // Try to increment position i (making it larger than s[i]). The new char must
  // differ from s[i-1] and s[i-2].
  for (int i = n - 1; i >= 0; --i) {
    char next = findValid(i, s[i]);
    if (next != -1) {
      s[i] = next;
      // Fill the suffix with smallest valid characters starting from 'a'.
      for (int j = i + 1; j < n; ++j) {
        for (char c = 'a'; c <= limit; ++c) {
          if (j - 1 >= 0 && c == s[j - 1]) continue;
          if (j - 2 >= 0 && c == s[j - 2]) continue;
          s[j] = c;
          break;
        }
      }
      return s;
    }
  }
  return "";
}

}  // namespace

LexicographicallySmallestBeautifulStringSolution::
    LexicographicallySmallestBeautifulStringSolution() {
  setMetaInfo({.id = 2663,
               .title = "Lexicographically Smallest Beautiful String",
               .url =
                   "https://leetcode.com/problems/lexicographically-smallest-"
                   "beautiful-string/"});
  registerStrategy(
      {.name = "GreedySuffix",
       .expected = "Accepted",
       .time_complexity = "O(n*k)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy"}},
      smallestBeautifulStringImpl);
}

std::string LexicographicallySmallestBeautifulStringSolution::
    smallestBeautifulString(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace problem_2663
}  // namespace leetcode

#include "leetcode/problems/longest-nice-substring.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1763 {
namespace {

// Enumerate all substrings and check niceness via lowercase/uppercase bitmasks.
// O(n^2) time, O(1) space.
std::string BruteForce(std::string s) {
  const int n = static_cast<int>(s.size());
  int bestLen = 0;
  int bestStart = 0;

  for (int i = 0; i < n; ++i) {
    int lower = 0;  // bits for seen lowercase letters
    int upper = 0;  // bits for seen uppercase letters
    for (int j = i; j < n; ++j) {
      char c = s[j];
      if (c >= 'a' && c <= 'z') {
        lower |= (1 << (c - 'a'));
      } else {
        upper |= (1 << (c - 'A'));
      }
      int len = j - i + 1;
      if (lower == upper && len > bestLen) {
        bestLen = len;
        bestStart = i;
      }
    }
  }

  return bestLen > 0 ? s.substr(bestStart, bestLen) : std::string();
}

}  // namespace

LongestNiceSubstringSolution::LongestNiceSubstringSolution() {
  setMetaInfo({.id = 1763,
               .title = "Longest Nice Substring",
               .url = "https://leetcode.com/problems/longest-nice-substring/"});
  registerStrategy({.name = "BruteForce",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Brute Force", "Bit Manipulation"}},
                   &BruteForce);
}

std::string LongestNiceSubstringSolution::longestNiceSubstring(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1763
}  // namespace leetcode

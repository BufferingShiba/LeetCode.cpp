#include "leetcode/problems/last-substring-in-lexicographical-order.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_1163 {

namespace {

std::string lastSubstringImpl(std::string s) {
  int n = static_cast<int>(s.size());
  int i = 0;       // start of current best suffix
  int j = 1;       // start of candidate suffix
  int k = 0;       // length of common prefix

  while (j + k < n) {
    if (s[i + k] == s[j + k]) {
      ++k;
      continue;
    }
    if (s[i + k] < s[j + k]) {
      // suffix i is smaller than suffix j;
      // all suffixes starting at i..i+k are also smaller
      i = std::max(i + k + 1, j);
      j = i + 1;
    } else {
      // suffix j is smaller, skip it and try next
      j = j + k + 1;
    }
    k = 0;
  }

  return s.substr(i);
}

}  // namespace

LastSubstringInLexicographicalOrderSolution::LastSubstringInLexicographicalOrderSolution() {
  setMetaInfo({.id = 1163,
               .title = "Last Substring in Lexicographical Order",
               .url = "https://leetcode.com/problems/last-substring-in-lexicographical-order/"});
  registerStrategy({.name = "Two Pointers",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Two Pointers", "String"}},
                   lastSubstringImpl);
}

std::string LastSubstringInLexicographicalOrderSolution::lastSubstring(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_1163

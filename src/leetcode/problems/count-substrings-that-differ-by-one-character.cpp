#include "leetcode/problems/count-substrings-that-differ-by-one-character.h"

namespace leetcode {
namespace problem_1638 {

// Count pairs of equal-length substrings of s and t differing at exactly one
// position. We fix the differing position (i in s, j in t) with s[i] != t[j].
// Left part can extend up to the LCP of (s[..i-1], t[..j-1]) positions, right
// part up to LCP of (s[i+1..], t[j+1..]). Each choice yields exactly one
// differing char, so contribution = (left[i-1][j-1]+1) * (right[i+1][j+1]+1).
static int countSubstringsImpl(std::string s, std::string t) {
  const int n = static_cast<int>(s.size());
  const int m = static_cast<int>(t.size());

  // left[i][j] = number of consecutive matching characters before (and
  // including) s[i], t[j] (i.e. scanning leftwards from positions i,j).
  std::vector<std::vector<int>> left(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) {
        left[i][j] = (i > 0 && j > 0 ? left[i - 1][j - 1] : 0) + 1;
      }
    }
  }

  // right[i][j] = number of consecutive matching characters after s[i], t[j]
  // (scanning rightwards from positions i,j, including themselves).
  std::vector<std::vector<int>> right(n, std::vector<int>(m, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (s[i] == t[j]) {
        right[i][j] =
            (i + 1 < n && j + 1 < m ? right[i + 1][j + 1] : 0) + 1;
      }
    }
  }

  long long result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) continue;
      const int lcnt = (i > 0 && j > 0) ? left[i - 1][j - 1] : 0;
      const int rcnt = (i + 1 < n && j + 1 < m) ? right[i + 1][j + 1] : 0;
      result += static_cast<long long>(lcnt + 1) * (rcnt + 1);
    }
  }
  return static_cast<int>(result);
}

CountSubstringsThatDifferByOneCharacterSolution::
    CountSubstringsThatDifferByOneCharacterSolution() {
  setMetaInfo({.id = 1638,
               .title = "Count Substrings That Differ by One Character",
               .url = "https://leetcode.com/problems/count-substrings-that-differ-by-one-character/"});
  registerStrategy(
      {.name = "lcp-prefix-suffix-count",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(n*m)",
       .tags = {"Dynamic Programming", "Enumeration", "String"}},
      countSubstringsImpl);
}

int CountSubstringsThatDifferByOneCharacterSolution::countSubstrings(
    std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_1638
}  // namespace leetcode

#include "leetcode/problems/longest-balanced-substring-ii.h"
#include <unordered_map>

namespace leetcode {
namespace problem_3714 {
namespace {

inline long long keyOf(int a, int b) {
  return (static_cast<long long>(a) << 32) ^
         static_cast<unsigned int>(b);
}

// A balanced substring has either:
//  - only one distinct char (any length), or
//  - exactly two chars X,Y with equal counts and the third absent, or
//  - all three chars with equal counts.
//
// Using prefix counts cntA,cntB,cntC:
//  * single-char: longest run of identical chars.
//  * all three: (cntA-cntB, cntB-cntC) repeats at two prefix positions.
//  * two chars with 'c' absent: (cntA-cntB, cntC) repeats (a-b gain equal, c
//    unchanged in between). Symmetric for 'b' and 'a' absent.
int longestBalancedImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  if (n <= 1) return n > 0 ? 1 : 0;

  int ans = 1;

  std::unordered_map<long long, int> type3;  // (a-b, b-c)
  std::unordered_map<long long, int> noC;    // (a-b, c)
  std::unordered_map<long long, int> noB;    // (a-c, b)
  std::unordered_map<long long, int> noA;    // (b-c, a)

  type3[0] = 0;
  noC[keyOf(0, 0)] = 0;
  noB[keyOf(0, 0)] = 0;
  noA[keyOf(0, 0)] = 0;

  int cntA = 0, cntB = 0, cntC = 0;
  // Track longest run of identical characters (single-char balanced substring).
  int run = 1;

  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    if (ch == 'a') ++cntA;
    else if (ch == 'b') ++cntB;
    else ++cntC;

    const int pos = i + 1;
    const int dab = cntA - cntB;
    const int dbc = cntB - cntC;
    const int dac = cntA - cntC;

    if (i > 0 && s[i] == s[i - 1]) {
      ++run;
    } else {
      run = 1;
    }
    ans = std::max(ans, run);

    auto tryUpdate = [&](std::unordered_map<long long, int>& mp, long long key) {
      auto it = mp.find(key);
      if (it != mp.end()) {
        ans = std::max(ans, pos - it->second);
      } else {
        mp.emplace(key, pos);
      }
    };

    tryUpdate(type3, keyOf(dab, dbc));
    tryUpdate(noC, keyOf(dab, cntC));
    tryUpdate(noB, keyOf(dac, cntB));
    tryUpdate(noA, keyOf(dbc, cntA));
  }

  return ans;
}

}  // namespace

LongestBalancedSubstringIiSolution::LongestBalancedSubstringIiSolution() {
  setMetaInfo({.id = 3714,
               .title = "Longest Balanced Substring II",
               .url = "https://leetcode.com/problems/longest-balanced-substring-ii/"});

  registerStrategy(
      {.name = "PrefixSumQuad",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Prefix Sum"},
       .notes = "Four prefix-diff maps covering all-balanced, two-char absent, and single-char runs."},
      longestBalancedImpl);
}

}  // namespace problem_3714
}  // namespace leetcode

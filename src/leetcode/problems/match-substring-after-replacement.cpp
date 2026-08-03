#include "leetcode/problems/match-substring-after-replacement.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2301 {

namespace {

bool matchReplacementImpl(std::string s, std::string sub,
                          std::vector<std::vector<char>>& mappings) {
  const int n = static_cast<int>(s.length());
  const int m = static_cast<int>(sub.length());

  // can[a][b] = true iff character a can become character b
  // (either a == b, or there is a mapping a -> b)
  bool can[128][128] = {};
  for (int c = 0; c < 128; ++c) {
    can[c][c] = true;
  }
  for (const auto& mp : mappings) {
    can[static_cast<unsigned char>(mp[0])][static_cast<unsigned char>(mp[1])] = true;
  }

  // For each possible start position in s
  for (int i = 0; i <= n - m; ++i) {
    int j = 0;
    while (j < m) {
      unsigned char sub_c = static_cast<unsigned char>(sub[j]);
      unsigned char s_c = static_cast<unsigned char>(s[i + j]);
      if (!can[sub_c][s_c]) {
        break;
      }
      ++j;
    }
    if (j == m) {
      return true;
    }
  }
  return false;
}

}  // namespace

bool MatchSubstringAfterReplacementSolution::matchReplacement(
    std::string s, std::string sub, std::vector<std::vector<char>>& mappings) {
  return getSolution()(s, sub, mappings);
}

MatchSubstringAfterReplacementSolution::MatchSubstringAfterReplacementSolution() {
  setMetaInfo({.id = 2301,
               .title = "Match Substring After Replacement",
               .url = "https://leetcode.com/problems/match-substring-after-replacement/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n * m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String", "String Matching"}},
      matchReplacementImpl);
}

}  // namespace problem_2301
}  // namespace leetcode

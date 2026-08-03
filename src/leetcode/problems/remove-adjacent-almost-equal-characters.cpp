#include "leetcode/problems/remove-adjacent-almost-equal-characters.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2957 {

namespace {

bool almostEqual(char a, char b) {
  return a == b || std::abs(a - b) == 1;
}

// DP over positions and final letters.
// dp[c] = min modifications needed so that the prefix up to the current
// position is valid and the current character ends up as letter c (c in 0..25).
// Transition: dp'[c] = (c != orig_i) + min over prev d with !almostEq(d,c) of dp[d].
int removeAlmostEqualCharactersImpl(std::string word) {
  const int kInf = 1e9;
  std::vector<int> dp(26, kInf);
  int orig0 = word[0] - 'a';
  for (int c = 0; c < 26; ++c) {
    dp[c] = (c == orig0) ? 0 : 1;
  }

  for (int i = 1; i < static_cast<int>(word.size()); ++i) {
    int orig = word[i] - 'a';
    std::vector<int> ndp(26, kInf);
    for (int c = 0; c < 26; ++c) {
      int best = kInf;
      for (int d = 0; d < 26; ++d) {
        if (almostEqual('a' + d, 'a' + c)) continue;
        best = std::min(best, dp[d]);
      }
      ndp[c] = best + (c == orig ? 0 : 1);
    }
    dp.swap(ndp);
  }

  return *std::min_element(dp.begin(), dp.end());
}

}  // namespace

RemoveAdjacentAlmostEqualCharactersSolution::RemoveAdjacentAlmostEqualCharactersSolution() {
  setMetaInfo({.id = 2957,
               .title = "Remove Adjacent Almost-Equal Characters",
               .url = "https://leetcode.com/problems/remove-adjacent-almost-equal-characters/"});
  registerStrategy(
      {.name = "DynamicProgramming",
       .expected = "Accepted",
       .time_complexity = "O(n * 26)",
       .space_complexity = "O(26)",
       .tags = {"String", "Dynamic Programming"}},
      removeAlmostEqualCharactersImpl);
}

}  // namespace problem_2957
}  // namespace leetcode

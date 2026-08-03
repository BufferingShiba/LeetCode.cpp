#include "leetcode/problems/can-convert-string-in-k-moves.h"

namespace leetcode {
namespace problem_1540 {

static bool solution1(string s, string t, int k) {
  int n = static_cast<int>(s.size());
  if (static_cast<int>(t.size()) != n) return false;

  // cnt[d] = number of positions that require a shift of exactly d letters
  // (d in [1, 25]; d == 0 means the characters already match).
  int cnt[26] = {0};
  for (int i = 0; i < n; ++i) {
    int d = (t[i] - s[i] + 26) % 26;
    if (d != 0) cnt[d]++;
  }

  // Positions needing shift d use moves d, d + 26, d + 52, ... (each index
  // chosen at most once). The largest such move must not exceed k.
  for (int d = 1; d < 26; ++d) {
    if (cnt[d] > 0) {
      int maxMove = d + 26 * (cnt[d] - 1);
      if (maxMove > k) return false;
    }
  }
  return true;
}

CanConvertStringInKMovesSolution::CanConvertStringInKMovesSolution() {
  setMetaInfo({
      .id = 1540,
      .title = "Can Convert String in K Moves",
      .url = "https://leetcode.com/problems/can-convert-string-in-k-moves"
  });
  registerStrategy(
      {.name = "Greedy frequency counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy", "Counting"}},
      solution1);
}

bool CanConvertStringInKMovesSolution::canConvertString(string s, string t, int k) {
  return getSolution()(s, t, k);
}

}  // namespace problem_1540
}  // namespace leetcode

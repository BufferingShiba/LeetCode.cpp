#include "leetcode/problems/maximum-length-of-a-concatenated-string-with-unique-characters.h"

#include <algorithm>

namespace leetcode {
namespace problem_1239 {

// Backtracking over subsequences.
// Each string is converted to a 26-bit mask of its characters.
// We keep a running mask of characters already used, and the current length.
static int solution1(vector<string>& arr) {
  // Build masks for each string; skip strings that contain duplicate chars.
  std::vector<int> masks;
  for (const std::string& s : arr) {
    int mask = 0;
    bool dup = false;
    for (char c : s) {
      int bit = 1 << (c - 'a');
      if (mask & bit) {
        dup = true;
        break;
      }
      mask |= bit;
    }
    if (!dup) masks.push_back(mask);
  }

  int best = 0;
  const int n = static_cast<int>(masks.size());

  // std::function-free recursive helper via a lambda with its own ref-capture.
  std::function<void(int, int, int)> dfs = [&](int idx, int usedMask, int len) {
    best = std::max(best, len);
    if (idx == n) return;
    for (int i = idx; i < n; ++i) {
      if ((usedMask & masks[i]) == 0) {
        dfs(i + 1, usedMask | masks[i], len + __builtin_popcount(masks[i]));
      }
    }
  };

  dfs(0, 0, 0);
  return best;
}

MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution::MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution() {
  setMetaInfo({
      .id = 1239,
      .title = "Maximum Length of a Concatenated String with Unique Characters",
      .url = "https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters"
  });
  registerStrategy({.name = "Backtracking", .time_complexity = "O(2^n)", .space_complexity = "O(n)"}, solution1);
}

int MaximumLengthOfAConcatenatedStringWithUniqueCharactersSolution::maxLength(vector<string>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_1239
}  // namespace leetcode

#include "leetcode/problems/minimum-length-of-anagram-concatenation.h"

namespace leetcode {
namespace problem_3138 {

static int solution1(string s) {
  int n = static_cast<int>(s.size());
  auto isValid = [&](int len) -> bool {
    // counts of the first block
    std::array<int, 26> first{};
    for (int i = 0; i < len; ++i) first[s[i] - 'a']++;
    for (int start = len; start < n; start += len) {
      std::array<int, 26> cur{};
      for (int i = start; i < start + len; ++i) cur[s[i] - 'a']++;
      if (cur != first) return false;
    }
    return true;
  };

  for (int len = 1; len <= n; ++len) {
    if (n % len != 0) continue;
    if (isValid(len)) return len;
  }
  return n;
}

MinimumLengthOfAnagramConcatenationSolution::MinimumLengthOfAnagramConcatenationSolution() {
  setMetaInfo({
      .id = 3138,
      .title = "Minimum Length of Anagram Concatenation",
      .url = "https://leetcode.com/problems/minimum-length-of-anagram-concatenation"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

int MinimumLengthOfAnagramConcatenationSolution::minAnagramLength(string s) {
  return getSolution()(s);
}

}  // namespace problem_3138
}  // namespace leetcode

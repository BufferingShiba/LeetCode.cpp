#include "leetcode/problems/find-the-k-th-character-in-string-game-i.h"

namespace leetcode::problem_3304 {
namespace {

char kthCharacterImpl(int k) {
  while (k > 1) {
    // Find the length of the string before the last operation: 1, 2, 4, 8, ...
    int before = 1;
    while (before * 2 < k) {
      before *= 2;
    }
    // k is in the appended half, which is next char of (k - before)-th char.
    if (k > before) {
      k -= before;
      // advance one letter in alphabet (wrap not needed since k <= 500, word << 26 chars)
      return static_cast<char>(kthCharacterImpl(k) + 1);
    }
  }
  return 'a';
}

}  // namespace

FindTheKThCharacterInStringGameISolution::FindTheKThCharacterInStringGameISolution() {
  setMetaInfo({.id = 3304,
               .title = "Find the K-th Character in String Game I",
               .url = "https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/"});

  registerStrategy({.name = "DivideAndConquer",
                    .expected = "Accepted",
                    .time_complexity = "O(log k)",
                    .space_complexity = "O(log k)",
                    .tags = {"Recursion", "Bit Manipulation"}},
                   kthCharacterImpl);
}

char FindTheKThCharacterInStringGameISolution::kthCharacter(int k) {
  return getSolution()(k);
}

}  // namespace leetcode::problem_3304

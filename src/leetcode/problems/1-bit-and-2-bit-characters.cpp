#include "leetcode/problems/1-bit-and-2-bit-characters.h"

namespace leetcode {
namespace problem_717 {

static bool solution1(vector<int>& bits) {
  int n = static_cast<int>(bits.size());
  int i = 0;
  while (i < n - 1) {
    if (bits[i] == 1) {
      i += 2;  // consume a two-bit character (10 or 11)
    } else {
      i += 1;  // consume a one-bit character (0)
    }
  }
  // The loop stops when i reaches the last index, meaning the last bit was
  // decoded as a standalone one-bit character.
  return i == n - 1;
}

Problem1BitAnd2BitCharactersSolution::Problem1BitAnd2BitCharactersSolution() {
  setMetaInfo({
      .id = 717,
      .title = "1-bit and 2-bit Characters",
      .url = "https://leetcode.com/problems/1-bit-and-2-bit-characters"
  });
  registerStrategy({.name = "Greedy Walk",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy"}},
                   solution1);
}

bool Problem1BitAnd2BitCharactersSolution::isOneBitCharacter(vector<int>& bits) {
  return getSolution()(bits);
}

}  // namespace problem_717
}  // namespace leetcode

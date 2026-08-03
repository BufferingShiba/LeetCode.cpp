#include "leetcode/problems/construct-the-longest-new-string.h"

#include <algorithm>

namespace leetcode {
namespace problem_2745 {

namespace {

int longestStringImpl(int x, int y, int z) {
  int mn = std::min(x, y);
  int extra = (x == y) ? 0 : 1;
  return 2 * (z + 2 * mn + extra);
}

}  // namespace

ConstructTheLongestNewStringSolution::ConstructTheLongestNewStringSolution() {
  setMetaInfo({.id = 2745,
               .title = "Construct the Longest New String",
               .url = "https://leetcode.com/problems/construct-the-longest-new-string/"});

  registerStrategy(
      {.name = "math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Greedy"}},
      longestStringImpl);

  setDefaultStrategy();
}

int ConstructTheLongestNewStringSolution::longestString(int x, int y, int z) {
  return getSolution()(x, y, z);
}

}  // namespace problem_2745
}  // namespace leetcode

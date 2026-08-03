#include "leetcode/problems/substrings-of-size-three-with-distinct-characters.h"

namespace leetcode {
namespace problem_1876 {

static int countGoodSubstringsImpl(std::string s) {
  int n = static_cast<int>(s.size());
  if (n < 3) return 0;
  int count = 0;
  for (int i = 0; i <= n - 3; ++i) {
    if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
      ++count;
    }
  }
  return count;
}

SubstringsOfSizeThreeWithDistinctCharactersSolution::
    SubstringsOfSizeThreeWithDistinctCharactersSolution() {
  setMetaInfo({.id = 1876,
               .title = "Substrings of Size Three with Distinct Characters",
               .url = "https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/"});
  registerStrategy(
      {.name = "SlidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Sliding Window", "Counting"}},
      countGoodSubstringsImpl);
}

int SubstringsOfSizeThreeWithDistinctCharactersSolution::countGoodSubstrings(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1876
}  // namespace leetcode

#include <algorithm>
#include <string>
#include <utility>

#include "leetcode/problems/lexicographically-smallest-string-after-a-swap.h"

namespace leetcode::problem_3216 {

static std::string getSmallestStringImpl(std::string s) {
  int n = static_cast<int>(s.size());
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] > s[i + 1] &&
        (s[i] - '0') % 2 == (s[i + 1] - '0') % 2) {
      std::swap(s[i], s[i + 1]);
      break;
    }
  }
  return s;
}

LexicographicallySmallestStringAfterASwapSolution::
    LexicographicallySmallestStringAfterASwapSolution() {
  setMetaInfo({.id = 3216,
               .title = "Lexicographically Smallest String After a Swap",
               .url = "https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/"});

  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy"}},
      getSmallestStringImpl);
}

std::string LexicographicallySmallestStringAfterASwapSolution::getSmallestString(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3216

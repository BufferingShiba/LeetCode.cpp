#include "leetcode/problems/minimum-string-length-after-balanced-removals.h"

#include <cstdlib>
#include <string>

namespace leetcode {
namespace problem_3746 {

namespace {

int minLengthAfterRemovalsImpl(const std::string& s) {
  int countA = 0;
  for (char c : s) {
    if (c == 'a') {
      ++countA;
    }
  }
  int countB = static_cast<int>(s.size()) - countA;
  return std::abs(countA - countB);
}

}  // namespace

MinimumStringLengthAfterBalancedRemovalsSolution::
    MinimumStringLengthAfterBalancedRemovalsSolution() {
  setMetaInfo({.id = 3746,
               .title = "Minimum String Length After Balanced Removals",
               .url =
                   "https://leetcode.com/problems/minimum-string-length-after-"
                   "balanced-removals/"});
  registerStrategy(
      {.name = "CountingDiff",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Counting"},
       .notes =
           "Each removal removes equal numbers of 'a' and 'b', so the diff "
           "(countA - countB) is invariant. The minimum remaining length equals "
           "|countA - countB|."},
      minLengthAfterRemovalsImpl);
}

int MinimumStringLengthAfterBalancedRemovalsSolution::minLengthAfterRemovals(
    const std::string& s) {
  return getSolution()(s);
}

}  // namespace problem_3746
}  // namespace leetcode

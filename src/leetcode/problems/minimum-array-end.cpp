#include "leetcode/problems/minimum-array-end.h"

namespace leetcode {
namespace problem_3133 {
namespace {

long long minEndImpl(int n, int x) {
  long long answer = x;
  long long remaining = static_cast<long long>(n) - 1;

  // The bits where x is zero are the only positions that may encode the
  // increasing index 0..n-1.  Embed remaining into those positions in order.
  for (int bit = 0; remaining != 0; ++bit) {
    if (((static_cast<long long>(x) >> bit) & 1LL) != 0) continue;
    if ((remaining & 1LL) != 0) answer |= 1LL << bit;
    remaining >>= 1;
  }
  return answer;
}

}  // namespace

MinimumArrayEndSolution::MinimumArrayEndSolution() {
  setMetaInfo({.id = 3133,
               .title = "Minimum Array End",
               .url = "https://leetcode.com/problems/minimum-array-end/"});
  registerStrategy({.name = "bit embedding",
                    .expected = "Accepted",
                    .time_complexity = "O(log(n + x))",
                    .space_complexity = "O(1)",
                    .tags = {"Bit Manipulation"}},
                   minEndImpl);
}

long long MinimumArrayEndSolution::minEnd(int n, int x) {
  return getSolution()(n, x);
}

}  // namespace problem_3133
}  // namespace leetcode

#include "leetcode/problems/sum-game.h"

#include <cstdlib>

namespace leetcode {
namespace problem_1927 {

namespace {

bool sumGameImpl(const std::string& num) {
  const int n = static_cast<int>(num.size());
  const int half = n / 2;

  long long diff = 0;  // knownSum(left) - knownSum(right)
  int ql = 0, qr = 0;  // count of '?' in left / right halves

  for (int i = 0; i < n; ++i) {
    if (num[i] == '?') {
      if (i < half) {
        ++ql;
      } else {
        ++qr;
      }
    } else {
      const int d = num[i] - '0';
      if (i < half) {
        diff += d;
      } else {
        diff -= d;
      }
    }
  }

  // Odd total '?' count means Alice always takes the last move and can
  // dictate a non-zero final difference. Alice wins.
  if (((ql + qr) & 1) != 0) {
    return true;
  }

  // Even total '?' count. Pair up equal numbers of left/right '?' that Bob
  // mirrors; the remaining excess '?' all lie on one side. Bob can only
  // force equality when the known difference exactly matches the maximum
  // reachable balance from that excess (9 * half the excess).
  return !(diff == 9LL * (qr - ql) / 2);
}

}  // namespace

SumGameSolution::SumGameSolution() {
  setMetaInfo({.id = 1927,
               .title = "Sum Game",
               .url = "https://leetcode.com/problems/sum-game/"});
  registerStrategy(
      {.name = "GameTheory",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String", "Greedy", "Game Theory"}},
      sumGameImpl);
}

}  // namespace problem_1927
}  // namespace leetcode

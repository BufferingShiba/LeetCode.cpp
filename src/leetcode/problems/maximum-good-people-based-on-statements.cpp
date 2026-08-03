#include "leetcode/problems/maximum-good-people-based-on-statements.h"

namespace leetcode {
namespace problem_2151 {
namespace {

int maximumGoodImpl(std::vector<std::vector<int>>& statements) {
  const int n = static_cast<int>(statements.size());
  int best = 0;

  for (int mask = 0; mask < (1 << n); ++mask) {
    bool consistent = true;
    // For every person i who is declared good under this mask, all their
    // statements must be truthful.
    for (int i = 0; i < n && consistent; ++i) {
      if (!(mask & (1 << i))) {
        continue;  // bad person; statements unrestricted
      }
      for (int j = 0; j < n; ++j) {
        int s = statements[i][j];
        if (s == 2) {
          continue;
        }
        bool jGood = (mask & (1 << j)) != 0;
        if ((s == 1) != jGood) {
          consistent = false;
          break;
        }
      }
    }
    if (consistent) {
      best = std::max(best, __builtin_popcount(static_cast<unsigned>(mask)));
    }
  }
  return best;
}

}  // namespace

MaximumGoodPeopleBasedOnStatementsSolution::
    MaximumGoodPeopleBasedOnStatementsSolution() {
  setMetaInfo({.id = 2151,
               .title = "Maximum Good People Based on Statements",
               .url = "https://leetcode.com/problems/maximum-good-people-based-on-statements/"});

  registerStrategy(
      {.name = "bitmask-enumeration",
       .expected = "Accepted",
       .time_complexity = "O(2^n * n^2)",
       .space_complexity = "O(1)",
       .tags = {"Backtracking", "Bit Manipulation", "Enumeration"}},
      maximumGoodImpl);
}

int MaximumGoodPeopleBasedOnStatementsSolution::maximumGood(
    std::vector<std::vector<int>>& statements) {
  return getSolution()(statements);
}

}  // namespace problem_2151
}  // namespace leetcode

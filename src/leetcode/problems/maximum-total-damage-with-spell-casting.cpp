#include "leetcode/problems/maximum-total-damage-with-spell-casting.h"

#include <algorithm>
#include <map>
#include <vector>

namespace leetcode {
namespace problem_3186 {

static long long maximumTotalDamageImpl(std::vector<int>& power) {
  // Count total damage for each unique spell value
  std::map<int, long long> totalDamage;
  for (int p : power) {
    totalDamage[p] += p;
  }

  int m = static_cast<int>(totalDamage.size());
  std::vector<int> values;
  std::vector<long long> damages;
  values.reserve(m);
  damages.reserve(m);
  for (auto& [val, dmg] : totalDamage) {
    values.push_back(val);
    damages.push_back(dmg);
  }

  // dp[i] = max total damage considering first i unique values (0..i-1)
  std::vector<long long> dp(m + 1, 0);

  // Two-pointer: j is the first index where values[j] + 3 > values[i]
  // So all indices 0..j-1 are compatible (difference >= 3)
  int j = 0;
  for (int i = 0; i < m; ++i) {
    while (j < i && values[j] + 3 <= values[i]) {
      ++j;
    }
    long long take = damages[i] + dp[j];
    long long skip = dp[i];
    dp[i + 1] = std::max(take, skip);
  }

  return dp[m];
}

MaximumTotalDamageWithSpellCastingSolution::MaximumTotalDamageWithSpellCastingSolution() {
  setMetaInfo({.id = 3186,
               .title = "Maximum Total Damage With Spell Casting",
               .url = "https://leetcode.com/problems/maximum-total-damage-with-spell-casting/"});
  registerStrategy({.name = "sorting_and_dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Two Pointers", "Binary Search",
                             "Dynamic Programming", "Sorting", "Counting"}},
                   maximumTotalDamageImpl);
}

long long MaximumTotalDamageWithSpellCastingSolution::maximumTotalDamage(std::vector<int>& power) {
  return getSolution()(power);
}

}  // namespace problem_3186
}  // namespace leetcode

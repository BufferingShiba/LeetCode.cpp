#include "leetcode/problems/get-equal-substrings-within-budget.h"

#include <algorithm>
#include <cstdlib>

namespace leetcode {
namespace problem_1208 {

// Sliding window: maintain the max window [l, r] whose total change cost
// stays <= maxCost. O(n) time, O(1) space.
static int solution1(string s, string t, int maxCost) {
  const int n = static_cast<int>(s.size());
  int left = 0;
  int cost = 0;
  int best = 0;

  for (int right = 0; right < n; ++right) {
    cost += std::abs(s[right] - t[right]);
    while (cost > maxCost) {
      cost -= std::abs(s[left] - t[left]);
      ++left;
    }
    best = std::max(best, right - left + 1);
  }
  return best;
}

GetEqualSubstringsWithinBudgetSolution::GetEqualSubstringsWithinBudgetSolution() {
  setMetaInfo({
      .id = 1208,
      .title = "Get Equal Substrings Within Budget",
      .url = "https://leetcode.com/problems/get-equal-substrings-within-budget"
  });
  registerStrategy({.name = "Sliding Window",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Sliding Window", "Two Pointers"}},
                   solution1);
}

int GetEqualSubstringsWithinBudgetSolution::equalSubstring(string s, string t, int maxCost) {
  return getSolution()(s, t, maxCost);
}

}  // namespace problem_1208
}  // namespace leetcode

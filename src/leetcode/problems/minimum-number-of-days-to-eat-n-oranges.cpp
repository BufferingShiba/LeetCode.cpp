#include "leetcode/problems/minimum-number-of-days-to-eat-n-oranges.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_1553 {
namespace {

int minDaysImpl(int n, std::unordered_map<int, int>& memo) {
  if (n <= 1) return n;
  auto it = memo.find(n);
  if (it != memo.end()) return it->second;
  int res = std::min(1 + (n % 2) + minDaysImpl(n / 2, memo),
                     1 + (n % 3) + minDaysImpl(n / 3, memo));
  memo[n] = res;
  return res;
}

int minDaysMemo(int n) {
  std::unordered_map<int, int> memo;
  return minDaysImpl(n, memo);
}

}  // namespace

MinimumNumberOfDaysToEatNOrangesSolution::MinimumNumberOfDaysToEatNOrangesSolution() {
  setMetaInfo({.id = 1553,
               .title = "Minimum Number of Days to Eat N Oranges",
               .url = "https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/"});
  registerStrategy({.name = "MemoizedRecursion",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Memoization", "Dynamic Programming"}},
                   minDaysMemo);
}

int MinimumNumberOfDaysToEatNOrangesSolution::minDays(int n) {
  return getSolution()(n);
}

}  // namespace problem_1553
}  // namespace leetcode

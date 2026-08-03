#include "leetcode/problems/maximum-number-of-integers-to-choose-from-a-range-i.h"

#include <unordered_set>

namespace leetcode::problem_2554 {

namespace {

int maxCountImpl(std::vector<int>& banned, int n, int maxSum) {
  std::unordered_set<int> bannedSet(banned.begin(), banned.end());
  int count = 0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (bannedSet.count(i)) continue;
    if (sum + i > maxSum) break;
    sum += i;
    ++count;
  }
  return count;
}

}  // namespace

MaximumNumberOfIntegersToChooseFromARangeISolution::MaximumNumberOfIntegersToChooseFromARangeISolution() {
  setMetaInfo({.id = 2554,
               .title = "Maximum Number of Integers to Choose From a Range I",
               .url = "https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/"});
  registerStrategy({.name = "Greedy with HashSet",
                    .expected = "Accepted",
                    .time_complexity = "O(n + m)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Hash Table", "Greedy"}},
                   maxCountImpl);
  setDefaultStrategy();
}

int MaximumNumberOfIntegersToChooseFromARangeISolution::maxCount(std::vector<int>& banned, int n, int maxSum) {
  return getSolution()(banned, n, maxSum);
}

}  // namespace leetcode::problem_2554

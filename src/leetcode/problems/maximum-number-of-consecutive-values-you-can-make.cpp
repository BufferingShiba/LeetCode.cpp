#include "leetcode/problems/maximum-number-of-consecutive-values-you-can-make.h"

#include <algorithm>

namespace leetcode {
namespace problem_1798 {

namespace {

int greedyMaximumConsecutive(std::vector<int>& coins) {
  std::sort(coins.begin(), coins.end());
  long long cur = 0;  // 当前可连续构造 [0, cur]
  for (int c : coins) {
    if (c <= cur + 1) {
      cur += c;
    } else {
      break;
    }
  }
  return static_cast<int>(cur + 1);
}

}  // namespace

MaximumNumberOfConsecutiveValuesYouCanMakeSolution::
    MaximumNumberOfConsecutiveValuesYouCanMakeSolution() {
  setMetaInfo({.id = 1798,
               .title = "Maximum Number of Consecutive Values You Can Make",
               .url = "https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/"});

  registerStrategy(
      {.name = "greedy-sort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy", "Sorting"},
       .notes =
           "Sort coins; maintain cur = max consecutive reachable [0, cur]. "
           "If next coin c <= cur+1, extend cur += c; otherwise break."},
      Func(greedyMaximumConsecutive));

  setDefaultStrategy();
}

}  // namespace problem_1798
}  // namespace leetcode

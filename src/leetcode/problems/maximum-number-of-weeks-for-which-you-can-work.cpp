#include "leetcode/problems/maximum-number-of-weeks-for-which-you-can-work.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_1953 {

static long long numberOfWeeksImpl(std::vector<int>& milestones) {
  long long total = 0;
  int maxVal = 0;
  for (int m : milestones) {
    total += m;
    if (m > maxVal) maxVal = m;
  }
  long long rest = total - maxVal;
  // If the largest project has more milestones than all others combined,
  // we can only interleave: use all of "rest" as separators, plus (rest+1)
  // of the largest project's milestones.
  if (maxVal > rest) {
    return 2 * rest + 1;
  }
  return total;
}

MaximumNumberOfWeeksForWhichYouCanWorkSolution::MaximumNumberOfWeeksForWhichYouCanWorkSolution() {
  setMetaInfo({.id = 1953,
               .title = "Maximum Number of Weeks for Which You Can Work",
               .url = "https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/"});
  registerStrategy({.name = "greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy"}},
                   numberOfWeeksImpl);
}

long long MaximumNumberOfWeeksForWhichYouCanWorkSolution::numberOfWeeks(std::vector<int>& milestones) {
  return getSolution()(milestones);
}

}  // namespace leetcode::problem_1953

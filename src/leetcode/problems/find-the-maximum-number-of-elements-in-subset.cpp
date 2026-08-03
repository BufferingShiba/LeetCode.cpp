#include "leetcode/problems/find-the-maximum-number-of-elements-in-subset.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_3020 {

static int solution1(vector<int>& nums) {
  std::unordered_map<long long, int> freq;
  for (int x : nums) freq[x]++;

  long long answer = 1;  // a single-element subset is always valid

  // Special case x = 1: all elements are 1, the pattern needs 2m+1 copies of 1.
  auto it1 = freq.find(1);
  if (it1 != freq.end()) {
    long long c = it1->second;
    long long best = (c % 2 == 1) ? c : c - 1;
    answer = std::max(answer, best);
  }

  for (const auto& [v, vcnt] : freq) {
    if (v <= 1) continue;  // handled above
    if (vcnt < 2) continue;  // cannot even be a side element

    long long cur = v;
    long long sideCount = 0;
    long long bestLocal = 0;
    while (cur <= 1000000000LL) {
      long long nxt = cur * cur;
      auto it = freq.find(nxt);
      if (it != freq.end() && it->second >= 1) {
        ++sideCount;
        bestLocal = std::max(bestLocal, sideCount * 2 + 1);
        if (it->second < 2) break;  // cannot extend further
        cur = nxt;
      } else {
        break;
      }
    }
    answer = std::max(answer, bestLocal);
  }

  return static_cast<int>(answer);
}

FindTheMaximumNumberOfElementsInSubsetSolution::FindTheMaximumNumberOfElementsInSubsetSolution() {
  setMetaInfo({
      .id = 3020,
      .title = "Find the Maximum Number of Elements in Subset",
      .url = "https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset"
  });
  registerStrategy({.name = "Hash Map + Power Chain",
                    .expected = "Accepted",
                    .time_complexity = "O(n + log(max))",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Map"}},
                   solution1);
}

int FindTheMaximumNumberOfElementsInSubsetSolution::maximumLength(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3020
}  // namespace leetcode

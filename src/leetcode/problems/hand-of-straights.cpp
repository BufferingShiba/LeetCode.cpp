#include "leetcode/problems/hand-of-straights.h"

#include <map>

namespace leetcode::problem_846 {

static bool isNStraightHandImpl(std::vector<int>& hand, int groupSize) {
  const int n = static_cast<int>(hand.size());
  if (n % groupSize != 0) {
    return false;
  }

  std::map<int, int> cnt;
  for (int card : hand) {
    ++cnt[card];
  }

  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    int start = it->first;
    int need = it->second;
    if (need == 0) {
      continue;
    }
    // Try to form groups starting from 'start', consuming 'need' groups.
    for (int i = 1; i < groupSize; ++i) {
      int card = start + i;
      auto f = cnt.find(card);
      if (f == cnt.end() || f->second < need) {
        return false;
      }
      f->second -= need;
    }
  }

  return true;
}

HandOfStraightsSolution::HandOfStraightsSolution() {
  setMetaInfo({.id = 846,
               .title = "Hand of Straights",
               .url = "https://leetcode.com/problems/hand-of-straights/"});
  registerStrategy(
      {.name = "Greedy with Ordered Map",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy", "Sorting"}},
      isNStraightHandImpl);
}

bool HandOfStraightsSolution::isNStraightHand(std::vector<int>& hand,
                                                int groupSize) {
  return getSolution()(hand, groupSize);
}

}  // namespace leetcode::problem_846

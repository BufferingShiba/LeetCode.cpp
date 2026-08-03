#include "leetcode/problems/sum-of-imbalance-numbers-of-all-subarrays.h"

#include <set>

namespace leetcode {
namespace problem_2763 {

// For a fixed left endpoint l, sweep right endpoint r while maintaining the
// deduplicated value set `seen` and the running imbalance number `imb`.
//
// Inserting a new value v into the ordered `seen` set splits the adjacent pair
// (predecessor p, successor s) into (p, v) and (v, s). Only this section of
// the sorted sequence changes, so the imbalance delta only depends on p and s.
static int sumImbalanceNumbersImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int total = 0;
  for (int l = 0; l < n; ++l) {
    std::set<int> seen;
    int imb = 0;
    for (int r = l; r < n; ++r) {
      const int v = nums[r];
      auto ins = seen.insert(v);
      if (ins.second) {
        auto itp = ins.first;
        auto its = std::next(itp);
        if (itp == seen.begin()) {
          if (its != seen.end()) {
            imb += ((*its - v > 1) ? 1 : 0);
          }
        } else if (its == seen.end()) {
          auto prevIt = std::prev(itp);
          imb += ((v - *prevIt > 1) ? 1 : 0);
        } else {
          auto prevIt = std::prev(itp);
          const int p = *prevIt;
          const int s = *its;
          imb += ((v - p > 1) ? 1 : 0) + ((s - v > 1) ? 1 : 0) - ((s - p > 1) ? 1 : 0);
        }
      }
      total += imb;
    }
  }
  return total;
}

SumOfImbalanceNumbersOfAllSubarraysSolution::SumOfImbalanceNumbersOfAllSubarraysSolution() {
  setMetaInfo({.id = 2763,
               .title = "Sum of Imbalance Numbers of All Subarrays",
               .url = "https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/"});
  registerStrategy(
      {.name = "sliding-window-with-ordered-set",
       .expected = "Accepted",
       .time_complexity = "O(n^2 log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Enumeration"}},
      sumImbalanceNumbersImpl);
}

int SumOfImbalanceNumbersOfAllSubarraysSolution::sumImbalanceNumbers(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2763
}  // namespace leetcode

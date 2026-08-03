#include "leetcode/problems/the-number-of-beautiful-subsets.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_2597 {

namespace {

int beautifulSubsetsImpl(std::vector<int>& nums, int k) {
  // Group the elements by value % k. Within each group, values are sorted and
  // any two values differing by k are mutually exclusive.
  std::unordered_map<int, std::vector<int>> groups;
  std::unordered_map<int, int> count;
  for (int x : nums) {
    groups[x % k].push_back(x);
    count[x]++;
  }

  long long result = 1;  // multiply across groups
  for (auto& entry : groups) {
    std::vector<int>& vals = entry.second;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());

    // dp_not: number of ways picking subsets up to current distinct value where
    // the current value is NOT selected (all of its count[v] occurrences are
    // skipped -> exactly 1 way).
    // dp_sel: number of ways where the current value IS selected, i.e. a non-
    // empty subset of its count[v] identical occurrences is chosen.
    long long dp_not = 1;
    long long dp_sel = 0;
    int prevVal = -1000000;
    for (int v : vals) {
      long long ways_choose_any = (1LL << count[v]) - 1;  // non-empty choices
      long long new_not = (dp_not + dp_sel) * 1;          // skip all occurrences
      long long new_sel;
      if (prevVal >= 0 && v - prevVal == k) {
        // Conflicting with previous distinct value, so previous must be
        // skipped -> only continue from dp_not state.
        new_sel = dp_not * ways_choose_any;
      } else {
        new_sel = (dp_not + dp_sel) * ways_choose_any;
      }
      dp_not = new_not;
      dp_sel = new_sel;
      prevVal = v;
    }
    result *= (dp_not + dp_sel);
  }

  // Subtract 1 to exclude the empty subset.
  return static_cast<int>(result - 1);
}

}  // namespace

TheNumberOfBeautifulSubsetsSolution::TheNumberOfBeautifulSubsetsSolution() {
  setMetaInfo({.id = 2597,
               .title = "The Number of Beautiful Subsets",
               .url = "https://leetcode.com/problems/the-number-of-beautiful-subsets/"});
  registerStrategy({.name = "grouping-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "Dynamic Programming", "Sorting"}},
                   beautifulSubsetsImpl);
}

int TheNumberOfBeautifulSubsetsSolution::beautifulSubsets(
    std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2597
}  // namespace leetcode

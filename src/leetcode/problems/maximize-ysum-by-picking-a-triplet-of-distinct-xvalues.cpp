#include "leetcode/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues.h"

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_3572 {
namespace {

// For each distinct x value we only ever pick it at most once, so the optimal
// value contributed by that x is simply its maximum y. The problem then reduces
// to choosing the three largest per-x maxima.
int maxSumDistinctTripletImpl(std::vector<int>& x, std::vector<int>& y) {
  std::unordered_map<int, int> best;
  best.reserve(x.size());
  const int n = static_cast<int>(x.size());
  for (int i = 0; i < n; ++i) {
    auto it = best.find(x[i]);
    if (it == best.end()) {
      best.emplace(x[i], y[i]);
    } else if (y[i] > it->second) {
      it->second = y[i];
    }
  }
  if (best.size() < 3) {
    return -1;
  }
  std::vector<int> vals;
  vals.reserve(best.size());
  for (const auto& kv : best) {
    vals.push_back(kv.second);
  }
  std::sort(vals.begin(), vals.end(), std::greater<int>());
  return vals[0] + vals[1] + vals[2];
}

}  // namespace

MaximizeYsumByPickingATripletOfDistinctXvaluesSolution::
    MaximizeYsumByPickingATripletOfDistinctXvaluesSolution() {
  setMetaInfo({.id = 3572,
               .title = "Maximize Y-Sum by Picking a Triplet of Distinct X-Values",
               .url = "https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/"});
  registerStrategy({.name = "GreedyPerXMax",
                    .expected = "Accepted",
                    .time_complexity = "O(n log m)",
                    .space_complexity = "O(m)",
                    .tags = {"Array", "Hash Table", "Greedy", "Sorting"}},
                   maxSumDistinctTripletImpl);
}

int MaximizeYsumByPickingATripletOfDistinctXvaluesSolution::
    maxSumDistinctTriplet(std::vector<int>& x, std::vector<int>& y) {
  return getSolution()(x, y);
}

}  // namespace problem_3572
}  // namespace leetcode

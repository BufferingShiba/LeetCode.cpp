#include <algorithm>
#include <cstdint>
#include <limits>
#include <utility>
#include <vector>

#include "leetcode/problems/minimum-operations-to-make-array-parity-alternating.h"

namespace leetcode {
namespace problem_3854 {
namespace {

// For a chosen parity-alternating pattern (the required parity at each index),
// compute the minimum total operations and the minimum value of
// (max - min) over all reachable alternating arrays using exactly the minimum
// operation count.
//
// Pattern A: at index i, required parity == (i % 2).
// Pattern B: at index i, required parity == (1 - i % 2).
//
// If index needs a flip, it costs exactly 1 operation and the value can become
// nums[i]-1 or nums[i]+1 (both flip parity).  If it must stay, it costs 0 and
// the value is fixed to nums[i].  Since the total ops is the sum of per-index
// minima, being "exactly minimum" forces each index to use its minimum step, so
// the candidate values are exactly these 1 or 2 choices per index.
//
// Minimising (max - min) over one choice per index is solved with a sliding
// window over all (value, index) candidates sorted by value.
std::pair<long long, long long> SolveMode(const std::vector<int>& nums,
                                          int pattern) {
  const int n = static_cast<int>(nums.size());
  struct Cand {
    long long value;
    int pos;
  };

  std::vector<Cand> cands;
  cands.reserve(static_cast<size_t>(n) * 2);
  long long ops = 0;
  for (int i = 0; i < n; ++i) {
    const long long v = nums[i];
    int parity = v % 2;
    if (parity < 0) parity += 2;  // normalise to {0,1}
    const int required = (pattern == 0) ? (i % 2) : (1 - i % 2);
    if (parity == required) {
      cands.push_back({v, i});
    } else {
      ++ops;
      cands.push_back({v - 1, i});
      cands.push_back({v + 1, i});
    }
  }

  std::sort(cands.begin(), cands.end(),
            [](const Cand& a, const Cand& b) { return a.value < b.value; });

  std::vector<int> count(n, 0);
  int covered = 0;
  int l = 0;
  long long bestRange = std::numeric_limits<long long>::max();
  for (int r = 0; r < static_cast<int>(cands.size()); ++r) {
    if (count[cands[r].pos]++ == 0) ++covered;
    while (covered == n) {
      bestRange = std::min(bestRange, cands[r].value - cands[l].value);
      if (--count[cands[l].pos] == 0) --covered;
      ++l;
    }
  }

  return {ops, bestRange};
}

std::vector<int> makeParityAlternatingImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n == 1) {
    return {0, 0};
  }

  auto m0 = SolveMode(nums, 0);
  auto m1 = SolveMode(nums, 1);

  // Prefer fewer operations; tie-break by smaller (max - min).
  auto best = m0;
  if (m1.first < best.first ||
      (m1.first == best.first && m1.second < best.second)) {
    best = m1;
  }

  return {static_cast<int>(best.first), static_cast<int>(best.second)};
}

}  // namespace

MinimumOperationsToMakeArrayParityAlternatingSolution::
    MinimumOperationsToMakeArrayParityAlternatingSolution() {
  setMetaInfo({.id = 3854,
               .title = "Minimum Operations to Make Array Parity Alternating",
               .url = "https://leetcode.com/problems/"
                      "minimum-operations-to-make-array-parity-alternating/"});
  registerStrategy(
      {.name = "greedy+sliding_window",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Greedy"}},
      makeParityAlternatingImpl);
}

std::vector<int> MinimumOperationsToMakeArrayParityAlternatingSolution::
    makeParityAlternating(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3854
}  // namespace leetcode

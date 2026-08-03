#include "leetcode/problems/maximize-subarrays-after-removing-one-conflicting-pair.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3480 {

namespace {

long long maxSubarraysImpl(int n, std::vector<std::vector<int>>& conflictingPairs) {
  int m = static_cast<int>(conflictingPairs.size());

  // Group pairs by their left endpoint a (the smaller value in the pair)
  // For each a (1..n), store list of (b, index)
  std::vector<std::vector<std::pair<int, int>>> byA(n + 1);
  for (int i = 0; i < m; ++i) {
    int x = conflictingPairs[i][0];
    int y = conflictingPairs[i][1];
    int a = std::min(x, y);
    int b = std::max(x, y);
    byA[a].emplace_back(b, i);
  }

  // Gains for each pair when it is the unique minimum
  std::vector<long long> pairGain(m, 0);

  // Track the two smallest b values among active pairs (those with a >= current L)
  int min1_b = n + 1;       // smallest b
  int min1_count = 0;       // how many pairs have min1_b
  int min1_idx = -1;        // index of one pair achieving min1_b (meaningful only if count==1)
  int min2_b = n + 1;       // second smallest b (strictly greater than min1_b)

  long long totalValid = 0;

  // Sweep L from n down to 1
  for (int L = n; L >= 1; --L) {
    // Add all pairs whose a == L to the active set
    for (auto& p : byA[L]) {
      int b = p.first;
      int idx = p.second;

      if (b < min1_b) {
        // New smallest b; old min1 becomes min2
        min2_b = min1_b;
        min1_b = b;
        min1_count = 1;
        min1_idx = idx;
      } else if (b == min1_b) {
        ++min1_count;
        // min1_idx becomes ambiguous; we won't use it while count > 1
      } else if (b < min2_b) {
        min2_b = b;
      }
    }

    // Valid subarrays starting at L with all pairs present
    long long validL = std::max(0, min1_b - L);
    totalValid += validL;

    // If the minimum is unique, removing it would raise g(L) to min2_b
    if (min1_count == 1) {
      long long gain = std::max(0, min2_b - L) - std::max(0, min1_b - L);
      pairGain[min1_idx] += gain;
    }
  }

  // Find maximum gain among all pairs
  long long maxGain = 0;
  for (long long g : pairGain) {
    if (g > maxGain) maxGain = g;
  }

  return totalValid + maxGain;
}

}  // namespace

MaximizeSubarraysAfterRemovingOneConflictingPairSolution::
    MaximizeSubarraysAfterRemovingOneConflictingPairSolution() {
  setMetaInfo({.id = 3480,
               .title = "Maximize Subarrays After Removing One Conflicting Pair",
               .url = "https://leetcode.com/problems/maximize-subarrays-after-removing-one-conflicting-pair/"});

  registerStrategy(
      {.name = "SweepLine",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n + m)",
       .tags = {"Array", "Enumeration", "Prefix Sum"}},
      maxSubarraysImpl);
}

long long
MaximizeSubarraysAfterRemovingOneConflictingPairSolution::maxSubarrays(
    int n, std::vector<std::vector<int>>& conflictingPairs) {
  return getSolution()(n, conflictingPairs);
}

}  // namespace problem_3480
}  // namespace leetcode

#include "leetcode/problems/smallest-pair-with-different-frequencies.h"

#include <array>
#include <limits>
#include <vector>

namespace leetcode::problem_3852 {

namespace {

std::vector<int> minDistinctFreqPairImpl(std::vector<int>& nums) {
  std::array<int, 101> freq{};
  for (int v : nums) {
    ++freq[v];
  }

  std::array<int, 101> count{};  // count[f]: frequency -> whether some value has it
  for (int v = 1; v <= 100; ++v) {
    count[freq[v]] = 1;
  }

  for (int x = 1; x <= 100; ++x) {
    if (freq[x] == 0) continue;
    for (int y = x + 1; y <= 100; ++y) {
      if (freq[y] == 0) continue;
      if (freq[x] != freq[y]) {
        return {x, y};
      }
    }
  }

  return {-1, -1};
}

}  // namespace

SmallestPairWithDifferentFrequenciesSolution::
    SmallestPairWithDifferentFrequenciesSolution() {
  setMetaInfo({.id = 3852,
               .title = "Smallest Pair With Different Frequencies",
               .url = "https://leetcode.com/problems/smallest-pair-with-different-frequencies/"});
  registerStrategy(
      {.name = "Counting + Brute Force",
       .expected = "Accepted",
       .time_complexity = "O(n + V^2)",
       .space_complexity = "O(V)",
       .tags = {"Array", "Hash Table", "Counting"}},
      minDistinctFreqPairImpl);
}

std::vector<int> SmallestPairWithDifferentFrequenciesSolution::
    minDistinctFreqPair(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3852

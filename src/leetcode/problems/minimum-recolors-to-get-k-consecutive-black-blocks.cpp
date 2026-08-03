#include "leetcode/problems/minimum-recolors-to-get-k-consecutive-black-blocks.h"

#include <algorithm>
#include <string>

namespace leetcode::problem_2379 {

namespace {

// Sliding window: the answer is the minimum number of 'W' in any window of
// length k.
int minimumRecolorsImpl(const std::string& blocks, int k) {
  int whites = 0;
  for (int i = 0; i < k; ++i) {
    if (blocks[i] == 'W') {
      ++whites;
    }
  }
  int best = whites;
  for (int i = k; i < static_cast<int>(blocks.size()); ++i) {
    if (blocks[i - k] == 'W') {
      --whites;
    }
    if (blocks[i] == 'W') {
      ++whites;
    }
    best = std::min(best, whites);
  }
  return best;
}

}  // namespace

MinimumRecolorsToGetKConsecutiveBlackBlocksSolution::
    MinimumRecolorsToGetKConsecutiveBlackBlocksSolution() {
  setMetaInfo({.id = 2379,
               .title = "Minimum Recolors to Get K Consecutive Black Blocks",
               .url = "https://leetcode.com/problems/"
                      "minimum-recolors-to-get-k-consecutive-black-blocks/"});
  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Sliding Window"}},
      static_cast<int (*)(const std::string&, int)>(minimumRecolorsImpl));
}

int MinimumRecolorsToGetKConsecutiveBlackBlocksSolution::minimumRecolors(
    std::string blocks, int k) {
  return getSolution()(std::move(blocks), k);
}

}  // namespace leetcode::problem_2379

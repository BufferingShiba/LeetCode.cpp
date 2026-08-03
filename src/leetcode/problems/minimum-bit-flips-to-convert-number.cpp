#include "leetcode/problems/minimum-bit-flips-to-convert-number.h"

namespace leetcode {
namespace problem_2220 {
namespace {

int minBitFlipsImpl(int start, int goal) {
  return __builtin_popcount(static_cast<unsigned>(start) ^
                            static_cast<unsigned>(goal));
}

}  // namespace

MinimumBitFlipsToConvertNumberSolution::MinimumBitFlipsToConvertNumberSolution() {
  setMetaInfo({.id = 2220,
               .title = "Minimum Bit Flips to Convert Number",
               .url = "https://leetcode.com/problems/minimum-bit-flips-to-convert-number/"});
  registerStrategy(
      {.name = "XorPopcount",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation", "Hamming Distance"}},
      minBitFlipsImpl);
}

int MinimumBitFlipsToConvertNumberSolution::minBitFlips(int start, int goal) {
  return getSolution()(start, goal);
}

}  // namespace problem_2220
}  // namespace leetcode

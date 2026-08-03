#include "leetcode/problems/reverse-bits.h"

#include <cstdint>

namespace leetcode::problem_190 {

namespace {

int reverseBitsImpl(int n) {
  uint32_t x = static_cast<uint32_t>(n);
  uint32_t result = 0;
  for (int i = 0; i < 32; ++i) {
    result = (result << 1) | (x & 1U);
    x >>= 1;
  }
  return static_cast<int>(result);
}

}  // namespace

ReverseBits::ReverseBits() {
  setMetaInfo({.id = 190,
               .title = "Reverse Bits",
               .url = "https://leetcode.com/problems/reverse-bits/"});

  registerStrategy(
      {.name = "bit-by-bit",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      reverseBitsImpl);
}

int ReverseBits::reverseBits(int n) { return getSolution()(n); }

}  // namespace leetcode::problem_190

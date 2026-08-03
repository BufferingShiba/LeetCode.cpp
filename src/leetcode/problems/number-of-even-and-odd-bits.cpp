#include "leetcode/problems/number-of-even-and-odd-bits.h"

namespace leetcode {
namespace problem_2595 {

static std::vector<int> evenOddBitImpl(int n) {
  int even = 0, odd = 0;
  int idx = 0;
  while (n > 0) {
    if (n & 1) {
      if (idx % 2 == 0) {
        ++even;
      } else {
        ++odd;
      }
    }
    n >>= 1;
    ++idx;
  }
  return {even, odd};
}

NumberOfEvenAndOddBitsSolution::NumberOfEvenAndOddBitsSolution() {
  setMetaInfo({.id = 2595,
               .title = "Number of Even and Odd Bits",
               .url = "https://leetcode.com/problems/number-of-even-and-odd-bits/"});

  registerStrategy(
      {.name = "BitTraversal",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      evenOddBitImpl);
}

}  // namespace problem_2595
}  // namespace leetcode

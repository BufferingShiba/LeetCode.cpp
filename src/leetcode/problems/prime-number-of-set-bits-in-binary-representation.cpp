#include "leetcode/problems/prime-number-of-set-bits-in-binary-representation.h"

namespace leetcode {
namespace problem_762 {

namespace {

// Primes up to 20: 2, 3, 5, 7, 11, 13, 17, 19
// Bitmask: bit i is 1 if i is prime
constexpr int kPrimeMask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) |
                           (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);

int countPrimeSetBitsImpl(int left, int right) {
  int count = 0;
  for (int n = left; n <= right; ++n) {
    int bits = __builtin_popcount(n);
    if ((kPrimeMask >> bits) & 1) {
      ++count;
    }
  }
  return count;
}

}  // namespace

PrimeNumberOfSetBitsInBinaryRepresentationSolution::
    PrimeNumberOfSetBitsInBinaryRepresentationSolution() {
  setMetaInfo({.id = 762,
               .title = "Prime Number of Set Bits in Binary Representation",
               .url = "https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/"});
  registerStrategy(
      {.name = "popcount-bitmask",
       .expected = "Accepted",
       .time_complexity = "O(right - left)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"}},
      countPrimeSetBitsImpl);
}

int PrimeNumberOfSetBitsInBinaryRepresentationSolution::countPrimeSetBits(
    int left, int right) {
  return getSolution()(left, right);
}

}  // namespace problem_762
}  // namespace leetcode

#include "leetcode/problems/minimum-number-of-flips-to-reverse-binary-string.h"

namespace leetcode {
namespace problem_3750 {
namespace {

// Let s be the binary representation of n (no leading zeros). We need to make
// s equal to reverse(s). A position i differs if s[i] != reverse(s)[i].
// But reverse(s)[i] == s[len-1-i], so a symmetric pair (i, len-1-i) with
// s[i] != s[len-1-i] has BOTH positions mismatching -> two flips.
// A symmetric pair that matches needs no flips. Hence the total answer is
// twice the number of mismatching symmetric pairs.
int minimumFlipsImpl(int n) {
  int len = 0;
  int temp = n;
  while (temp > 0) {
    ++len;
    temp >>= 1;
  }

  int mismatched_pairs = 0;
  for (int i = 0; i < len / 2; ++i) {
    const int left = (n >> i) & 1;              // low-order side
    const int right = (n >> (len - 1 - i)) & 1;  // symmetric high-order side
    if (left != right) {
      ++mismatched_pairs;
    }
  }
  return 2 * mismatched_pairs;
}

}  // namespace

MinimumNumberOfFlipsToReverseBinaryStringSolution::
    MinimumNumberOfFlipsToReverseBinaryStringSolution() {
  setMetaInfo({.id = 3750,
               .title = "Minimum Number of Flips to Reverse Binary String",
               .url = "https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/"});

  registerStrategy(
      {.name = "BitSymmetricCompare",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"}},
      minimumFlipsImpl);
}

int MinimumNumberOfFlipsToReverseBinaryStringSolution::minimumFlips(int n) {
  return getSolution()(n);
}

}  // namespace problem_3750
}  // namespace leetcode

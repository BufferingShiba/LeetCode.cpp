#include "leetcode/problems/complement-of-base-10-integer.h"

namespace leetcode {
namespace problem_1009 {

// Flip all significant bits of n using a mask of all ones over n's bit length.
static int bitwiseComplementImpl(int n) {
  if (n == 0) {
    return 1;
  }
  int mask = 0;
  int x = n;
  while (x > 0) {
    mask = (mask << 1) | 1;
    x >>= 1;
  }
  return (~n) & mask;
}

ComplementOfBase10IntegerSolution::ComplementOfBase10IntegerSolution() {
  setMetaInfo({.id = 1009,
               .title = "Complement of Base 10 Integer",
               .url = "https://leetcode.com/problems/complement-of-base-10-integer/"});
  registerStrategy(
      {.name = "bitwise-mask",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      bitwiseComplementImpl);
}

int ComplementOfBase10IntegerSolution::bitwiseComplement(int n) {
  return getSolution()(n);
}

}  // namespace problem_1009
}  // namespace leetcode

#include "leetcode/problems/power-of-four.h"

namespace leetcode {
namespace problem_342 {

namespace {

bool isPowerOfFourImpl(int n) {
  // n > 0, n is a power of two, and its single 1-bit sits in an even position.
  return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}

}  // namespace

PowerOfFourSolution::PowerOfFourSolution() {
  setMetaInfo({.id = 342,
               .title = "Power of Four",
               .url = "https://leetcode.com/problems/power-of-four/"});
  registerStrategy({.name = "BitManipulation",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Bit Manipulation", "Recursion"}},
                   isPowerOfFourImpl);
}

bool PowerOfFourSolution::isPowerOfFour(int n) {
  return getSolution()(n);
}

}  // namespace problem_342
}  // namespace leetcode

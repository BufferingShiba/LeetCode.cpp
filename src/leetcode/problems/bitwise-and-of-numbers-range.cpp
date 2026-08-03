#include "leetcode/problems/bitwise-and-of-numbers-range.h"

namespace leetcode {
namespace problem_201 {

static int rangeBitwiseAndImpl(int left, int right) {
  while (left < right) {
    right &= (right - 1);
  }
  return right;
}

BitwiseAndOfNumbersRangeSolution::BitwiseAndOfNumbersRangeSolution() {
  setMetaInfo({.id = 201,
               .title = "Bitwise AND of Numbers Range",
               .url = "https://leetcode.com/problems/bitwise-and-of-numbers-range/"});
  registerStrategy(
      {.name = "Brian Kernighan",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Bit Manipulation"}},
      rangeBitwiseAndImpl);
  setDefaultStrategy();
}

int BitwiseAndOfNumbersRangeSolution::rangeBitwiseAnd(int left, int right) {
  return getSolution()(left, right);
}

}  // namespace problem_201
}  // namespace leetcode

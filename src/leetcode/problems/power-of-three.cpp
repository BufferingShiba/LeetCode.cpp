#include "leetcode/problems/power-of-three.h"

namespace leetcode {
namespace problem_326 {

namespace {

bool isPowerOfThreeImpl(int n) {
  // 3^19 = 1162261467 is the largest power of three within int range.
  return n > 0 && 1162261467 % n == 0;
}

}  // namespace

PowerOfThreeSolution::PowerOfThreeSolution() {
  setMetaInfo({.id = 326,
               .title = "Power of Three",
               .url = "https://leetcode.com/problems/power-of-three/"});

  registerStrategy({.name = "ModuloLargestPower",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Recursion"}},
                   ::leetcode::problem_326::isPowerOfThreeImpl);
}

bool PowerOfThreeSolution::isPowerOfThree(int n) {
  return getSolution()(n);
}

}  // namespace problem_326
}  // namespace leetcode
